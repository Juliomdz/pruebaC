/*
 * informe.c
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pProducto.h"
#include "pNacionalidad.h"
#include "pTipo.h"
#include "utn.h"
#include "informe.h"

//------------------------------------------------------------------ ALTA PRODUCTO
/*
*\brief Da de alta en una posicion del array
*\param lista Puntero al array de Cliente
*\param limite Es el limite del array de cliente
*\param id: Es el puntero al ID inicializado en el main
*\param indiceVacioEncontrado: indice vacio encontrado en el array
*\return Retorna 0 si OK, -1 ERROR
*/
int informe_altaArrayPunterosProducto(pProducto* arrayPproducto[], int limiteProductos, int* idProducto,
                      pNacionalidad* arrayPnacionalidad[], int limiteNacionalidad,
                      pTipo* arrayPtipo[], int limiteTipo)
{
  int retorno = -1;
  pProducto buffer;
  int flagError;
  int indiceRespuestaNacio, indiceRespuestaTipo;
  int indiceAlta = -1;
  int indiceTipoAltaProducto, indiceNacioAltaProducto;

  if(arrayPproducto != NULL && limiteProductos > 0 && idProducto != NULL && arrayPnacionalidad != NULL && limiteNacionalidad > 0 && arrayPtipo != NULL && limiteTipo > 0)
  {
    if(!utn_getAlfanumerico(buffer.descripcion, DESCIPCION_LEN, "\n - Ingrese descripcion >  ", "\n * ERROR *\n", 2))
    {
      pNacionalidad_imprimirArray(arrayPnacionalidad, limiteNacionalidad, &flagError);
        if(!utn_getNumero(&buffer.idNacionalidad, "\n - Ingrese ID nacionalidad  >  ", "\n * ERROR *\n", 0, 999999999, 2))
        {
          indiceRespuestaNacio = pNacionalidad_buscarIndicePorId(arrayPnacionalidad, limiteNacionalidad, buffer.idNacionalidad);
          if(indiceRespuestaNacio >= 0)
          {
            pTipo_imprimirArray(arrayPtipo, limiteTipo, &flagError);
            if(!utn_getNumero(&buffer.idTipo,  "\n - Ingrese ID tipo >  ",  "\n * ERROR *\n", 0, 999999999 , 2))
            {
              indiceRespuestaTipo = pTipo_buscarIndicePorId(arrayPtipo, limiteTipo, buffer.idTipo);
              if(indiceRespuestaTipo >= 0)
              {
                if(!utn_getNumeroFloat(&buffer.precioPorUnidad, "\n - Ingrese precio del producto >  ", "\n * ERROR *\n", 0, 1000000, 2))
                {
                  (*idProducto)++;
                  buffer.idProducto = *idProducto;
                  indiceAlta = pProducto_agregarAlArray(arrayPproducto, limiteProductos, buffer.idProducto, buffer.descripcion, buffer.idNacionalidad, buffer.idTipo, buffer.precioPorUnidad);
                  if(indiceAlta >= 0)
                  {
                    printf("\n=============================================================================="
                        "==================================================*\n");
                    pProducto_imprimirUno(arrayPproducto, indiceAlta, &flagError);
                    printf("\n");
                    indiceNacioAltaProducto = pNacionalidad_buscarIndicePorId(arrayPnacionalidad, limiteNacionalidad, buffer.idNacionalidad);
                    pNacionalidad_imprimirUno(arrayPnacionalidad, indiceNacioAltaProducto, &flagError);
                    printf("\n");
                    indiceTipoAltaProducto = pTipo_buscarIndicePorId(arrayPtipo, limiteTipo, buffer.idTipo);
                    pTipo_imprimirUno(arrayPtipo, indiceTipoAltaProducto, &flagError);
                    printf("\n=============================================================================="
                        "==================================================*\n");
                    retorno = 0;
                  }
                }
              }
              else
                printf("\n * EL ID TIPO NO EXISTE");
            }
          }
          else
            printf("\n * EL ID DE NACIONALIDAD NO EXISTE");
        }
    }
  }
  return retorno;
}
//----------------------------------------------------------------------- MODIFICAR PRODUCTO
int informe_menuModificarProducto(pProducto* arrayPproducto[], int limiteProductos,
                  pNacionalidad* arrayPnacionalidad[], int limiteNacionalidad,
                  pTipo* arrayPtipo[], int limiteTipo)
{
  int retorno = -1;
  int opcionMenu;
  int indiceModificar;
  int id;
  int flagError;
  int indiceRespuestaTipo;
  pProducto buffer;

  if(arrayPproducto != NULL && limiteProductos > 0 && arrayPnacionalidad != NULL && limiteNacionalidad > 0 && arrayPtipo != NULL && limiteTipo > 0)
  {
    informe_imprimirProductos(arrayPproducto, limiteProductos, arrayPnacionalidad, limiteNacionalidad, arrayPtipo, limiteTipo, &flagError);

    if(!flagError && !utn_getNumero(&id, "\n - Ingrese ID del producto a modificar > ", "\n * ERROR *\n", 0, 999999999, 2))
    {
      indiceModificar = pProducto_buscarIndicePorId(arrayPproducto, limiteProductos, id);
      if(indiceModificar >= 0)
      {
        do
        {
          if(!utn_getNumero(&opcionMenu,
                    "\n* =============  \x1b[93m\x1b[44mSUBMENU MODIFICAR\x1b[0m\x1b[0m  ============= *"
                    "\n| =============================================== |"
                    "\n| 1 -  Modificar Descripcion                      |"
                    "\n| 2 -  Modificar Nacionalidad                     |"
                    "\n| 3 -  Modificar Tipo                             |"
                    "\n| 4 -  Modificar Precio por unidad                |"
                    "\n| 5 -  Salir                                      |"
                    "\n* ----------------------------------------------- *"
                    "\n - Opcion >   ",
                    "\n   - ERROR -"
                    "\nOpcion invalida\n", 1, 5, 2))
          {
            switch(opcionMenu)
            {
              case 1: // Modificar Descripcion
                if(!utn_getAlfanumerico(buffer.descripcion, DESCIPCION_LEN,
                    "\n - Ingrese descripcion [alfanumerica] a modificar > ", "\n* DESCRIPCION INVALIDA *\n", 2))
                {
                  pProducto_setDescripcion(arrayPproducto[indiceModificar], buffer.descripcion);
                  printf("\n* DESCRIPCION MODIFICADA \n");
                }
              break;
              case 2: // Modificar Nacionalidad
                pNacionalidad_imprimirArray(arrayPnacionalidad, limiteNacionalidad, &flagError);
                if(!utn_getNumero(&buffer.idNacionalidad,  "\n - Ingrese ID nacionalidad >  ",  "\n * ERROR *\n", 0, 999999999 , 2))
                {
                  indiceRespuestaTipo = pNacionalidad_buscarIndicePorId(arrayPnacionalidad, limiteNacionalidad, buffer.idNacionalidad);
                  if(indiceRespuestaTipo >= 0)
                  {
                    pProducto_setIdNacionalidad(arrayPproducto[indiceModificar], buffer.idNacionalidad);
                    printf("\n* NACIONALIDAD MODIFICADA \n");
                  }
                  else
                    printf("\n* EL ID DE NACIONALIDAD NO EXISTE");
                }
              break;
              case 3: // Modificar Tipo
                pTipo_imprimirArray(arrayPtipo, limiteTipo, &flagError);
                if(!utn_getNumero(&buffer.idTipo,  "\n - Ingrese ID tipo >  ",  "\n * ERROR *\n", 0, 999999999 , 2))
                {
                  indiceRespuestaTipo = pTipo_buscarIndicePorId(arrayPtipo, limiteTipo, buffer.idTipo);
                  if(indiceRespuestaTipo >= 0)
                  {
                    pProducto_setIdTipo(arrayPproducto[indiceModificar], buffer.idTipo);
                    printf("\n* TIPO MODIFICADO \n");
                  }
                  else
                    printf("\n* EL ID TIPO NO EXISTE");
                }
              break;
              case 4: // Modificar Precio por unidad
                if(!utn_getNumeroFloat(&buffer.precioPorUnidad, "\n - Ingrese precio del producto >  ", "\n * ERROR *\n", 0, 1000000, 2))
                {
                  pProducto_setPrecioPorUnidad(arrayPproducto[indiceModificar], buffer.precioPorUnidad);
                  printf("\n* PRECIO X UNIDAD MODIFICADO \n");
                }
              break;
            }
            retorno = 0;
          }
        }while(opcionMenu != 5);
      }
      else
      {
        printf("\n* EL ID INGRESADO NO EXISTE\n");
      }
    }
  }
  return retorno;
}

