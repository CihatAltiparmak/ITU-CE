#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ARRAY_SIZE 10
 
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
 
void random_fill_array(int *arr){
    int i = 0;
    for(i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand();
}
 
int main(){
    
    //srand(time(NULL));
    int my_array[ARRAY_SIZE];
//    for(int i=0; i<ARRAY_SIZE; my_array[i++]=i);
//    random_fill_array(my_array);
    int i = 0;
    int a;
    scanf("%d", &a); 
    for(i=0; i<ARRAY_SIZE; i++)
        scanf("%d",&my_array[i]);
     
    printf("ORIGINAL ARRAY: ");
    for (i = 0; i < ARRAY_SIZE; printf("%-5d", my_array[i++]));
    printf("\n");

    // Implement the swap op here.
    for(i = 0; i < ARRAY_SIZE / 2; i++)
        swap(&my_array[i] , &my_array[ARRAY_SIZE - 1 - i]);
     
    printf("REVERSE ARRAY:  ");
    for (i = 0; i < ARRAY_SIZE; printf("%-5d", my_array[i++]));
    printf("\n");
    
    return EXIT_SUCCESS;
}
