


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
int getNumero (int* numeroIngresado,char* pTexto,char* pError, int min, int max,int reintento)
{
	int retorno=-1;
	do
	{
	printf("%s",pTexto);
	__fpurge(stdin);
	if (scanf("%d",numeroIngresado))
	{
	if(*numeroIngresado>min && *numeroIngresado<max)
	{
		reintento=3;
		retorno= 0;
	}
	else
	{
		printf("%s",pError);
		reintento++;
		retorno=-1;
	}
	}
	else
	{
		printf("%s",pError);
		reintento++;
		retorno=-1;
	}
	}
	while(reintento<3);
	return retorno;
}
