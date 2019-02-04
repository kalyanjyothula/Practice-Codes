#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int grades_size, int* grades){
    // Complete this function
    for(int i=0;i<grades_size;i++)
    {   
        if(grades[i]>=38)
        {   
            int ex=grades[i]-(grades[i]%5)+5;
            if(ex-grades[i] < 3) grades[i]=ex;
        }
    }return grades;
}

int main() {
    int n; 
    scanf("%d", &n);
    int *grades = malloc(sizeof(int) * n);
    for(int grades_i = 0; grades_i < n; grades_i++){
       scanf("%d",&grades[grades_i]);
    }
    int* result = solve(n, grades);
    for(int result_i = 0; result_i <n; result_i++) {
        if(result_i) {
            printf("\n");
        }
        printf("%d", result[result_i]);
    }
    puts("");
    

    return 0;
}

