#include <stdio.h>

double info[2];
const double pi = 3.14159265358979323846;

void circle(double r)
{
    info[0] = 2 * pi * r;
    info[1] = pi * r * r;
    return;
}

void rectangle(double x, double y)
{
    info[0] = (x + y) * 2;
    info[1] = x * y;
    return;
}

void square(double x)
{
    info[0] = 4 * x;
    info[1] = x * x;
    return;
}

int main()
{
    char c;
    printf("Enter the shape type, e.g., rectangle, square, or circle\n"); 
    scanf("%s", &c);

    if(c == 'r')
    {
        printf("Enter the side lengths of the rectangle\n");
        double x, y;
        scanf("%lf %lf", &x, &y);
        rectangle(x, y); 
    }
    else if(c == 'c')
    {
        printf("Enter the radius of the circle\n");
        double r;
        scanf("%lf", &r);
        circle(r);        
    }
    else if(c == 's')
    {
        printf("Enter the side length of the square\n");
        double x;
        scanf("%lf", &x);
        square(x);
    }
    
    if(c == 'c')
        printf("Circumference: %lf\n", info[0]);
    else
        printf("Perimeter: %lf\n", info[0]);
    printf("Area: %lf\n", info[1]);
    
    return 0;
}












