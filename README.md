# OpenBuds
Convert your old wired headphones to Bluetooth using an ESP32.

**Latest Software Version: v4.0**

## How to Build:
For this Project you will need:
- Wired Headphones
- ESP32 (preferably dev kit c)
- Headphone yack (can also be hardwired)
- Breadboard
- Cables

These connections are needed:
GPIO25 -> TIP, RING 1 (Mono Channels)
GND -> RING 2 
SLEEVE -> GPIO34 (Not needed, will be future button control)

Software Setup
1. Download the OpenAudioDriver_ESP32.ino File and open it in the Arduino IDE
2. If not done yet, install ESP32 Boards: In the board manager install esp32 by Espressif Systems
3. Select the ESP32 Dev Module and the COM Port (on Linux most likely /dev/ttyUSB0)
4. Hold the Boot button on the ESP down
5. Click "FLASH"
6. release the button when its at 100%
7. DONE!

How to connect:
Open the Bluetooth Settings on your Phone and connect to "OpenBuds"
Play your music!

How it works:
Currently it only works Mono because Stereo caused ticking and scratiching souds. If you want the Stereo Driver please contact me. 
You can set the System Voulume using the Serial Monitor typing v100 (for 100% Volume), ... I tested it and I reccomend 90% Voulume because at 100% you get a bit of wierd effects. So if you set it to 90% and your phone to 100% you wont have these effects.
The System should have a very stable connection, from my test i could freely walk around 100m away without losing Connection.

Feel free to improve my driver and maybe get Stereo working, i already connected GPIO34 for button controls. For one Stop button you wont need a resistor but with multiple you might need some.

I use arch btw.
