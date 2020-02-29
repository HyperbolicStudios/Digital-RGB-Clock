//#include <Time.h>
#include <TimeLib.h>
#include <Wire.h>

int timeDelay = 4;
int x;
int value;
int a;
String b;
// Digit Mapping Sets

int mappingSets[10][13] = {

 {1, 1, 1,
  1,    1,
  1, 0, 1,
  1,    1,
  1, 1, 1},

 {0, 0, 1,
  0,    1,
  0, 0, 1,
  0,    1,
  0, 0, 1},

 {1, 1, 1,
  0,    1,
  1, 1, 1,
  1,    0,
  1, 1, 1},
                    
 {1, 1, 1,
  0,    1,
  1, 1, 1,
  0,    1,
  1, 1, 1},

 {1, 0, 1,
  1,    1,
  1, 1, 1,
  0,    1,
  0, 0, 1},

 {1, 1, 1,
  1,    0,
  1, 1, 1,
  0,    1,
  1, 1, 1},

 {1, 1, 1,
  1,    0,
  1, 1, 1,
  1,    1,
  1, 1, 1},
                      
 {1, 1, 1,
  0,    1,
  0, 0, 1,
  0,    1,
  0, 0, 1},

 {1, 1, 1,
  1,    1,
  1, 1, 1,
  1,    1,
  1, 1, 1},
                      
 {1, 1, 1,
  1,    1,
  1, 1, 1,
  0,    1,
  0, 0, 1}

 };



                      
void setup() {
  // put your setup code here, to run once:

  Wire.begin();
  //Serial.begin(9600);
  setTime(23, 51, 40, 1, 1, 2001);

  for (int thisPin = 1; thisPin < 14; thisPin++) { //Set pins to be output
  pinMode(thisPin, OUTPUT);
  }
  pinMode(A1, OUTPUT);
 
  Wire.beginTransmission(1); // transmit to device #1
  Wire.write(1);        // send one byte - int 1, as a ping to device
  Wire.endTransmission();    // stop transmitting

}

void loop() {
  // put your main code here, to run repeatedly:
  time_t t = now();   //Get current time
  /*Serial.print(hour());
  Serial.print(" ");
  Serial.print(minute());
  Serial.print(" ");
  Serial.println(second()); */  
  switchDigit(1);
  //Write the Hour
  value = hour();   //Put Hour into a variable
  if((value >= 22 and minute() > 30) or value > 22 or value < 5 or (value <= 5 and minute() < 45)) {
      Serial.println(value);
      for (int thisPin = 1; thisPin < 14; thisPin++) { //Set pins to be output
        digitalWrite(thisPin, LOW);
  }}
  else {
      
  
    
    if (value > 9) {
      b = (String(value))[0];
      writeDigit(b.toInt()); //Write the first digit
      delay(timeDelay);
      
      switchDigit(2);
      
      b = (String(value))[1];
      writeDigit(b.toInt()); //Write the first digit
      delay(timeDelay);
    }
  
    else {
      writeDigit(0); //first digit will be a zero
      delay(timeDelay);
      switchDigit(2);
      writeDigit(value); //write the "Value" digit
      delay(timeDelay);
    }
    
    switchDigit(3);
  
    //Write the minute
  
  
    value = minute();   //Put Minute into a variable
    if (value > 9) {
      
      b = (String(value))[0];
      writeDigit(b.toInt()); //Write the first digit
      delay(timeDelay);
      
      switchDigit(4);
  
      b = (String(value))[1];
      writeDigit(b.toInt());
      delay(timeDelay);
    }
  
    else {
      writeDigit(0);
      delay(timeDelay);
      switchDigit(4);
      
      writeDigit(value); //write the digit
      delay(timeDelay);
    }
    
  }   
} //End Main Loop






void writeDigit(int number) {
  
  int x = 0;
    while(x < 13) {
      digitalWrite((x+1), (mappingSets[number][x]));
      x++;
    }
   // digitalWrite(A1, mappingSets[number][12]);
}

/*void writeZero() {
 
  int x = 0;
  while(x < 13) {
    digitalWrite((x+1), (mappingSets[0][x]));
    x++;
  }
 // digitalWrite(A1, mappingSets[0][12]);
  
}
*/



void switchDigit(int x) {

  Wire.beginTransmission(1); // transmit to device #1
 
  Wire.write(x);        // send one byte - int 1, as a ping to device
  Wire.endTransmission();    // stop transmitting

}
