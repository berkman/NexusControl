/*
    Name:      Mike Berkman (mike@berkman.co)
    Date:      2013-04-25
    Purpose:   Receive input from Subaru steering wheel controlsv(SWC) and translate the signal to control a Nexus 7 tablet.
               Intend to control Nexus power on/off (mode), volume up, volume down, previous track, next track and mute.
    Device:    Sparkfun Pro Micro -- https://www.sparkfun.com/products/11098
    URL:       http://berkman.co/nexus
    
    Some code/guidance borrowed from Yuri (thanks!): 
    http://atomic-cactus.com/2013/03/29/resistor-ladder-steering-wheel-control-interpreter-using-arduino/

    Sparkfun Pro Micro tutorial found here:
    https://www.sparkfun.com/tutorials/337
    
    Button values sourced from Android:
    http://source.android.com/tech/input/keyboard-devices.html
*/

#define	KEY_MUTE	      0x7F    // Keyboard Mute
#define	KEY_VOLUMEUP	      0x80    // Keyboard Volume Up
#define	KEY_VOLUMEDOWN	      0x81    // Keyboard Volume Down
#define	KEY_PREVIOUSSONG      0xEA    // Keyboard Previous Song
#define	KEY_NEXTSONG	      0xEB    // Keyboard Next Song

int sensorPin =               A0;     // Voltage reading from SWC
int powerPin =                A3;     // Output for controlling on/off

float sensorValue =           0.00;
int delay_sec =               5;      // Delay between button presses
float range =                 0.10;   // Voltage range for button presses

// Voltage readings from SWC (in volts)
float BUTTON_OFF =            0.57; // .47 - .67
float BUTTON_CHANNEL_DOWN =   1.53; // 1.43 - 1.63
float BUTTON_CHANNEL_UP =     2.06; // 1.96 - 2.16
float BUTTON_MODE =           2.47; // 2.37 - 2.57
float BUTTON_VOLUME_DOWN =    2.77; // 2.67 - 2.87
float BUTTON_VOLUME_UP =      3.03; // 2.93 - 3.13
float BUTTON_MUTE =           3.23; // 3.13 - 3.33

void sendKey(byte key, byte modifiers = 0);


void setup() {
  Serial.begin(9600);
}


void loop() {
  sensorValue = analogRead(sensorPin); 
  
  // Input is on a scale of 0-1023.  Max voltage is 5.0V  Convert to the actual voltage
  float voltageValue = sensorValue *  (5.0 / 1023.0);
  
  Serial.println(voltageValue);
  
  sendKey(KEY_VOLUMEUP);
  delay(delay_sec * 1000);
}



void sendKey(byte key, byte modifiers) {
  KeyReport report = {0};
  
  report.keys[0] = key;
  report.modifiers = modifiers;
  report.reserved = 1;
  Keyboard.sendReport(&report);
  
  /* Now we've got to send a report with nothing pressed */
  for (int i=0; i<6; i++)
    report.keys[i] = 0;
  report.modifiers = 0x00;
  report.reserved = 0;
  Keyboard.sendReport(&report);
}
