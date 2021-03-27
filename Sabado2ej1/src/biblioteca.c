/*
 * biblioteca.c
 *
 *  Created on: 27 mar. 2021
 *      Author: julio
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int validadorNumero (int numeroIngresado)
{
	int retorno;
	if(numeroIngresado == 0)
	{
	retorno = 0;
	}
	else
	{
		if(numeroIngresado>0)
		{
			retorno =1;
		}
		else if (numeroIngresado<0)
		{
			retorno = -1;
		}
	}
	return retorno;
}
