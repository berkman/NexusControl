/*
    Name:      Mike Berkman (mike@berkman.co)
    Date:      2013-03-22
    Purpose:   Receive input from Subaru steering wheel controls and translate the signal to control a Nexus 7 tablet.
               Intend to control Nexus power, volume UP, volume DOWN, and mute.
    URL:       http://berkman.co/nexus
*/

int sensorPin = A0;
int ledPin = 13;
float sensorValue = 0.00;


void setup() {
  pinMode (ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  sensorValue = analogRead(sensorPin);
  //sensorValue = sensorValue * 1000000;  
  
  //float value = sensorValue *  (5.0 / 1023.0);
  
  Serial.println(sensorValue);
  //delay(3000);
}


//Sensor Values

// 20k resistance

// off = 114.00  0.57V
// volume up = 611.00  3.03V   
// volume down = 557.00  2.77V
// mute = 651.00   3.23V
// mode = 497.00  2.47V
// channel down =  307.00  1.53V 
// channel up = 413.00  2.06V
