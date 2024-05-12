/*
SDL Check Bait

This program is an image viewer that makes use of "SDL_image" to load and save PNG files. Then it adds a checkerboard.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>



int width,height;

char filename[256],text[256];
SDL_Window *window = NULL;
SDL_Surface *surface,*bitmap,*bitmap_temp;
int loop=1;
SDL_Event e;
SDL_Rect rect;

int fps=60; /*frames per second*/
int sdl_time,sdl_time1,delay;

#include "sdl_chaste_checkerboard_surface.h"
#include "sdl_chastefont_surface.h"

#include "sdl_checkbait_demo.h"

int main(int argc, char **argv)
{

 checkbait_demo_2();

 return 0;
}

