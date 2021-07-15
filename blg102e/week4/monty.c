#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int dv = 1;
    srand(time(NULL)); 
    int i = 0;
    while (i < 1000) {
        int cup = rand() % 3 + 1;
        int user = rand() % 3 + 1;

       
        if (user != cup)
           dv++;
        i++;
    }

    double res = (dv * 1.0) / 1000;
    printf("degistiginde:  %lf\n", res);
    printf("degismediginde: %lf\n", 1 - res);
    return 0;
}
