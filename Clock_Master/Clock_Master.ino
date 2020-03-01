//#include <Time.h>
#include <TimeLib.h>
#include <Wire.h>

int timeDelay = 4;
int x;
int value;
int a;
String b;
int currentDigit;
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

  Wire.begin(1); //Join bus as device #1
  Wire.onReceive(receiveEvent); // register event
  //Serial.begin(9600);
  setTime(22, 53, 40, 1, 1, 2001);

  for (int thisPin = 1; thisPin < 14; thisPin++) { //Set pins to be output
  pinMode(thisPin, OUTPUT);
  }
  pinMode(A1, OUTPUT);
}
void loop() {
  //nothing here
  }
  


void receiveEvent(int x) {
  // put your main code here, to run repeatedly:
  time_t t = now();   //Get current time
  x = Wire.read();
  /*Serial.print(hour());
  Serial.print(" ");
  Serial.print(minute());
  Serial.print(" ");
  Serial.println(second()); */  
  if (x==1) {
  //Write the Hour
    value = hour();
    
    if (value < 10) {
      writeDigit(0);
      b = (String(value))[0];
     
    }
    else {
       b = (String(value))[0];
       writeDigit(b.toInt());
      b = (String(value))[1];
      
    }
    
  }

    

  else if (x==2) {
     writeDigit(b.toInt());
  }

  else if (x == 3) {
    value = minute();
    
    if (value < 10) {
      writeDigit(0);
      b = (String(value))[0];
     
    }
    else {
      b = (String(value))[0];
      writeDigit(b.toInt());
      b = String(value)[1];
      
    }
   
    
  }

  else if (x ==4 ) {
    writeDigit(b.toInt());
  }
  

  
}






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
