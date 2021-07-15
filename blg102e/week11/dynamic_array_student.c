#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
/*
Your function should:
    1) Create a 2-D array whose columns are appendable (dynamic)
    2) Create a 1-D dynamic array which will be used for storing the lastAnswer variables
    3) Handle 2 types of queries and fills in the aforementioned 2-D and 1-D arrays, based on the instructions
    4) Return the 1-D array and its size in the result_count variable
    5) Deletes the redundant variables which are created dynamically (by using malloc functions)
*/

    int *last_ans = malloc(n * sizeof(int));
    int **arr = malloc(n * sizeof(int*));
    int *length = malloc(n * sizeof(int));
    

    for(int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
        length[i] = 0;
    }
    *result_count = 0;
    
    for(int i = 0; i < queries_rows; i++) {

        int x = queries[i][1];
        int y = queries[i][2];
        int res = 0;
        if(*result_count > 0)
            res = last_ans[*result_count - 1];

        if(queries[i][0] == 1) {
            int idx = (x ^ res) % n;
            arr[idx][length[idx]] = y;
            length[idx]++;
        } else if(queries[i][0] == 2) {
            int idx = (x ^ res) % n;
            last_ans[*result_count] = arr[idx][y % length[idx]];
            *result_count += 1;
        }
    } 

    for(int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    free(length);

    for(int i = 0; i < queries_rows; i++) {
        free(queries[i]);
    }
    free(queries);

    queries = NULL;
    length = NULL;
    arr = NULL;
    return last_ans;

}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    
    int** queries = malloc(q * sizeof(int*));
    
    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * sizeof(int));
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }
    
    int result_count;
    int* result = dynamicArray(n, q, 3, queries, &result_count);
    
    for (int i = 0; i < result_count; i++){
        printf("%d", *(result + i));
        printf("\n");
    }
    
    free(result);
    result = NULL;
    return 0;
}

