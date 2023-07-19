// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 3. Write a C program to implement Mid-Point Circle Drawing Algorithm.


#include <graphics.h>
#include <stdio.h>

int main()
{
   int gd = DETECT, gm; // Detects the graphics driver and mode
   int x, y, r, p;

   printf("Enter the center coordinates (x,y): ");
   scanf("%d %d", &x, &y);

   printf("Enter the radius: ");
   scanf("%d", &r);

   // Initialize graphics mode
   initgraph(&gd, &gm, (char*)"");

   // Initialize starting point
   p = 1 - r;
   putpixel(x, y, WHITE);

   // Draw the circle
   while (x < y)
   {
      x++;
      if (p < 0)
      {
         p += 2 * x + 1;
      }
      else
      {
         y--;
         p += 2 * (x - y) + 1;
      }
      putpixel(x + x, y + y, WHITE);
      putpixel(x + x - 1, y + y, WHITE);
      putpixel(x + x, y + y - 1, WHITE);
      putpixel(x + x - 1, y + y - 1, WHITE);
      putpixel(y + y, x + x, WHITE);
      putpixel(y + y - 1, x + x, WHITE);
      putpixel(y + y, x + x - 1, WHITE);
      putpixel(y + y - 1, x + x - 1, WHITE);
   }

   getch();
   closegraph();
   return 0;
}

