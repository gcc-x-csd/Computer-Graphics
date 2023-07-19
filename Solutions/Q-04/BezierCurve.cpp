// By - Kaustav Purkayastha ( Gurucharan University, Silchar - @ Department of Computer Science )

// 4. Write a C program to draw a Bezier Curve.


#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Calculate binomial coefficient
int binomialCoeff(int n, int k)
{
    int res = 1;

    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Calculate Bezier point for a given value of t
void calculateBezierPoint(int n, int *x, int *y, float t, int *xi, int *yi)
{
    float u = 1 - t;
    float coeff;
    *xi = 0;
    *yi = 0;

    // Calculate the point on the Bezier curve
    for (int i = 0; i <= n; i++)
    {
        coeff = binomialCoeff(n, i) * pow(u, n - i) * pow(t, i);
        *xi += x[i] * coeff;
        *yi += y[i] * coeff;
    }
}

int main()
{
    int gd = DETECT, gm;

    int n, x[100], y[100], i;
    float t, delta_t;

    // Get number of control points
    printf("Enter the number of control points: ");
    scanf("%d", &n);

    // Get coordinates of control points
    for (i = 0; i < n; i++)
    {
        printf("Enter the x coordinate of point %d: ", i + 1);
        scanf("%d", &x[i]);

        printf("Enter the y coordinate of point %d: ", i + 1);
        scanf("%d", &y[i]);
    }
    
    initgraph(&gd, &gm, (char*)"");
    
     for (i = 0; i < n; i++) {
     	putpixel(x[i], y[i], 3);
	 }

    // Calculate and draw points on the Bezier curve
    delta_t = 0.01;
    t = 0;
    while (t <= 1)
    {
        int xi, yi;
        calculateBezierPoint(n - 1, x, y, t, &xi, &yi);
        putpixel(xi, yi, WHITE);
        t += delta_t;
    }

    getch();
    closegraph();

    return 0;
}

