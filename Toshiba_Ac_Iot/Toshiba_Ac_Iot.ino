/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
 *************************************************************/
 
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Toshiba.h>

// Install Blynk application, enter mailId and configure widgets.
// Check out your mailId that you gave when opening blynk account.
char auth[] = "-Kg_-NYi6gsPjmF***Something";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TP-Link_6F";
char pass[] = "1234";

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).
IRToshibaAC ac(kIrLed);  // Set the GPIO to be used for sending messages.

void printState() {
  // Display the settings.
  Serial.println("Toshiba A/C remote is in the following state:");
  Serial.printf("  %s\n", ac.toString().c_str());
  // Display the encoded IR sequence.
  unsigned char* ir_code = ac.getRaw();
  Serial.print("IR Code: 0x");
  for (uint8_t i = 0; i < kToshibaACStateLength; i++)
    Serial.printf("%02X", ir_code[i]);
  Serial.println();
  Blynk.virtualWrite(V3,ac.toString().c_str());
}


void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
 
  ac.begin();
  delay(200);

  // Set up what we want to send. See ir_Toshiba.cpp for all the options.
  Serial.println("Default state of the remote.");
  printState();
  Serial.println("Setting desired state for A/C.");
  ac.setMode(kToshibaAcCool);
}
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  Serial.println(pinValue);
   if (pinValue == 1)
  {
    ac.on();
  }
  else if (pinValue ==0)
  {
    ac.off();
  }
  ac.send();
}
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  ac.setFan(pinValue);
  ac.send();
}
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  ac.setTemp(pinValue);
  ac.send();
}
void loop()
{
  Blynk.run();
  // Now send the IR signal.
#if SEND_TOSHIBA_AC
  Serial.println("Sending IR command to A/C ...");
#endif  // SEND_TOSHIBA_AC
  printState();
  delay(5000);
}
