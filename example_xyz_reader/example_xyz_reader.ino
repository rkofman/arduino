#include <Xterm.h>

//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Simple code for the ADXL335, prints calculated orientation via serial
//////////////////////////////////////////////////////////////////

// proper terminal output
Xterm xterm=Xterm();

//Analog read pins
const int xPin = 0;
const int yPin = 1;
const int zPin = 2;

//The minimum and maximum values that came from
//the accelerometer while standing still
//You very well may need to change these
int minVal = 0;
int maxVal = 125;

int minimum = 10000;
int maximum = -1000;
  
//to hold the caculated values
double x;
double y;
double z;


void setup(){
  Serial.begin(9600);
  xterm.init();          // if you forget about this line you will see lots of cursor related garbage

  xterm.print(1,1,"This is normal text",NORMAL); 
}

int i = 0;

void loop(){
for (i=0; i<100;i++)
  {
    xterm.print(1,1,"This is normal text",NORMAL); 
    xterm.print(1,30,i,NORMAL);
    xterm.print(2,1,"This is bold text",BOLD);
    xterm.print(2,30,i,BOLD);
    xterm.print(3,1,"This is underlined text",UNDERLINED);
    xterm.print(3,30,i,UNDERLINED);
    xterm.print(4,1,"This is blinking text",BLINK);
    xterm.print(4,30,i,BLINK);
    xterm.print(5,1,"This is inverted text",INVERSE);
    xterm.print(5,30,i,INVERSE);  
  }
  
  //read the analog values from the accelerometer
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);

  //convert read values to degrees -90 to 90 - Needed for atan2
  int xAng = map(xRead, minVal, maxVal, -90, 90);
  int yAng = map(yRead, minVal, maxVal, -90, 90);
  int zAng = map(zRead, minVal, maxVal, -90, 90);

  //Caculate 360deg values like so: atan2(-yAng, -zAng)
  //atan2 outputs the value of -π to π (radians)
  //We are then converting the radians to degrees
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  //Output the caculations
//  Serial.print("\r                                                         \r");
//  Serial.print("x: ");
//  Serial.print(x);
//  Serial.print(" | y: ");
//  Serial.print(y);
//  Serial.print(" | z: ");
//  Serial.print(z);


//  minimum = min(minimum, xRead);
//  minimum = min(minimum, yRead);
//  minimum = min(minimum, zRead);
//  
//  maximum = max(maximum, xRead);  
//  maximum = max(maximum, yRead);
//  maximum = max(maximum, zRead);
//    
//  Serial.print("minimum: ");
//  Serial.print(minimum);
//  Serial.print(" | maximum: ");
//  Serial.println(maximum);

  delay(300);//just here to slow down the serial output - Easier to read
}
