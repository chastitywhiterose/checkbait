/*
This first demo is a complete program that creates a Window of a size based on an existing image or makes a default window if it can't be found
*/

int checkbait_demo_1()
{
 int x;

 if(SDL_Init(SDL_INIT_VIDEO))
 {
  printf( "SDL could not initialize! SDL_Error: %s\n",SDL_GetError());return -1;
 }

 x=IMG_Init(IMG_INIT_PNG);
 printf("IMG_Init: %d\n",x);

 /*test by using hard coded bitmap file*/
 strcpy(filename,"./bitmap/Progress Flag Square.png");

 printf("opening filename: %s\n",filename);



 bitmap_temp=IMG_Load(filename);

if(bitmap_temp!=NULL)
{
 bitmap=SDL_ConvertSurfaceFormat(bitmap_temp,SDL_PIXELFORMAT_BGRA32,0);
 SDL_FreeSurface(bitmap_temp);
}

 else
 {
  printf("No bitmap was loaded. Attempting to create blank image.\n");
  bitmap=SDL_CreateRGBSurfaceWithFormat(0,1280,720,32,SDL_PIXELFORMAT_BGRA32);
  SDL_FillRect(bitmap,NULL,0xFF000000);
  strcpy(filename,"Help Page");

  /*printf("Enter file as command line to display it.\nExample:\n\n%s ./bitmap/Chastity_Progress_Flag.png\n\n",argv[0]);*/
 }

 if(bitmap==NULL)
 {
  printf( "SDL could not load main image! SDL_Error: %s\n",SDL_GetError());
  return 0;
 }

 width=bitmap->w;
 height=bitmap->h;

 printf("bitmap loaded:\n");
 printf("bitmap width: %d\n",width);
 printf("bitmap height: %d\n",height);


 window=SDL_CreateWindow(filename,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN );
 if(window==NULL){printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );return -1;}

 surface = SDL_GetWindowSurface( window ); /*get surface for this window*/

 font_8=chaste_font_load("./font/FreeBASIC Font 8.bmp");
 main_font=font_8;

 SDL_BlitSurface(bitmap,NULL,surface,NULL);

/* 
if(argc==1)
{
 sprintf(text,"Enter file as command line to display it.\nExample:\n\n%s ./bitmap/Chastity_Progress_Flag.png",argv[0]);

 chaste_font_draw_string_scaled_color(text,64,300,3,0xFFFFFF);
}
*/


 /*chaste_font_draw_string_scaled_color("Chastity",64,300,3,0xFFFFFF);*/

init_checkerboard();
/*main_check.rectcolor=0x0000FF;*/

 main_check.x_begin=0;
 main_check.y_begin=0;
 /*main_check.x_end=width/2;*/
 /*main_check.y_end=height/2;*/

chaste_checker_xor();
 SDL_UpdateWindowSurface(window);

 delay=1000/fps;

 loop=1;
 while(loop)
 {
  sdl_time = SDL_GetTicks();
  sdl_time1 = sdl_time+delay;

SDL_BlitSurface(bitmap,NULL,surface,NULL);

 /*SDL_FillRect(surface,NULL,0xFF00FF);*/
 chaste_checker_xor();

 SDL_UpdateWindowSurface(window);

 main_check.x_begin--;
 /*main_check.y_begin--;*/

 /*time loop used to slow the game down so users can see it*/
 while(sdl_time<sdl_time1)
 {
  sdl_time=SDL_GetTicks();
 }

  /*test for events and only process if they exist*/
  while(SDL_PollEvent(&e))
  {
   if(e.type == SDL_QUIT){loop=0;}
   if(e.type == SDL_KEYUP)
   {
    if(e.key.keysym.sym==SDLK_ESCAPE){loop=0;}
   }
  }
 }

 if(0){IMG_SavePNG(surface,"output.png");}

 /*free memory of bitmaps now that we are done with them*/
 SDL_FreeSurface(font_8.surface);
 SDL_FreeSurface(bitmap);
 SDL_DestroyWindow(window);
 IMG_Quit();
 SDL_Quit();
 return 0;
}


