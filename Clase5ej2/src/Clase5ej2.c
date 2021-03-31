/*
 ============================================================================
 Name        : Clase5ej1.c
 Author      : Julio Mendez
 División    : H.
 Enunciado   : Hacer una funcion para hallar el maximo, otra para hallar el
               mínimo, y una tercera para hallar el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "arr.h"

#define CANTIDAD_EDADES 5
int main(void)
{
    int arrayEdades[CANTIDAD_EDADES];
    int acumuladorEdades;
    float promedioEdades;
    int maximo;

for(int i=0;i<CANTIDAD_EDADES;i++)
  {
  utn_getNumero(&arrayEdades[i],"Ingrese su edad:","ERROR!\n",0,150,2);
  }
    acumuladorEdades=0;
for(int i=0;i<CANTIDAD_EDADES;i++)
  {
    acumuladorEdades = acumuladorEdades + arrayEdades[i];
  }
for(int i=0;i<CANTIDAD_EDADES;i++)
  {
    arr_calcularMaximoInt(&arrayEdades[i],CANTIDAD_EDADES, &maximo);
  }
promedioEdades= (float)acumuladorEdades / CANTIDAD_EDADES;
  printf("El promedio de edades ingresadas es: %.2f",promedioEdades);
  printf("El maximo ingresado es: %d",maximo);
  return 0;
}

