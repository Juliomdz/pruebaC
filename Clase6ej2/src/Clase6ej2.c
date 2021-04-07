/*
 ============================================================================
 Name        : Clase6ej2.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define CANTIDAD_NUMEROS 5
int arr_calcularMinimoInt2(int* array, int inicio, int limite, int* pResultado, int* indiceResultado);
int algoritmoLudmila(int* arrayOriginal, int limite);

int main(void) {

  int arrayNumeros[CANTIDAD_NUMEROS];

  for(int i=0;i<CANTIDAD_NUMEROS;i++)
    {
    utn_getNumero(&arrayNumeros[i],"Ingrese un numero:","ERROR!\n",0,150,2);
    }
  if(algoritmoLudmila(arrayNumeros, CANTIDAD_NUMEROS)==0)
    {
      algoritmoLudmila(arrayNumeros, CANTIDAD_NUMEROS);
      for ( int j = 0 ; j < CANTIDAD_NUMEROS ; j++ )
        {
         printf ("\nEn el Indice: %d el Valor es: %d \n", j, arrayNumeros[j]);
        }
    }
  return 0;
}



int algoritmoLudmila(int* arrayOriginal, int limite)
{
  int retorno = -1;
  int minimo;
  int indiceMinimo;
  int auxMinimo;
  int inicial =0;
  if(arr_calcularMinimoInt2(arrayOriginal,inicial, limite, &minimo, &indiceMinimo)==0)
  {
      arr_calcularMinimoInt2(arrayOriginal,inicial, limite, &minimo, &indiceMinimo);
      auxMinimo=arrayOriginal[0];
      arrayOriginal[0]=minimo;
      arrayOriginal[indiceMinimo] = auxMinimo;

      for(; inicial<limite-1;inicial++)
      {
          if (inicial != indiceMinimo)
            {
            arr_calcularMinimoInt2(arrayOriginal,inicial,limite, &minimo, &indiceMinimo);
            auxMinimo=arrayOriginal[inicial];
            arrayOriginal[inicial]=minimo;
            arrayOriginal[indiceMinimo]=auxMinimo;
            }
      }
    retorno =0;
  }
  return retorno;
}

int arr_calcularMinimoInt2(int* array, int inicio, int limite, int* pResultado, int* indiceResultado)
{
  int retorno = -1;
  int minimo;
  int indice;
  if(array != NULL && limite> 0 && pResultado !=NULL)
  {
    minimo = array[inicio];
    indice = inicio;
    for(int i=inicio; i<limite;i++)
      {
        if(array[i]< minimo)
        {
          minimo = array[i];
          indice = i;
        }
      }
    *pResultado=minimo;
    *indiceResultado=indice;
    retorno =0;
  }
  return retorno;
}
