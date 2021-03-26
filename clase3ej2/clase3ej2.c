/*
 ============================================================================
 Name        : clase3ej2.c
 Author      : Julio
Consigna:
Hacer un men� con las funciones sumar, restar, multiplicar y dividir en el que se pueda
elegir que operaci�n realizar.
Al final del programa imprimir el resultado.
El usuario debe ingresar los numeros.
Obligatorio usar Switch.
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int multiplicar (int numeroA, int numeroB, float *punteroResultado);
int sumar (int numeroA, int numeroB, float *punteroResultado);
int restar (int numeroA, int numeroB, float *punteroResultado);
int dividir (int numeroA, int numeroB, float *punteroResultado);
int main(void) {
	float numeroA;
	float numeroB;
	float resultado;
	char operacion;
	int operacionErronea=1;

	printf("Ingrese un numero:\n");
	scanf("%f",&numeroA);
	do
	{
	printf("Selecione la operaci�n a realizar ingresando la opci�n deseada: [*+* , *-* , *x*, */*]\n");
	__fpurge(stdin);
	scanf("%c",&operacion);
	if(operacion=='+'||operacion=='-'||operacion=='x'||operacion=='/')
	{
		operacionErronea = 0;
	}
	else
	{
		printf("TIPO DE OPERACION ELEGIDA ERRONEA.\n");
		operacionErronea = 1;
	}
	}
	while(operacionErronea ==1);
	printf("Ingrese un numero:\n");
	scanf("%f",&numeroB);
	switch(operacion)
	{
		case'+':
			sumar(numeroA,numeroB,&resultado);
			break;
		case'-':
			restar(numeroA,numeroB,&resultado);
			break;
		case'x':
			multiplicar(numeroA,numeroB,&resultado);
			break;
		case'/':
			dividir(numeroA,numeroB,&resultado);
			break;
	}
	if(operacion!= '/')
	{
		printf("El resultado es %.2f",resultado);
	}
	else
	{
		if (dividir (numeroA, numeroB, &resultado) == 0)
		{
			printf("El resultado es %.2f",resultado);
		}
		else
		{
			printf("ERROR, no se puede dividir por 0");
		}
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
int multiplicar (int numeroA, int numeroB, float *punteroResultado)
{
	*punteroResultado = (float) numeroA * numeroB;
	return 0;
}
int sumar (int numeroA, int numeroB, float *punteroResultado)
{
	*punteroResultado = (float) numeroA + numeroB;
	return 0;
}
int restar (int numeroA, int numeroB, float *punteroResultado)
{
	*punteroResultado = (float) numeroA - numeroB;
	return 0;
}
