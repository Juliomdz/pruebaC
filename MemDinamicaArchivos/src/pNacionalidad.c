/*
 * pNacionalidad.c
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pNacionalidad.h"
#include "utn.h"

//----------------------------------------------------------------------- CREAR
pNacionalidad* pNacionalidad_new(void)
{
  return (pNacionalidad*) malloc (sizeof(pNacionalidad) * 1);
}

pNacionalidad* pNacionalidad_newConParametros(int idNacionalidad, char* descripcion)
{
  pNacionalidad* pAux;

  pAux = pNacionalidad_new(); // pido memoria

  if(pAux != NULL) // si no obtuvo memoria retorna NULL
  {
    if(pNacionalidad_setIdNacionalidad(pAux, idNacionalidad)   < 0 ||
       pNacionalidad_setDescripcion(pAux, descripcion)         < 0 )
    {
      pNacionalidad_delete(pAux); // elimino memoria si no obtuvo los set
    }
  }
  return pAux; // si obtuvo los set retorna aux
}

int pNacionalidad_agregarAlArray(pNacionalidad* arrayPunteros[], int limite, int idNacionalidad, char* descripcion)
{
  int retorno = -1;
  int indiceVacio;

  if(arrayPunteros != NULL && limite > 0)
  {
    indiceVacio = pNacionalidad_buscarIndiceVacio(arrayPunteros, limite);
    if(indiceVacio >= 0)
    {
      arrayPunteros[indiceVacio] = pNacionalidad_newConParametros(idNacionalidad, descripcion);
      retorno = indiceVacio;
    }
  }
  return retorno;
}
//----------------------------------------------------------------------- ELIMINAR
int pNacionalidad_delete(pNacionalidad* this)// - DESTRUCTOR
{
  int retorno = -1;
  if(this != NULL)
  {
    free(this);
    retorno = 0;
  }
  return retorno;
}

//-----------------------------------------------------------------------
int pNacionalidad_setIdNacionalidad(pNacionalidad* this, int id)
{
  int retorno = -1;
  if(this != NULL && pNacionalidad_isValidIdNacionalidad(id))
  {
    this->idNacionalidad = id;
    retorno = 0;
  }
  return retorno;
}

int pNacionalidad_getIdNacionalidad(pNacionalidad* this,int* flagError)
{
  *flagError = -1;
  int auxId = -1;
  if(this != NULL && flagError != NULL )
  {
    auxId=this->idNacionalidad;
    *flagError = 0;
  }
  return auxId;
}

int pNacionalidad_isValidIdNacionalidad(int id)
{
  int retorno = 0;
  if(id >= 0)
  {
    retorno = 1;
  }
  return retorno;
}
//-----------------------------------------------------------------------
int pNacionalidad_setDescripcion(pNacionalidad* this, char* descripcion)
{
  int retorno = -1;
  if(this != NULL && descripcion != NULL && pNacionalidad_isValidDescripcion(descripcion))
  {
    strcpy(this->descripcion,descripcion);
    retorno = 0;
  }
  return retorno;
}

char* pNacionalidad_getDescripcion(pNacionalidad* this,int* flagError)
{
  *flagError = -1;
  char* aux= NULL;
  if(this != NULL && flagError != NULL )
  {
    aux = this->descripcion;
    *flagError = 0;
  }
  return aux;
}
int pNacionalidad_isValidDescripcion(char* descripcion)
{
  int retorno = 0;

  if(descripcion != NULL && esAlfanumerico(descripcion))
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------------- NEW CON PARAMETROS TXT
pNacionalidad* pNacionalidad_newConParametrosTxt(char* idNacionalidad, char* descripcion)
{
  pNacionalidad* pAux;

  pAux = pNacionalidad_new(); // pido memoria

  if(pAux != NULL) // si no obtuvo memoria retorna NULL
  {
    if(pNacionalidad_setIdNacionalidadTxt(pAux, idNacionalidad)   < 0 ||
       pNacionalidad_setDescripcion(pAux, descripcion)         < 0 )
    {
      pNacionalidad_delete(pAux); // elimino memoria si no obtuvo los set
    }
  }
  return pAux; // si obtuvo los set retorna aux
}
//----------------------------------------------------------------------- SET - GET- IS VALID TXT
int pNacionalidad_setIdNacionalidadTxt(pNacionalidad* this, char* id)
{
  int retorno = -1;
  if(this != NULL && id != NULL && pNacionalidad_isValidIdNacionalidadTxt(id))
  {
    this->idNacionalidad = atoi(id);
    retorno = 0;
  }
  return retorno;
}
char* pNacionalidad_getIdNacionalidadTxt(pNacionalidad* this, int* flagError)
{
  *flagError = -1;
  char* auxId = NULL;

  if(this != NULL && flagError != NULL)
  {
    sprintf(auxId, "%d", this->idNacionalidad);
    *flagError = 0;
  }
  return auxId;
}
int pNacionalidad_isValidIdNacionalidadTxt(char* id)
{
  int retorno = 0;
  if(id != NULL && esNumerica(id, IDINT_LEN))
  {
    retorno = 1;
  }
  return retorno;
}
//* * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *
//----------------------------------------------------------------------- BUSACAR
/*
*\brief Busca indice vacio en el array de punteros
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de puntero
*\return Retorna >= 0 si encuentra indice libre, -1 ERROR de parametros, -2 no encontró lugar libre
*/
int pNacionalidad_buscarIndiceVacio(pNacionalidad* arrayPunteros[], int limite)
{
  int retorno = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0)
  {
    retorno = -2; // parametros OK pero no encontró indice vacio;
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] == NULL)
      {
        retorno = i;
        break;
      }
    }
  }
  return retorno;
}

