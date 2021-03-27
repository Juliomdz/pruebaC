/*
 ============================================================================
 Name        : Sabado2ej1.c
 Author      : Julio Méndez
 División	 : H.
Ejercicio 2-1:
Crear una función que reciba como parámetro un numero entero. La función
retornara 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en
caso de que sea 0. Realizar la prueba lógica de la función en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "biblioteca.h"

int main(void) {

	int numeroIngresado;

	printf ("Ingrese un numero:");
	__fpurge(stdin);
	scanf ("%d", &numeroIngresado);

	if (validadorNumero (numeroIngresado) ==1)
	{
		printf ("El numero es Positivo");
	}
	else
	{
		if (validadorNumero (numeroIngresado) ==0)
		{
		printf ("El numero es 0.");
		}
	else if (validadorNumero (numeroIngresado) ==-1)
		{
		printf ("El numero es Negativo");
		}
	}

}
