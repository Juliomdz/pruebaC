/*
 * utn.c
 *
 *  Created on: 16 mar. 2021
 *      Author: julio Méndez
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"


int myGets(char* string, int limite)
{
  int retorno = -1;
  char bufferString[4096];

  if(string != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
  {
    __fpurge(stdin);
    if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
    {
        bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
    }
    if(strnlen(bufferString,sizeof(bufferString)) <= limite)
        {
            strncpy(string,bufferString,limite);
            retorno=0;
        }
  }
  return retorno;
}

int utn_getInt(int* pResultado)
{
  int retorno = -1;
  char bufferString[64];

  if( pResultado != NULL &&
      myGets(bufferString, sizeof(bufferString)) == 0 &&
      utn_esNumerica(bufferString, sizeof(bufferString)))
    {
      *pResultado = atoi(bufferString);
      retorno = 0;
    }
  return retorno;
}

int getFloat(float* pResultado)
{
  int retorno = -1;
  char buffer[64];

  if(pResultado != NULL)
  {
    if(myGets(buffer, sizeof(buffer)) == 0 && utn_esDecimal(buffer,sizeof(buffer)))
    {
      *pResultado = atof(buffer);
      retorno = 0;
    }
  }

  return retorno;
}

int utn_esNumerica(char* cadena, int limite)
{
  int retorno = -1;
  int i = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 0;
    if(cadena[0] == '-' || cadena[0] == '+')
    {
        i=1;
    }
    for( ;i<limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] >= '0' && cadena[i] <= '9')
      {
        retorno = 1;
      }
    }
  }

  return retorno;
}

int utn_esDecimal(char* cadena, int limite)
{
  int retorno = -1;
  int punto = 1;
  int signo = 1;
  int i = 0;

  if(cadena != NULL && limite > 0)
  {
    retorno = 0;
    for( ;i<limite && cadena[i] != '\0'; i++)
    {
      if(cadena[i] >= '0' && cadena[i] <= '9')
      {
        if(i == 0 && cadena[i] == '-' && signo)
        {
          signo = 0;
        }
        if(cadena[i] == '.' && punto)
        {
          punto = 0;
        }
        retorno = 1;
      }
    }
  }

  return retorno;
}

int utn_getNumero(int* pNumero, const char* mensaje, const char* mensajeError, int min, int max,int reintentos)
{
  int retorno = -1;
  int bufferInt;

  if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && min <= max)
  {
    do
    {
      printf(mensaje);
      __fpurge(stdin);
      if(utn_getInt(&bufferInt) == 0 &&
         bufferInt >= min &&
         bufferInt <= max)
        {
          retorno = 0;
          *pNumero = bufferInt;
          break;
        }
        else
        {
            printf(mensajeError);
            reintentos--;
      }
    }while(reintentos);
    if(reintentos==0)
    {
    printf("¡No hay mas intentos, vaya a tomarle el pelo al codigo de su abuela!");
    retorno = -2;
    }
  }
  else
  {
    printf("hay parametros invalidos en la funcion");
  }
  return retorno;
}

int utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, int reintentos)
{
  int retorno = -1;
  float buffer;

  if(pNumero != NULL && pTexto != NULL && mensajeError != NULL)
  {
    while(reintentos)
    {
      printf(pTexto);
      __fpurge(stdin);
      if(getFloat(&buffer) == 0)
      {
        retorno = 0;
        *pNumero = buffer;
        break;
      }
      else
      {
        printf(mensajeError);
        reintentos--;
      }
    }
    if(reintentos==0)
    {
    printf("¡vaya a tomarle el pelo al codigo de su abuela!");
    }
  }
  else
  {
    printf("hay parametros invalidos en la funcion");
  }

  return retorno;
}

int utn_sumar(float numeroA, float numeroB, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = numeroA + numeroB;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

int utn_restar(float numeroA, float numeroB, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = numeroA - numeroB;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    if(divisor != 0)
    {
      resultado = dividendo / divisor;
      retorno = 0;
    }
    else
    {
      printf(pDivisionPorCero);
    }
  }

  *pResultado = resultado;
  return retorno;
}

int utn_multiplicar(float dividendo, float divisor, float* pResultado)
{
  int retorno = -1;
  float resultado;

  if(pResultado != NULL)
  {
    resultado = dividendo * divisor;
    retorno = 0;
  }

  *pResultado = resultado;
  return retorno;
}

int utn_factorial(float numero, float* pResultado)
{
  int retorno = -1;
  int acumulador = 1;

  if(pResultado != NULL)
  {
    if(numero <0)
    {
        retorno= -2;
        *pResultado=0;
    }
    else
    {
      if(numero==0)
      {
          *pResultado=1;
          retorno =0;
      }
      else
      {
        for(int i = 1; i <= numero; i++)
        {
          acumulador *= i;
        }
      }
      *pResultado = acumulador;
      retorno = 0;
    }
  }

  return retorno;
}

int utn_getText(char* pResultado, char* pMensaje, char* mensajeError, int limite, int reintentos)
{
  int retorno = -1;
  char buffer[limite];

  if(pResultado != NULL && pMensaje != NULL && mensajeError != NULL && limite >= 0 && reintentos >=0)
  {
    do
    {
      printf(pMensaje);
      __fpurge(stdin);
        if(myGets(buffer,limite)==0)
        {
          retorno = 0;
          strncpy(pResultado, buffer,limite);
          break;
        }
        else
          {
            printf(mensajeError);
            reintentos--;
          }
    }while(reintentos);
  }
  return retorno;
}
/////////////////////////////////////////////
///
int utn_GetChar(char* pResultado,char* pMensaje,char* mensajeError,int reintentos){
    int retorno=-1;
    char letra[2];

    do{
        printf("%s",pMensaje);
        if(!myGets(letra, 1) &&esLetra(letra)==0){
            *pResultado=*letra;
            retorno=0;
            break;
        }
        printf("%s",mensajeError);
        reintentos--;
    }while(reintentos >= 0);

    return retorno;
}

int esLetra(char* letra){
    int retorno=-1;
    if((*letra >= 'a' && *letra <= 'z') || (*letra >= 'A' && *letra <= 'Z')){
        retorno=0;
    }
    return retorno;
}
int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError)
{
  int retorno = -1;
  char bufferString[12];

  if(pCuit != NULL && pMensaje != NULL && pMensajeError != NULL)
  {
    printf("%s", pMensaje);
    __fpurge(stdin);
    if(myGets(bufferString, sizeof(bufferString)) == 0 && validarCuit(bufferString, sizeof(bufferString)) == 1)
    {
      strncpy(pCuit, bufferString, 12);
      retorno = 0;
    }
    else
    {
      printf("%s", pMensajeError);
    }
  }

  return retorno;
}

int validarCuit(char* cadena, int limite)
{
 int retorno = -1;

 if(cadena != NULL && limite > 0)
 {
   retorno = 1;
   for(int i = 0; i < limite && cadena[i] != '\0'; i++)
   {
     if(cadena[i] < '0' || cadena[i] > '9')
     {
       retorno = 0;
       break;
     }
   }
   if(strlen(cadena) != 11)
   {
     retorno = 0;
   }
 }

 return retorno;
}

////////////////////////



