#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(0));

    int inside = 0;

    for(int i = 0; i < 1000000; i++)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        
        double d = sqrt(x*x + y*y);
        if(d <= 1.0)
            inside++;
        
    }

    double pi =(4.0 *  inside) / (1000000);
    printf("PI number is %lf\n", pi);
}
