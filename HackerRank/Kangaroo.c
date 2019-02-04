#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* kangaroo(float x1, float v1, float x2, float v2) 
{
    int x=v1-v2;
    if(x>0)
    {
        float g=(x2-x1)+(v1-v2);
        float h=v1-v2;
        float n=g/h;      
        float s=(int)n;
        if(n!=s) return "NO";
        else return "YES";
    }
    else
        return "NO";
}

int main() {
    int x1; 
    int v1; 
    int x2; 
    int v2; 
    scanf("%i %i %i %i", &x1, &v1, &x2, &v2);
    int result_size;
    char* result = kangaroo(x1, v1, x2, v2);
    printf("%s\n", result);
    return 0;
}
