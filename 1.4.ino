#define PWMCHANNEL 4
#define ONEmS_COUNTS ((1 << 12) * 50 / 1000)  // 2^12 bit resolution * freq / 1000 (ms/s)
int reading, newPos, currMap, num;

void setup() {
 ledcAttach(10, 50, 12);	
 Serial.begin(115200);
 pinMode(4, INPUT);
}

void loop() {
 Serial.println(mapToPos(analogRead(4))); // print out the value
 int g = ((mapToPos(analogRead(4))) / 90 + 0.5) * ONEmS_COUNTS;  // convert to duty cycle
 ledcWrite(10, g); // write to the servo
 delay(50);
}

int mapToPos(int pos){ // map the position, max 4096 min around 16
 int num = map(pos, 16, 4096, 0, 180); // map
 return num; //return it
}
