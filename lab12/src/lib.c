#include "lib.h"
#include <stdio.h>

int str_to_int(const char *str) 
{
    int result = 0;
    sscanf(str, "%d", &result);
    return result;
}

float str_to_float(const char *str) 
{
    float result = 0.0;
    sscanf(str, "%f", &result);
    return result;
}
