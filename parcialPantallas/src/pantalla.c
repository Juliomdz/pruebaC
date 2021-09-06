/*
 * pantalla.c
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"




/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int pantalla_init(Pantalla* arrayPantalla,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPantalla != NULL)
    {
        retorno = 1;
        for(i=0;i<limite;i++)
        {
            arrayPantalla[i].idPantalla = i;
            strncpy(arrayPantalla[i].nombre, "", sizeof(arrayPantalla[i].nombre));
            arrayPantalla[i].precioPorDia = 0.0;
            strncpy(arrayPantalla[i].direccion, "", sizeof(arrayPantalla[i].direccion));
            strncpy(arrayPantalla[i].tipo, "", sizeof(arrayPantalla[i].tipo));
            arrayPantalla[i].isEmpty=1;
        }
    }
    return retorno;
}

int pantalla_mostrarDebug(Pantalla* pPantalla,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && pPantalla != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(pPantalla[i].isEmpty ==0)
              {
            printf("[DEBUG] - %d - %s - %s - %f - %s - %d\n",pPantalla[i].idPantalla, pPantalla[i].nombre,pPantalla[i].direccion,pPantalla[i].precioPorDia,pPantalla[i].tipo, pPantalla[i].isEmpty);
              }

        }
    }
    return retorno;
}
int pantalla_imprimir(Pantalla* pPantalla)
{
  int retorno = -1;
  if(pPantalla != NULL && !pPantalla->isEmpty)
    {
  printf("[Pantalla ID:%d] %s - precio: %.2f$ - %s\n",pPantalla->idPantalla, pPantalla->nombre,pPantalla->precioPorDia, pPantalla->direccion);
    retorno=0;
    }
  return retorno;
}

int pantalla_imprimirArray(Pantalla* arrayPantalla,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPantalla != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            pantalla_imprimir(&arrayPantalla[i]);

        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* arrayPantalla,int limite, int indice, int* id)
{
    int retorno = -1;
    Pantalla bufferPantalla;
    if(pantalla_buscarLugarLibre(arrayPantalla,&indice,limite) && indice <limite && limite > 0 && indice >=0 && id != NULL)
    {
        if(indice >= 0)
        {
            if(!utn_getText(bufferPantalla.nombre,"\nNombre? ","\nEso no es un nombre",SIZE_NOMBRE,2) &&
               !utn_getText(bufferPantalla.direccion,"\nDireccion? ","\nEso no es un direccion",SIZE_DIRECCION,2)&&
               !utn_getFloat(&bufferPantalla.precioPorDia,"\nPrecio? ","\nEso no es un precio",2) &&
               !utn_getText(bufferPantalla.tipo,"\nTipo: (1) para LCD (2) para LED pantallas gigantes? ","\nEso no es tipo\n",SIZE_TIPO,2))
                        {
                            bufferPantalla.idPantalla = *id;
                            bufferPantalla.isEmpty = 0;
                            arrayPantalla[indice] = bufferPantalla;
                            retorno = 1;
                            (*id)++;
                        }
        }

    }
    return retorno;
}

int pantalla_baja(Pantalla* pPantalla,int limite, int indice)
{
    int retorno = -1;
    if(!pantalla_isEmptyIndice(&pPantalla[indice])&&pPantalla!=NULL && limite >0 && indice >=0 && indice <limite)
      {
            retorno = 0;
            pPantalla[indice].isEmpty = 1;
      }
    return retorno;
}

int pantalla_modificacion(Pantalla* arrayPantalla,int limite, int indice)
{
    int retorno = -1;
    Pantalla bufferPantalla;
    if(!pantalla_isEmptyIndice(&arrayPantalla[indice])&& indice <limite && limite > 0 && indice >=0)
      {
                  if(!utn_getText(bufferPantalla.nombre,"\nNombre? ","\nEso no es un nombre",SIZE_NOMBRE,2) &&
                     !utn_getText(bufferPantalla.direccion,"\nDireccion? ","\nEso no es un direccion",SIZE_DIRECCION,2)&&
                     !utn_getFloat(&bufferPantalla.precioPorDia,"\nPrecio? ","\nEso no es un precio",2) &&
                     !utn_getText(bufferPantalla.tipo,"\nTipo: (1) para LCD (2) para LED pantallas gigantes? ","\nEso no es tipo\n",SIZE_TIPO,2))
                              {
                                   bufferPantalla.idPantalla =arrayPantalla[indice].idPantalla;
                                  bufferPantalla.isEmpty = 0;
                                  arrayPantalla[indice] = bufferPantalla;
                                  retorno = 0;
                              }
    }
    return retorno;
}

int pantalla_ordenarNombre(Pantalla* arrayPantalla,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && arrayPantalla != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(pantalla_isEmptyIndice(&arrayPantalla[i]) || pantalla_isEmptyIndice(&arrayPantalla[i+1]))
                  {
                    continue;
                  }
                  if(strncmp(arrayPantalla[i].nombre,arrayPantalla[i+1].nombre, SIZE_NOMBRE) > 0) //******
                    {
                        auxiliarEstructura = arrayPantalla[i];
                        arrayPantalla[i] = arrayPantalla[i+1];
                        arrayPantalla[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
            }
        }while(flagSwap);
        retorno =1;
    }
    return retorno;
}

int pantalla_ordenarNombrePrecio(Pantalla* arrayPantalla,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;
    int auxCompare;

    if(limite > 0 && arrayPantalla != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(pantalla_isEmptyIndice(&arrayPantalla[i]) || pantalla_isEmptyIndice(&arrayPantalla[i+1]))
                  {
                    continue;
                  }
                auxCompare= strncmp(arrayPantalla[i].nombre,arrayPantalla[i+1].nombre, SIZE_NOMBRE);
                    if( auxCompare > 0 ||
                      ( auxCompare == 0 && arrayPantalla[i].precioPorDia < arrayPantalla[i+1].precioPorDia) ) //******
                    {
                        auxiliarEstructura = arrayPantalla[i];
                        arrayPantalla[i] = arrayPantalla[i+1];
                        arrayPantalla[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
            }
            limite--;
        }while(flagSwap);
        retorno =1;
    }
    return retorno;
}

int pantalla_buscarLugarLibre(Pantalla* arrayPantalla,int* indiceLibre,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPantalla != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(pantalla_isEmptyIndice(&arrayPantalla[i]))
            {
                retorno = 1;
                *indiceLibre = i;
                break;
            }
        }
        if(*indiceLibre != i)
          {
            retorno =-2;
          }
    }
    return retorno;
}

int pantalla_isEmptyIndice(Pantalla* pPantalla)
{
  int retorno = -1;

  if(pPantalla != NULL)
  {
            if(pPantalla->isEmpty ==1)
            {
                retorno=1;
            }
            if(pPantalla->isEmpty!=1)
              {
                  retorno=0;
              }
    }
    return retorno;
}

int pantalla_buscarID(Pantalla* arrayPantalla,int limite, int valorBuscado, int indiceRespuesta)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPantalla != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(arrayPantalla[i].idPantalla == valorBuscado)
              {
                indiceRespuesta =i;
              }
        }
    }
    return retorno;
}

int pantalla_altaForzada(Pantalla* pPantalla,int limite,char* nombre,char* direccion, float precio, char* tipo, int indice,int* id)
{
    int retorno = -1;

    if(pantalla_isEmptyIndice(&pPantalla[indice])== 1&& limite > 0 && pPantalla != NULL&&indice >= 0)
    {

            retorno = 0;
            strncpy(pPantalla[indice].nombre,nombre,SIZE_NOMBRE);
            strncpy(pPantalla[indice].direccion,direccion,SIZE_DIRECCION);
            pPantalla[indice].precioPorDia = precio;
            strncpy(pPantalla[indice].tipo,tipo,SIZE_TIPO);
            pPantalla[indice].isEmpty = 0;
            (*id)++;
    }
    return retorno;
}

int get_option(int* pOpcion,int opciones)
{
 int retorno =-1;
 int bufferOpt=0;
 char bufferString[1024];
  do
    {
      if( pOpcion != NULL &&
          myGets(bufferString, sizeof(bufferString)) == 0 &&
          utn_esNumerica(bufferString, sizeof(bufferString)))
        {
          *pOpcion = atoi(bufferString);
          bufferOpt =*pOpcion;
          retorno = 1;
        }
      return retorno;
    }
  while(bufferOpt<1||bufferOpt>opciones);
}

int get_ledOLcd(char* pRespuesta)
{
  int retorno =-1;
  int bufferOption[64];
  do
    {
      if(get_option(bufferOption,2))
        {
          if(*bufferOption==1)
            {
              strncpy(pRespuesta,"LED",4);
            }
          else if(*bufferOption==2)
            {
              strncpy(pRespuesta,"LCD",4);
            }
        }
    }
  while(*bufferOption!=1 && *bufferOption !=2);
return retorno;
}
