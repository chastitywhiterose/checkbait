SDL Chaste Bitmap

Introduction:

This program is meant to be able to load a bitmap file and then create a window of equal size and display it. Basically it is an image viewer, but it is much more than that because I have full direct access to the pixels in this viewer and can modify them. This is for my own learning.

The original purpose of the SDL Chaste Bitmap project was to refine my knowledge of how images are loaded and stored in SDL as surfaces. My font library that was used in the SDL port of Chaste Tris, and Chaste Panel made use of Windows BMP images because SDL can load them natively. I threw the code together pretty quickly without understanding the formats used internally.

The correct format to use in my font library is "SDL_PIXELFORMAT_BGRA32". This is because it matches the RGB format expected by my code and is identical to what is used in HTML hexadecimal colors. Here are some examples.

0xFF0000 Red
0x00FF00 Green
0x0000FF Blue

Previous source of my games used "SDL_PIXELFORMAT_RGBA32". This reverses the red and blue bytes in the 32 bit integer so that it looks like 0xAABBGGRR. Obviously this is an error and yet because my font library only checked whether the pixel was black or white in the source font image, this order did not matter at the time and so the games have been running correctly. I will probably still fix this in future updates.

But the key thing that I have learned so far is that although it takes a lot of time to sort through the documentation and experiment around, it does mean I have a better idea how to access the pixels directly in SDL.

Usage:

Enter file as command line to display it.
Example:

./main ./bitmap/Chastity_Progress_Flag.png



Helpful SDL wiki pages

https://wiki.libsdl.org/SDL2/SDL_LoadBMP
https://wiki.libsdl.org/SDL2/SDL_ConvertSurfaceFormat
https://wiki.libsdl.org/SDL2/SDL_PixelFormatEnum
