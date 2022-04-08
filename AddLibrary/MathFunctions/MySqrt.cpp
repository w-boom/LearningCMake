#include "MySqrt.h"

int MySqrt(int x) 
{
	/*
    if (x == 0) 
        return 0;

    double res = 1, pre = 0;
    while (abs(res - pre) > 1e-6) 
    {
        pre = res;
        res = (res + x / res) / 2;
    }
    return int(res);
	*/
	return 2 * x;
}