 /********************************************************************************************************************************************************
 *                                                                                                                                                       *
 *  Project:         Webspector - WebServer based Spectrum Analyzer                                                                                      *
 *  Target Platform: ESP32                                                                                                                               *
 *                                                                                                                                                       * 
 *  Version: 1.0                                                                                                                                         *
 *  Hardware setup: See github                                                                                                                           *
 *                                                                                                                                                       *
 *                                                                                                                                                       * 
 *  Mark Donners                                                                                                                                         *
 *  The Electronic Engineer                                                                                                                              *
 *  Website:   www.theelectronicengineer.nl                                                                                                              *
 *  facebook:  https://www.facebook.com/TheelectronicEngineer                                                                                            *
 *  youtube:   https://www.youtube.com/channel/UCm5wy-2RoXGjG2F9wpDFF3w                                                                                  *
 *  github:    https://github.com/donnersm                                                                                                               *
 *                                                                                                                                                       *  
 ********************************************************************************************************************************************************/
 

#pragma once

#define MODE_BUTTON_PIN     15
#define GAIN_DAMPEN         2                       // Higher values cause auto gain to react more slowly
int NoiseTresshold =        1000;                   // this will effect the upper bands most.

// Other stuff don't change
#define ARRAYSIZE(a)    (sizeof(a)/sizeof(a[0]))
#define ADC_INPUT ADC1_CHANNEL_0
uint16_t offset = (int)ADC_INPUT * 0x1000 + 0xFFF;
double vReal[SAMPLEBLOCK];
double vImag[SAMPLEBLOCK];
int16_t samples[SAMPLEBLOCK];
arduinoFFT FFT = arduinoFFT(); /* Create FFT object */
byte peak[65];
int oldBarHeights[65];
volatile float FreqBins[65];
volatile float FreqBinsOD[65];
volatile float FreqBinsNW[65];


char Projectinfo[] PROGMEM = R"=====(
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

             +3.3V
               |                             ________ GPIO15
              | | 4.7K                      |
              | |                           |
               |                            |
 Audio --||---- ----->GPIO36               \
       220nF   |                            |
              | | 4..7K                     |
              | |                           |
               |                            |
              gnd                          gnd

The program is running on both cores. Core 1 is used for the main loop and does the FFT analyses
Core 0 is used for the webinterface. Both could run on 1 core but whenever the WIFI signal is disturbed,
for example by putting hand over the ESP32, the program would freeze...and the userinterface is not monitored.
Therefore, the webserver is on a different core. If it freezes up, the user interface will still work.

If you like this program, please buy me a coffee. The link is under the graph in the webinterface
   

)=====";
