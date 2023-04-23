#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update(); 
}

void onSwitch4Change()  {
  // Add your code here to act upon Switch4 change
  if(switch4)
  {
    digitalWrite(19, LOW);
  }
  else
  {
    digitalWrite(19,HIGH);
  }
}

void onSwitch2Change()  {
  if(switch2)
  {
    digitalWrite(17, LOW);
  }
  else
  {
    digitalWrite(17,HIGH);
  }
  // Add your code here to act upon Switch2 change
}

void onSwitch1Change()  {
  if(switch1)
  {
    digitalWrite(16, LOW);
  }
  else
  {
    digitalWrite(16,HIGH);
  }
  // Add your code here to act upon Switch1 change
}

void onSwitch3Change()  {
  if(switch3)
  {
    digitalWrite(18, LOW);
  }
  else
  {
    digitalWrite(18,HIGH);
  }
  // Add your code here to act upon Switch3 change
}
