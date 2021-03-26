/*
 ============================================================================
 Name        : Clase3ej1.c
 Author      : Julio
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

int getNumero (int* numeroIngresado,char* pTexto,char* pError, int min, int max,int reintento);
int main(void)
{
    int numero;

	if(getNumero(&numero,"Ingrese un número:","Fuera de rango\n",0,99,0)==0)
	{
		printf("Ingresaste %d",numero);
	}
	return 0;
}
