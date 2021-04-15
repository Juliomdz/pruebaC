/*
 ============================================================================
 Name        : Clase7ej1.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_ARRAY 11
int validarQueSeaNumero(char* cadena, int limite);

int main(void) {


  char texto[TAM_ARRAY];
  int saldoDelBanco=1;

  fgets(texto,TAM_ARRAY,stdin);
  // validar que sean todos los caracteres numericos (del 0 al 9)
  if(validarQueSeaNumero(texto, TAM_ARRAY)==1)
  {
    saldoDelBanco = atoi(texto);
  }

  printf("\ntenes %d pesos",saldoDelBanco);

  return EXIT_SUCCESS;
}

int validarQueSeaNumero(char* cadena, int limite)
{
  int retorno;
  int i=0;
  if(cadena != NULL && limite >0)
    {
      do
        {
         if(cadena[i] <'0' || cadena[i] > '9')
           {
             retorno = -1;
             break;
           }
         else
         {
             i++;
             limite--;
             retorno=1;
         }
         }
      while(limite!=0);
    }
  return retorno;
}
