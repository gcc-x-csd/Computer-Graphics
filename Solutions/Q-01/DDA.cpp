// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 1. Write a C program to implement DDA Line Drawing Algorithm.


#include <graphics.h>
#include <stdio.h>

int main()
{
   int gd = DETECT, gm; // Detects the graphics driver and mode
   int x1, y1, x2, y2, dx, dy, steps, i;
   float x, y, x_inc, y_inc;

   printf("Enter the starting coordinates (x1,y1): ");
   scanf("%d %d", &x1, &y1);

   printf("Enter the ending coordinates (x2,y2): ");
   scanf("%d %d", &x2, &y2);

   // Initialize graphics mode
   initgraph(&gd, &gm, (char*)"");

   // Calculate the change in x and y
   dx = x2 - x1;
   dy = y2 - y1;

   // Determine the number of steps required to reach from (x1,y1) to (x2,y2)
   if (abs(dx) > abs(dy))
   {
      steps = abs(dx);
   }
   else
   {
      steps = abs(dy);
   }

   // Calculate the increment in x and y
   x_inc = dx / (float) steps;
   y_inc = dy / (float) steps;

   // Draw the line using DDA Algorithm
   x = x1;
   y = y1;

   for (i = 0; i < steps; i++)
   {
      putpixel(x, y, WHITE);
      x += x_inc;
      y += y_inc;
   }

   getch();
   closegraph();
   return 0;
}