//------------------------------------------------------------------ IMPRIMIR PRODUCTOS Y DETALLE
/*
*\brief Imprime array de punteros
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de punteros
*\return Retorna 0 si OK, -1 ERROR
*/
int informe_imprimirProductos(pProducto* arrayPproducto[], int limiteProductos,
                pNacionalidad* arrayPnacionalidad[], int limiteNacionalidad,
                pTipo* arrayPtipo[], int limiteTipo, int* flagError)
{
  *flagError = -1;
  int i, j, k;
  int flagErrorProducto, flagErrorTipo, flagErrorNacionalidad = -1;

  if(arrayPproducto != NULL && limiteProductos > 0 &&
     arrayPnacionalidad != NULL && limiteNacionalidad > 0 &&
     arrayPtipo != NULL && limiteTipo > 0 && flagError != NULL)
  {
    for(i=0; i<limiteProductos; i++)
    {
      if(arrayPproducto[i] != NULL)
      { for(j=0; j<limiteTipo; j++)
        {
          if(arrayPtipo[j] != NULL &&
             arrayPproducto[i]->idTipo == arrayPtipo[j]->idTipo)
          {
            for(k=0; k<limiteNacionalidad; k++)
            {
              if(arrayPnacionalidad[k] != NULL &&
                 arrayPproducto[i]->idNacionalidad == arrayPnacionalidad[k]->idNacionalidad)
              {
                printf("\n=============================================================================="
                    "==================================================*\n");
                pProducto_imprimirUno(arrayPproducto, i, &flagErrorProducto);
                printf("\n");
                pNacionalidad_imprimirUno(arrayPnacionalidad, k, &flagErrorNacionalidad);
                printf("\n");
                pTipo_imprimirUno(arrayPtipo, j, &flagErrorTipo);
                if(flagErrorProducto == 0 && flagErrorTipo == 0)
                  *flagError = 0;
              }else
                continue;
            }
          }
          else
            continue;
        }
      }else
        continue;
    }
  }
  return *flagError;
}

