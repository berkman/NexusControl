/*
    Name:      Mike Berkman (mike@berkman.co)
    Date:      2013-04-13
    Purpose:   Receive input from Subaru steering wheel controls and translate the signal to control a Nexus 7 tablet.
               Intend to control Nexus power on/off, volume up, volume down, and mute.
    URL:       http://berkman.co/nexus
    
    Some code borrowed from Yuri (thanks!): 
    http://atomic-cactus.com/2013/03/29/resistor-ladder-steering-wheel-control-interpreter-using-arduino/
*/

int sensorPin = A0;
float sensorValue = 0.00;

// Voltage readings from SWC (in volts)
float BUTTON_OFF =            0.57;
float BUTTON_VOLUME_UP =      3.03;
float BUTTON_VOLUME_DOWN =    2.77;
float BUTTON_MUTE =           3.23;
float BUTTON_MODE =           2.47;
float BUTTON_CHANNEL_UP =     2.06;
float BUTTON_CHANNEL_DOWN =   1.53;


void setup() {
  Serial.begin(9600);
}


void loop() {
  sensorValue = analogRead(sensorPin); 
  
  // Input is on a scale of 0-1023.  Max voltage is 5.0V  Convert to the actual voltage
  float voltageValue = sensorValue *  (5.0 / 1023.0);
  
  Serial.println(voltageValue);
}
