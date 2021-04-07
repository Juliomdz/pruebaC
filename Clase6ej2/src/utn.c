/*
 * utn.c
 *
 *  Created on: 30 mar. 2021
 *      Author: julio
 */




#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
//#include <time.h>
#include "utn.h"
int utn_getNumero (int* pResultado,char* mensaje,char* mensajeError, int minimo, int maximo,int reintentos)
{
  int retorno=-1;
  int bufferInt;
  if(pResultado !=NULL && mensaje !=NULL && mensajeError!=NULL &&minimo<=maximo)
  {
      retorno=-2;

      do
      {
      printf("%s",mensaje);
      __fpurge(stdin);
      scanf("%d",&bufferInt);
      if(bufferInt >= minimo && bufferInt <=maximo)
        {
        retorno = 0;
        *pResultado = bufferInt;
        break;
        }
      printf("%s",mensajeError);
      reintentos--;
      }
      while(reintentos>=0);
  }
  return retorno;
}
//////////////////////////////

int utn_getCharacter(char* pResultado,char* mensaje,char* mensajeError, char minimo, char maximo,int reintentos)
{
  int retorno=-1;
  char bufferChar;
  if(pResultado !=NULL && mensaje !=NULL && mensajeError!=NULL &&minimo<=maximo)
  {
      retorno=-2;

      do
      {
      printf("%s",mensaje);
      __fpurge(stdin);
      scanf("%c",&bufferChar);
      if(bufferChar >= minimo && bufferChar <=maximo)
        {
        retorno = 0;
        *pResultado = bufferChar;
        break;
        }
      printf("%s",mensajeError);
      reintentos--;
      }
      while(reintentos>=0);
  }
  return retorno;
}
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float utn_getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int utn_getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char utn_getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    __fpurge(stdin); //Linux y OSx
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
/*
 *  para obtener un numero aleatorio en un rango dado
char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}
*/
