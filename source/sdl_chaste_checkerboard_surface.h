/*
sdl_chaste_checkerboard.h

This file shows my own personal method of drawing a checkerboard in SDL2 using a renderer.
*/

struct checkerboard
{
 int x_begin,y_begin,x_end,y_end;
 int rectsize;
 int rectcolor;
};

struct checkerboard main_check;

/*set up initial state to allow drawing checkerboard to whole screen*/
void init_checkerboard()
{
 main_check.x_begin=0;
 main_check.y_begin=0;
 main_check.x_end=width;
 main_check.y_end=height;
 main_check.rectsize=32;
 main_check.rectcolor=0xFFFFFF;
}




/*
 this function draws a checkerboard. it is highly optimized because it does not switch colors during the function. it only draws half of the checkerboard squares and leaves the remaining areas the same as the background
*/
void chaste_checker()
{
 int x,y,index,index1;
 index=0;

 rect.w=main_check.rectsize;
 rect.h=main_check.rectsize;

 y=main_check.y_begin;
 while(y<main_check.y_end)
 {
  index1=index;
  x=main_check.x_begin;
  while(x<main_check.x_end)
  {
   if(index==1)
   {
    rect.x=x;
    rect.y=y;
    /*SDL_RenderFillRect(renderer,&rect);*/
    SDL_FillRect(surface,&rect,main_check.rectcolor);
   }
   index^=1;
   x+=main_check.rectsize;
  }
  index=index1^1;
  y+=main_check.rectsize;
 }

}
























