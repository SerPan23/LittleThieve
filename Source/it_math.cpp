#include "it_math.h"
int it_min(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

double it_min(double a, double b)
{
    if(a > b)
        return a;
    return b;
}
