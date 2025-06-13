WoodCoreTranslucenceRig
===========

The distinction between sapwood and heartwood is important for the correct upscaling of point based measurements of sap flux densities (obtained from sapflow probes) to the tree level. In some cases, there are no obvious visual differences between sapwood and heartwood. In such cases, translucence may be an option to distinguish the hydraulically active sapwood from the heartwood. If you are lucky, natural light conditions are just fine for that method, but sometimes it can be necessary to get a better control of light for the translucence method.

In this repository I provide:
* 3D printable parts for a translucence rig (suited for wood core samples with ø = 5.15 mm )
* Firmware to use an Arduino to control an LED strip placed within the translucence rig
 
The current version of the translucence rig features slits at 10 mm intervals that make it possible to use a scalpel to slice the wood core while it is within the rig.

## About

![image](https://github.com/stseeger/WoodCoreTranslucenceRig/blob/main/doc/rigParts.png)

Print the following parts with a black, non-reflecting  material:  
[A: translucenceRig-rig.stl](Hardware/translucenceRig-rig.stl)  
[D: translucenceRig-socket.stl](Hardware/translucenceRig-socket.stl) (optional)  
[E: translucenceRig-slider.stl](Hardware/translucenceRig-slider.stl)  

Print the following part with a transparent material with a matte surface finnish:  
[E: translucenceRig-diffusor.stl](Hardware/translucenceRig-diffusor.stl)  

Aquire an WS2812B (or similar) LED strip with 60 LEDs/m (a 20 cm piece should suffice) and place it at the bottom of the rig.
[Connect the LED-strip to an Arduino Uno](doc/wiring_LED_to_Arduino.JPG) programmed with the [provided firmware](Firmware/translucenceRig/translucenceRig.ino).  

Connect the Arduino to a computer and open the Serial Monitor of the Arduino IDE to adjust the number of active LEDs and their brightness. If you are able to minimize the ambient light around the rig (e.g. by placing it in a dark box), you will get better results at lower brightness values of the LED strip.  

Aquire a fresh wood core (B) with an 5.15 mm increment borer and slide it into the rig.  Before fully sliding the core into the rig, you should find the orientation with the maximum translucence. Afterwards, you can use the slider (E) to move the core sample it within the rig.  

Identify the sapwood by translucence, take a photograph and use a scalpel to slice the wood core into sapwood and heartwood through one of the slits within the rig. Use the slider to push all parts of the wood core out of the rig.
