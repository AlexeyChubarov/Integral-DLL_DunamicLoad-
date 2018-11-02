#ifndef _INTEGRAL_H_

#ifndef NAN
#define _HUGE_ENUF  1e+300
#define INFINITY   ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define NAN        ((float)(INFINITY * 0.0F))
#endif


extern "C" INTERGAL_DLL_API double dIntegral(double(*func)(double x), double from, double to, double step);

extern "C" INTERGAL_DLL_API double SinPlusCos(double x);

extern "C" INTERGAL_DLL_API double SinDivideId(double x);

extern "C" INTERGAL_DLL_API double SecMultiplyId(double x);
#define _INTEGRAL_H_
#endif
