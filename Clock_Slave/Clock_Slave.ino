
//Based on "Wire_Slave Example Code

#include <Wire.h>

int pinList[4][3] = {{2,3,4},  {5,6,7},  {8,9,10},  {11,12,13} }; //list of pins in use, in groups of 3 (RGB)



void setup() {
  Wire.begin(1);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

  for (int thisPin = 2; thisPin < 13; thisPin++) {
  pinMode(thisPin, OUTPUT);
  digitalWrite(thisPin, LOW);

    }
}

void loop() {

}


void receiveEvent(int howMany) {
  int x = Wire.read();
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
  delay(1.5);
  digitalWrite(pinList[x][0], LOW); //Write certain pins to be HIGH
  digitalWrite(pinList[x][1], LOW);
  digitalWrite(pinList[x][2], LOW);

  
}
