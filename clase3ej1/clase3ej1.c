/*
 ============================================================================
 Name        : clase3ej1.c
 Author      : Julio
 Version     :
 Copyright   : 
 ENUNCIADO:
 Funcion que divida numero A por numero B, y validar que B sea distinto de 0.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int dividir (int numeroA, int numeroB, float *punteroResultado);
int main(void) {


	float resultado;


	if (dividir (4, 2, &resultado) == 0)
	{
		printf("El resultado es %f",resultado);
	}
	else
	{
		printf("ERROR, no se puede dividir por 0");
	}
	return EXIT_SUCCESS;
}

int dividir (int numeroA, int numeroB, float *punteroResultado)
{
	if(numeroB == 0)
	{
		return -1;
	}
	else
	{
	*punteroResultado = (float) numeroA / numeroB;
	return 0;
	}
}

