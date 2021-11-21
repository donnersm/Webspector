# Webspector
Web bases 8-64 channel spectrum analyzer for ESP32

This project uses a ESP32 DEVKIT V1 and only 4 external components.
Using the switch, you can select the number of bands you want to display on the webinterface 8,16,24,32 or 64
Uppon first boot, the wifi manager will kick in asking your WIFI credentials. If it doens't, you can force the 
manager to start by holding the mode button while rebooting.

Below is a screendump ( Serial debugger) of a coorect boot:

Setting up Audio Input I2S
Configuring I2S...
I2S driver installed.
Audio input setup completed
*wm:[1] AutoConnect 
*wm:[2] ESP32 event handler enabled 
*wm:[2] Connecting as wifi client... 
*wm:[2] setSTAConfig static ip not set, skipping 
*wm:[1] Connecting to SAVED AP: EMDEE
*wm:[1] connectTimeout not set, ESP waitForConnectResult... 
*wm:[2] Connection result: WL_CONNECTED
*wm:[1] AutoConnect: SUCCESS 
*wm:[1] STA IP Address: 192.168.1.140

ESP32 is connected to Wi-Fi network, Don't forget to reboot if you just reconfigured the network settings.
You can reconfigure WIFI settings by pressing and holding the mode button when rebooting.
Program written by Mark Donners

The Electronic Engineer.
www.theelectronicengineer.nl
email: Mark.Donners@judoles.nl

Needed components:
ESP32 ( obviously )
Connected a switch to pin GPIO15(D15) and ground to create a mode button
Two identical resistor. can be any value between 1K and 50K als long as you use 2 of the same
Connect 1 resistor between pin GPIO36 (up) and ground. Connect the other resistor to +3.3V and GPIO36 
This will create an offset to your input signal to protect the esp32
Connect a capacitor of 220nF to GPIO36. The other end of the capacitor is your audio line in


The program is running on both cores. Core 1 is used for the main loop and does the FFT analyses
Core 0 is used for the webinterface. Both could run on 1 core but whenever the WIFI signal is disturbed,
for example by putting hand over the ESP32, the program would freeze...and the userinterface is not monitored.
Therefore, the webserver is on a different core. If it freezes up, the user interface will still work.

If you like this program, please buy me a coffee. The link is under the graph in the webinterface
   


HTTP server started
Webserver task is  running on core 0
