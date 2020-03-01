
//Based on "Wire_Slave Example Code

#include <Wire.h>
#include <TimeLib.h>
int pinList[4][3] = {{2,3,4},  {5,6,7},  {8,9,10},  {11,12,13} }; //list of pins in use, in groups of 3 (RGB)
int h;
int m;

int x =1;
void setup() {
  Wire.begin();
                  // join i2c bus with address #8
  setTime(22, 58, 40, 1, 1, 2001);

  Serial.begin(9600);           // start serial for output

  for (int thisPin = 2; thisPin < 13; thisPin++) {
  pinMode(thisPin, OUTPUT);
  digitalWrite(thisPin, LOW);

    }
}

void loop() {
  h = hour();
  m = minute();
  if ((h <= 6 and m < 30) or (h >= 22 and m > 30) or h > 23 or h <6) {
     for (int thisPin = 2; thisPin < 13; thisPin++) {
  
       digitalWrite(thisPin, HIGH);
  }}

  else {
  
    Wire.beginTransmission(1);
    Wire.write(x);
    Wire.endTransmission();
    Serial.println(x);
    int y = x-1;
    if (y == 0) {
      y = 4;
    
    }
    y--;
    x--;
    digitalWrite(pinList[y][0], HIGH);
    digitalWrite(pinList[y][1], HIGH);
    digitalWrite(pinList[y][2], HIGH);
    delay(1);
    digitalWrite(pinList[x][0], LOW); //Write certain pins to be HIGH
    digitalWrite(pinList[x][1], LOW);
    digitalWrite(pinList[x][2], LOW);
    delay(3.5);
    x=x+2;
    if (x==5) {
      x = 1;
    }
  }
}
