#include <Wire.h>
#include <Adafruit_LSM303.h>

Adafruit_LSM303 lsm;

/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag mag = Adafruit_LSM303_Mag(12345);

void setup() 
{
  Serial.begin(9600);
  
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
    while (1);
  }
  
  Serial.println("Magnetometer Test"); Serial.println("");
  /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }

}

void loop() 
{
  lsm.read();
//  Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
//  Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
//  Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
//  Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
//  Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
//  Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
//  delay(1000);
  
  
  /* Get a new sensor event */ 
  sensors_event_t event; 
  mag.getEvent(&event);
  
  float Pi = 3.14159;
  
  // Calculate the angle of the vector y,x
  float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;
  
  // Normalize to 0-360
  if (heading < 0)
  {
    heading = 360 + heading;
  }
  Serial.print("Compass Heading: ");
  Serial.println(heading);
  delay(500);
}
