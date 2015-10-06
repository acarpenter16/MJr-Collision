#include <MeggyJrSimple.h> 

void setup() 
{

MeggyJrSimpleSetup();

}

int xdot = 0; // dot coordinates created and initialized (player)
int ydot = 0;
int directiondot = 0;

void loop() // run over and over again
{ 
  
ClearSlate();
CheckButtonsDown(); // Check to see which button(s) is/are down.

//Direction check
if (Button_Up) // up pressed, direction changes to 90
  directiondot=90;

if (Button_Down) 
   directiondot=270; // down pressed, direction changes to 270

if (Button_Right) 
  directiondot=0; // right pressed, direction changes to 0

if (Button_Left) 
  directiondot=180; // left pressed, direction changes to 180

//change the dot's coordinates based on current direction 
if ( directiondot==90) // up
  ydot=ydot+1;

if (directiondot==270) // down
   ydot=ydot-1;

if (directiondot==0) // right
  xdot=xdot+1;

if (directiondot==180) // left
  xdot=xdot-1;

//wrapping
if (ydot>7)
  ydot=0;
if (ydot<0) 
  ydot=7;

if (xdot>7)
  xdot=0;
if (xdot<0)
  xdot=7;
  
//collisions

if(ReadPx(xdot,ydot)==1)
  {
    Cool();
  }
  
if(ReadPx(xdot,ydot)==4)
  {
    Meow();
  }

DrawPx(3,5,1);
DrawPx(1,2,4);
DrawPx(xdot,ydot,12); 

DisplaySlate();
delay(300);
} 

void Cool()
{
 DrawPx(0,7,5);
 DrawPx(0,6,5);
 DrawPx(0,5,5);
 DrawPx(0,3,5);
 DrawPx(0,2,5);
 DrawPx(1,7,5);
 DrawPx(1,5,5);
 DrawPx(1,3,5);
 DrawPx(1,2,5);
 DrawPx(2,7,5);
 DrawPx(2,5,5);
 DrawPx(2,1,5);
 DrawPx(2,0,5);
 DrawPx(3,0,5);
 DrawPx(3,2,5);
 DrawPx(3,3,5);
 DrawPx(4,3,5);
 DrawPx(4,2,5);
 DrawPx(6,0,5);
 DrawPx(6,7,5);
 DrawPx(6,6,5);
 DrawPx(6,5,5);
 DrawPx(6,4,5);
 DrawPx(6,3,5);
 DrawPx(6,2,5);
}

void Meow()
{
  DrawPx(0,6,8);
  DrawPx(1,7,8);
  DrawPx(2,6,8);
  DrawPx(5,6,8);
  DrawPx(6,7,8);
  DrawPx(7,6,8);
  DrawPx(2,4,8);
  DrawPx(5,4,8);
  DrawPx(2,2,8);
  DrawPx(2,1,8);
  DrawPx(3,1,8);
  DrawPx(4,2,8);
  DrawPx(5,1,8);
  DrawPx(6,1,8);
  DrawPx(6,2,8);
}
