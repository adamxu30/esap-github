// initialize constants
#define one_ms ((1<<12) * 50 / 1000)
#define PWMCHANNEL 4
void setup() {
  // put your setup code here, to run once:
  ledcAttach(4, 50, 12);  // initialize servo
  Serial.begin(115200); // initialize serial monitor
}

void spin_to(int angle, int time){
  int target = ((angle/180) + 1) * one_ms;  // convert target angle to servo units
  int currentpos = ledcRead(PWMCHANNEL);  // get current position

  int interval = time / 20; // calculate interval for 50Hz

  for(int i = 0; i < interval; i++){
    ledcWrite(PWMCHANNEL, currentpos + target * i / interval);  // move servo to desired angle
    delay(20 / time);
  }
}

void loop() {
  spin_to(0, 1000);
  delay(1000);
  spin_to(180, 1000);
  delay(1000);
}
