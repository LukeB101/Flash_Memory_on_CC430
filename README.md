Flash_Memory_on_CC430
=====================

Using the flash memory for the CC430 chips on the KickSat Sprites:

With the use of the flash memory, if the power to the processing chip cuts out half way through the script, upon restart instead of going through the whole code you can skip to the point where it left off!

This can be used on the KickSat Sprites. If the sprite spins so the solar cells are no longer in sunlight, it will shutdown. If the sprite is programmed to transmit 3 pieces of data (eg. a message and gyroscope and magnetometer data), it will be interrupted. As transmitting a message is time consuming the sprite may not get round to transmitting the third segment of data. With the use of the flash memory this can be overcome. When the sprite transmits a piece of data it writes a character to the flash memory. If it shuts down and reboots it reads the flash memory and skips to the segment of data corresponding to this character.

=====================

In order for the code to work, you need to put the CCFlash folder and all of its contents in to this directory:

    ~/EnergiaKickSatWindows/hardware/msp430/libraries
