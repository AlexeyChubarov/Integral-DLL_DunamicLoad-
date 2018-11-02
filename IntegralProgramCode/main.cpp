#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <Windows.h>
#include <Winbase.h>
#include <libloaderapi.h>
#include "Integral.h"

constexpr auto k = 4 ;

int main()
{
	const int m = 14;

	//обь€вление типов и переменных
	typedef double (*funcp)(double x);

	int i;
	double delta[5];
	
	//подключение внешних библиотек и выгрузка функций из внешних библиотек
	
	HMODULE IntegralLib;
	IntegralLib = LoadLibrary("IntegralLib.dll");
	
	double (*pdIntegral)(double(*func)(double x), double from, double to, double step);
	(FARPROC &)pdIntegral = GetProcAddress(IntegralLib, "dIntegral");

	double(*pSinPlusCos)(double);
	(FARPROC &)pSinPlusCos = GetProcAddress(IntegralLib, "SinPlusCos");

	double(*pSinDivideId)(double);
	(FARPROC &)pSinDivideId = GetProcAddress(IntegralLib, "SinDivideId");

	double(*pSecMultiplyId)(double);
	(FARPROC &)pSecMultiplyId = GetProcAddress(IntegralLib, "SecMultiplyId");
	//объ€вление структур

	struct function {
		funcp f;
		char* fName;
	} funcArray[3] = { { pSinPlusCos,"sin(x)+cos(x)" }, 
	                 {  pSinDivideId, "sin(x)/x"}, 
	                 { pSecMultiplyId,"sec(x)*x"} };

	struct limits {
		double from, to;
	} integrals[5];
	
	//ввод пользовател€
	for (i = 0; i <= k; i++)
	{
		printf("please, enter the limits of integration:\t");
		scanf_s("%lf %lf", &integrals[i].from, &integrals[i].to);
		getchar();

		printf("please, enter the integration accuracy: \t");
		scanf_s("%lf", &delta[i]);
		getchar();
	}
	
	printf("computing, please, be patient :))\n");

	printf("Your results: \n");
	
	//вывод результатов интегрировани€
	for (i = 0; i <= m; i++)
	{
		printf("f(x)= %s on <%lf;%lf> equal % +12lf\n", funcArray[i/5].fName, integrals[i % 5].from, integrals[i % 5].to, pdIntegral(funcArray[i/5].f, integrals[i % 5].from, integrals[i % 5].to, delta[i%5]));
		fflush(stdout);
	}

	system("pause");
	return 0;
}