// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 5. Write a C program to clip a line using Cohen-Sutherland Line Clipping Algorithm.


#include <graphics.h>
#include <stdio.h>

// Define constants to represent the region codes for points in relation to the clipping window.
#define INSIDE 0    // 0000
#define LEFT 1      // 0001
#define RIGHT 2     // 0010
#define BOTTOM 4    // 0100
#define TOP 8       // 1000

// Define the coordinates of the clipping window.
#define x_min 100 // left edge of clipping window
#define y_min 100 // bottom edge of clipping window
#define x_max 400 // right edge of clipping window
#define y_max 300 // top edge of clipping window

// Function to compute the region code for a given point in relation to the clipping window.
int computeRegionCode(int x, int y) {
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;

    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

// Function to clip a line segment to the clipping window using the Cohen-Sutherland algorithm.
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1, code2, accept = 0;
    while (1) {
    	// Compute the region codes for the endpoints of the line segment.
        code1 = computeRegionCode(x1, y1);
        code2 = computeRegionCode(x2, y2);
		
		// Check if the line segment is completely inside the clipping window.
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            break;
        } 
		// Check if the line segment is completely outside the clipping window.
		else if (code1 & code2) {
            break;
        } 
		// If the line segment intersects the clipping window, compute the intersection point(s).
		else {
            int x, y;

            int code_out = code1 ? code1 : code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Update the endpoint of the line segment that is outside the clipping window.
			if (code_out == code1) {
                x1 = x;
                y1 = y;
            } else {
                x2 = x;
                y2 = y;
            }
        }
    }

    // If the line segment is inside the clipping window, draw the clipped line segment in red.
	if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    // initialize graphics mode
    int gd = DETECT, gm;
    
    int x1, y1, x2, y2;

    // get the endpoints of the line
    printf("Enter the endpoints of the line:\n");
    printf("Endpoint 1 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Endpoint 2 (x2, y2): ");
    scanf("%d %d", &x2, &y2);

	initgraph(&gd, &gm, (char*)"");
	
	// draw the clipping window
    rectangle(x_min, y_min, x_max, y_max);
	
    // draw the original line
    setcolor(GREEN);
    line(x1, y1, x2, y2);

    // clip the line
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