int pNacionalidad_buscarIndicePorId(pNacionalidad* arrayPunteros[], int limite, int id)
{
  int retorno = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0 && id >= 0)
  {
    retorno = -2;
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] != NULL &&
         arrayPunteros[i]->idNacionalidad == id)
      {
        retorno = i;
        break;
      }
    }
  }
  return retorno;
}

//----------------------------------------------------------------------- INIT ARRAY
/*
*\brief Incializa el array de puntero con NULL
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de cliente
*\return Retorna 0 si OK, -1 ERROR
*/
int pNacionalidad_initArray(pNacionalidad* arrayPunteros[], int limite)
{
  int retorno = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0)
  {
    for(i=0; i<limite; i++)
    {
      arrayPunteros[i] = NULL;
    }
    retorno = 0;
  }
  return retorno;
}
//----------------------------------------------------------------------- IMPRIMIR
/*
*\brief Imprime uno del array de punteros
*\param arrayPunteros Puntero al array de punteros
*\param indice Ubicacion a ser mostrada del array de punteros
*\param flagError Puntero a la bandera
*\return Retorna 0 si OK, -1 ERROR
*/
int pNacionalidad_imprimirUno(pNacionalidad* arrayPunteros[], int indice, int* flagError)
{
  *flagError = -1;
  int aux;
  if (arrayPunteros != NULL && flagError != NULL)
  {
    aux = pNacionalidad_getIdNacionalidad(arrayPunteros[indice], flagError);

    printf("ID NACIONALIDAD: %-31d"
         "NACIONALIDAD: %-10s",
         pNacionalidad_getIdNacionalidad(arrayPunteros[indice], flagError),
         pNacionalidad_getDescripcion(arrayPunteros[indice], flagError));
      *flagError = 0;
  }
  return *flagError;
}
/*
*\brief Imprime array de punteros
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de punteros
*\return Retorna 0 si OK, -1 ERROR
*/
int pNacionalidad_imprimirArray(pNacionalidad* arrayPunteros[], int limite, int* flagError)
{
  *flagError = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0)
  {
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] != NULL)
      {
        printf("\n-----------------------------------------------------------------------------------*\n");
        pNacionalidad_imprimirUno(arrayPunteros, i, flagError);
        *flagError = 0;
      }
    }
  }
  return *flagError;
}


