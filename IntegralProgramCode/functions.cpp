#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "Integral.h"

double SinPlusCos(double x)
{
	return sin(x) + cos(x);
}

double SinDivideId(double x)
{
	return sin(x) / x;
}

double SecMultiplyId(double x)
{
	return x / cos(x);
}

double SqareId(double x)
{
	return x * x;
}