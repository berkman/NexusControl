/*
    Name:      Mike Berkman (mike@berkman.co)
    Date:      2013-04-13
    Purpose:   Receive input from Subaru steering wheel controls and translate the signal to control a Nexus 7 tablet.
               Intend to control Nexus power on/off, volume up, volume down, and mute.
    URL:       http://berkman.co/nexus
    
    Some code borrowed from http://atomic-cactus.com/2013/03/29/resistor-ladder-steering-wheel-control-interpreter-using-arduino/
*/

int sensorPin = A0;
int ledPin = 13;
float sensorValue = 0.00;

// Voltage readings from SWC
float BUTTON_OFF =            0.57;      // Volts.  114
float BUTTON_VOLUME_UP =      3.03;      // Volts.  611
float BUTTON_VOLUME_DOWN =    2.77;      // Volts.  557
float BUTTON_MUTE =           3.23;      // Volts.  651
float BUTTON_MODE =           2.47;      // Volts.  497
float BUTTON_CHANNEL_UP =     2.06;      // Volts.  413
float BUTTON_CHANNEL_DOWN =   1.53;      // Volts.  307


void setup() {
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  sensorValue = analogRead(sensorPin); 
  
  //float value = sensorValue *  (5.0 / 1023.0);
  
  Serial.println(sensorValue);
}
