#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define BUFFER_SIZE 1000

int main() 
{
    char buffer[BUFFER_SIZE];
    if (!fgets(buffer, BUFFER_SIZE, stdin)) 
    {
        fprintf(stderr, "Failed to read input.\n");
        return 1;
    }
    
    int result_int = str_to_int(buffer);
    printf("Integer value: %d\n", result_int);
    
    float result_float = str_to_float(buffer);
    printf("Float value: %.2f\n", result_float);
    
    return 0;
}