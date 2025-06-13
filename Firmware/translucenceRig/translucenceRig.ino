/***
https://github.com/stseeger/WoodCoreTranslucenceRig

This script is intended to control an WS2812b LED strip that is to be placed at
the bottom of the translucenceRig to inspect wood core samples.

The script provides a command line interface to adjust the settings while
the script is running. Once you have found suiting settings, I recommend to adjust
the default values defined in this script.

--------------------
Dependencies:
The FastLED library available through the Arduino Library manager or:
https://github.com/FastLED/FastLED

The CmdArduino library available through the Arduino library manager or:
https://github.com/freaklabs/cmdArduino

--------------------
Connections:
WS2812b -> Adruino
+5V     -> VIN (assuming the Arduino is powered via USB)
Din     -> A0
GND     -> GND

!!! ATTENTION !!!
With white light at the highest brighntess value (255) each LED is drawing around 60 mA.
This means, that 15 LEDs at full brightness already draw 900 mA, which is the maximum allowed
current draw from an USB3-Port (the limit for an USB2-port is already at 500 mA).
Please keep that in mind and make sure not to overcharge your USB port.
Luckiliy, running the LEDs at much lower brightness levels produces the same results when used in a 
dark environment.
***/

//SETTINGS
#define DATA_PIN A0 // change to any other pin if yu need A0 for something else

// How many LEDs in your strip?
#define NUM_LEDS 15

// define variables to store settings and define default values
int value=20;
int first=1;
int count = 10;
char color = 'w';


//import libraries
#include <FastLED.h>
#include <cmdArduino.h>

//define device info
#define DEVICE "translucenceRig"
#define VERSION "2.0"


// Define the array of leds
CRGB leds[NUM_LEDS];

//~~~~~~~~~ define functions ~~~~~~~~~~~~~~~~~~~~~~

void cmd_info(int arg_cnt, char **args){
  Serial.println("----------------------");
  Serial.print(DEVICE);  
  Serial.print(" v");
  Serial.println(VERSION);

  Serial.println("Overview of possible commands:");
  Serial.println("   (if no value is passed for n or c, the current value will be returned)");
  Serial.println("?        : print this overview of commands");
  Serial.println("count [n]: set how many LEDs should be lit");
  Serial.println("first [n]: set the first led that should be lit (1<=n<=NUMBER_OF_LEDS");
  Serial.println("value [n]: set how bright the LEDs should be lit (0<=n<=255)");  
  Serial.println("color [c]: set the color of all LEDS ('w'=white, 'r'=red, 'g'=green, 'b'=blue)");
  if(!arg_cnt)Serial.print(">>");
}

void cmd_setFirstLED(int arg_cnt, char **args){
  if(arg_cnt<2) Serial.println(first);
  else first = atoi(args[1]); 
}

void cmd_setLEDcount(int arg_cnt, char **args){
  if(arg_cnt<2) Serial.println(count);
  else count = atoi(args[1]); 
}

void cmd_setBrightness(int arg_cnt, char **args){
  if(arg_cnt<2) Serial.println(value);
  else value = atoi(args[1]);
}

void cmd_setColor(int arg_cnt, char **args){
  if(arg_cnt<2) Serial.println(color);
  else color = args[1][0];  
}


//~~~~~~~~~ setup ~~~~~~~~~~~~~~~~~~~~~~

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
    FastLED.setBrightness(value);
    for(byte n=0; n < NUM_LEDS;n++) leds[n] = CRGB::Black;
    FastLED.show();
    
    // initialize command line interface
    cmd.begin(9600);
    // assign cmd commands
    /*
     * the first argument of cmdAdd is a command string,
     * the second argument is the function it will trigger
     */
    cmd.add("?", cmd_info);
    cmd.add("first", cmd_setFirstLED);
    cmd.add("count", cmd_setLEDcount);
    cmd.add("value", cmd_setBrightness);
    cmd.add("color", cmd_setColor);
    // inform the user how the device can be used
    cmd_info(0,NULL);
}


//~~~~~~~~~ main loop ~~~~~~~~~~~~~~~~~~~~~~
void loop() { 

  // check if a command was passed
  cmd.poll();

  //set color
  CRGB col = CRGB::White;
  if(color=='b') col=CRGB::Blue;
  if(color=='r') col=CRGB::Red;
  if(color=='g') col=CRGB::Green;

  // light as many LEDs as specified in count, starting at first
  for(byte n=1; n < NUM_LEDS;n++){    
    leds[n] = (n>=first & n < first+count) ? col : CRGB::Black;
  }
  
  //set brightness as specified by value
  FastLED.setBrightness(value);
  FastLED.show();
  delay(50);
}
