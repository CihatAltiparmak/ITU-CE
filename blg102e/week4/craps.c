#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i = 0;
    int win = 0;
    int lose = 0;
    int c = 1;
    int cer = 0;
    while(i < 100000)
    {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int top = dice1 + dice2;


        if(c == 0)
        {
            if(top == 7)
            {
                lose++;
                c = 1;
                i++;
            }
            else if(top == cer)
            {
                win++;
                c = 1;
                i++;
            }   
            continue;
        }
        

        if(top == 7 || top == 11)
        {
            win++;
        }
        else if(top == 2 || top == 3 || top == 12)
        {
            lose++;
        }
        else
        {
            c = 0;
            cer = top;
            continue;
        }
        i++;
    }
    double res = (win * 1.0) / (lose + win);
    printf("%lf\n", 1 - res);  
   
}
