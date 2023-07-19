// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 2. Write a C program to implement Bresenham's Line Drawing Algorithm.


#include <graphics.h>
#include <stdio.h>

int main()
{
   int gd = DETECT, gm; // Detects the graphics driver and mode
   int x1, y1, x2, y2, dx, dy, p, x, y;

   printf("Enter the starting coordinates (x1,y1): ");
   scanf("%d %d", &x1, &y1);

   printf("Enter the ending coordinates (x2,y2): ");
   scanf("%d %d", &x2, &y2);

   // Initialize graphics mode
   initgraph(&gd, &gm, (char*)"");

   dx = x2 - x1;
   dy = y2 - y1;
   x = x1;
   y = y1;

   putpixel(x, y, WHITE);

   p = 2 * dy - dx;

   while (x < x2)
   {
      if (p >= 0)
      {
         y++;
         p += 2 * dy - 2 * dx;
      }
      else
      {
         p += 2 * dy;
      }
      x++;
      putpixel(x, y, WHITE);
   }

   getch();
   closegraph();
   return 0;
}

