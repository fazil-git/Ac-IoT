#Hi Everyone

Pre-requisites:
    1. NodeMCU (ESP8266)
    2. IR Blaster (IR transmitter)
    3. Basic coding knowledge

Step-1:
    Install Arduino software and configure for ESP8266 board
    Check out this link to configure:  https://github.com/esp8266/Arduino
    Download and setup Blynk Library: https://github.com/blynkkk/blynk-library/releases/latest
    Download IRremoteESP8266 Library from the attachment or get new version from web.
    Download other libraries from the library folder that is attached or get new version from web.

Step-2:
    Install Blynk application in mobile with a valid mail id and set up widgets to control.
        Note: Configure widgets and setup virtual pins that gives input to your board.
        Learn about virtual pins : https://youtu.be/iueWEkM6cuQ

    You would receive an auth code to your mail id.
    Enter that auth code in your code. Eg. check line 39: char auth[] = "something";

Step-3:
    Setup your wifi credentials in the code.
    Connect GPIO pin 4 (which is D2 in NodeMCU dev board) to IR Blaster +ve(long pin).
    Connect the -ve(short pin) to the GND.

Step-4:
    Upload the code in your NodeMCU.
    You are good to go.
    
Enjoy switching On your AC and cool your room before you arrive!

Thank you!!