/*this second demo always creates a window of specific size but then loads a smaller image onto it*/




int checkbait_demo_2()
{
 int x;
 int bitmap_width,bitmap_height;

 width=1920;
 height=1080;

 if(SDL_Init(SDL_INIT_VIDEO))
 {
  printf( "SDL could not initialize! SDL_Error: %s\n",SDL_GetError());return -1;
 }

 x=IMG_Init(IMG_INIT_PNG);
 printf("IMG_Init: %d\n",x);

 /*test by using hard coded bitmap file*/
 strcpy(filename,"./bitmap/Progress Flag Square.png");

 printf("opening filename: %s\n",filename);



 bitmap_temp=IMG_Load(filename);

if(bitmap_temp!=NULL)
{
 bitmap=SDL_ConvertSurfaceFormat(bitmap_temp,SDL_PIXELFORMAT_BGRA32,0);
 SDL_FreeSurface(bitmap_temp);
}

 else
 {
  printf("No bitmap was loaded. Attempting to create blank image.\n");
  bitmap=SDL_CreateRGBSurfaceWithFormat(0,1280,720,32,SDL_PIXELFORMAT_BGRA32);
  SDL_FillRect(bitmap,NULL,0xFF000000);
  strcpy(filename,"Help Page");

  /*printf("Enter file as command line to display it.\nExample:\n\n%s ./bitmap/Chastity_Progress_Flag.png\n\n",argv[0]);*/
 }

 if(bitmap==NULL)
 {
  printf( "SDL could not load main image! SDL_Error: %s\n",SDL_GetError());
  return 0;
 }

 bitmap_width=bitmap->w;
 bitmap_height=bitmap->h;

 printf("bitmap loaded:\n");
 printf("bitmap width: %d\n",bitmap_width);
 printf("bitmap height: %d\n",bitmap_height);


 window=SDL_CreateWindow(filename,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN );
 if(window==NULL){printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );return -1;}

 surface = SDL_GetWindowSurface( window ); /*get surface for this window*/

 font_8=chaste_font_load("./font/FreeBASIC Font 8.bmp");
 main_font=font_8;

 SDL_BlitSurface(bitmap,NULL,surface,NULL);



init_checkerboard();
/*main_check.rectcolor=0x0000FF;*/

 main_check.rectsize=60;

 main_check.x_begin=0;
 main_check.y_begin=0;
 /*main_check.x_end=width/2;*/
 /*main_check.y_end=height/2;*/

 /*chaste_checker();*/
 /*chaste_checker_xor();*/
 SDL_UpdateWindowSurface(window);

 delay=1000/fps;

 loop=1;
 while(loop)
 {
  sdl_time = SDL_GetTicks();
  sdl_time1 = sdl_time+delay;



 SDL_FillRect(surface,NULL,0x000000);


 chaste_checker();

/*set up rectangle position where image will be drawn*/
rect.x=(width-bitmap_width)/2;
rect.y=0;
rect.w=bitmap_width;
rect.h=bitmap_height;

 SDL_BlitSurface(bitmap,NULL,surface,&rect);

 /*chaste_checker_xor();*/

 SDL_UpdateWindowSurface(window);

 main_check.x_begin--;
 /*main_check.y_begin--;*/

 /*time loop used to slow the game down so users can see it*/
 while(sdl_time<sdl_time1)
 {
  sdl_time=SDL_GetTicks();
 }

  /*test for events and only process if they exist*/
  while(SDL_PollEvent(&e))
  {
   if(e.type == SDL_QUIT){loop=0;}
   if(e.type == SDL_KEYUP)
   {
    if(e.key.keysym.sym==SDLK_ESCAPE){loop=0;}
   }
  }
 }

 if(0){IMG_SavePNG(surface,"output.png");}

 /*free memory of bitmaps now that we are done with them*/
 SDL_FreeSurface(font_8.surface);
 SDL_FreeSurface(bitmap);
 SDL_DestroyWindow(window);
 IMG_Quit();
 SDL_Quit();
 return 0;
}

