#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    char  name[50];
    char surname[50];
    char  year[50];
    printf("Enter Your Name:");
    scanf("%s", name);
    printf("Enter Your Surname:");
    scanf("%s", surname);
    printf("Enter Your Birthyear:");
    scanf("%s", year);

    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char my_rand_num[5]; 
    my_rand_num[0] = digits[rand() % 10];
    my_rand_num[1] = digits[rand() % 10];
    my_rand_num[2] = digits[rand() % 10];
    my_rand_num[3] = digits[rand() % 10];
    my_rand_num[4] = '\0';
    printf("Email Candidate 1: %c%s%c%c@itu.edu.tr\n", name[0], surname, year[2], year[3]);
    printf("Email Candidate 2: %c%c%c%c%s@itu.edu.tr\n", name[0], name[1], surname[0], surname[1], my_rand_num);
    printf("Email Candidate 3: %s%s%s@itu.edu.tr\n", surname, name, year); 
}
