WoodCoreTranslucenceRig
===========

The distinction between sapwood and heartwood is important for the correct upscaling of point based measurements of sap flux densities (obtained from sapflow probes) to the tree level. In some cases, there are no obvious visual differences between sapwood and heartwood. In such cases, translucence may be an option to distinguish the hydraulically active sapwood from the heartwood. If you are lucky, natural light conditions are just fine for that method, but sometimes it can be necessary to get a better control of light for the translucence method.

In this repository I provide:
* 3D printable parts for a translucence rig (suited for wood core samples with ø = 5.15 mm )
* Firmware to use an Arduino to control an LED strip placed within the translucence rig
 
The current version of the translucence rig features slits at 10 mm intervals that make it possible to use a scalpel to slice the wood core while it is within the rig.

## About

![image](https://github.com/stseeger/WoodCoreTranslucenceRig/blob/main/doc/rigParts.png)

Aquire an WS2812B (or similar) LED strip with 60 LEDs/m. A 20 cm piece should suffice.
Connect it to an Arduino Uno programmed with the firmware:
[translucenceRig.ino](Firmware/translucenceRig/translucenceRig.ino)

Print the following parts with a black, non-reflecting  material:
[A: translucenceRig-rig.stl](Hardware/translucenceRig-rig.stl)
[D: translucenceRig-socket.stl](Hardware/translucenceRig-socket.stl) (optional)
[E: translucenceRig-slider.stl](Hardware/translucenceRig-slider.stl)

Print the following part with a transparent material with a matte surface finnish:
[E: translucenceRig-diffusor.stl](Hardware/translucenceRig-diffusor.stl)
