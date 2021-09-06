/*
 * pTipo.c
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */


#include "pTipo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

//----------------------------------------------------------------------- CREAR
pTipo* pTipo_new(void)
{
  return (pTipo*) malloc (sizeof(pTipo) * 1);
}

pTipo* pTipo_newConParametros(int idTipo, char* marca, char* fabrica, char* tipoTela)
{
  pTipo* pAux;

  pAux = pTipo_new(); // pido memoria

  if(pAux != NULL)
  {
    if( pTipo_setIdTipo(pAux, idTipo)     <0 ||
      pTipo_setMarca(pAux, marca)       <0 ||
      pTipo_setFabrica(pAux, fabrica)   <0 ||
      pTipo_setTipoTela(pAux, tipoTela) <0)
    {
      pTipo_delete(pAux); // elimino memoria si no obtuvo los set
    }
  }
  else
  {
    printf("\n * No hay mas espacio en memoria");
  }
  return pAux;
}

int pTipo_agregarAlArray(pTipo* arrayPunteros[], int limite, int idTipo, char* marca, char* fabrica, char* tipoTela)
{
  int retorno = -1;
  int indiceVacio;

  if(arrayPunteros != NULL && limite > 0)
  {
    indiceVacio = pTipo_buscarIndiceVacio(arrayPunteros, limite);
    if(indiceVacio >= 0)
    {
      arrayPunteros[indiceVacio] = pTipo_newConParametros(idTipo, marca, fabrica, tipoTela);
      retorno = indiceVacio;
    }
  }
  return retorno;
}

//----------------------------------------------------------------- ID TIPO
int pTipo_setIdTipo(pTipo* this, int id)
{
  int retorno = -1;
  if(this != NULL && pTipo_isValidIdTipo(id))
  {
    this->idTipo = id;
    retorno = 0;
  }
  return retorno;
}

int pTipo_getIdTipo(pTipo* this,int* flagError)
{
  *flagError = -1;
  int auxId = -1;
  if(this != NULL && flagError != NULL )
  {
    auxId = this->idTipo;
    *flagError = 0;
  }
  return auxId;
}

int pTipo_isValidIdTipo(int id)
{
  int retorno = 0;
  if(id >= 0)
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------- MARCA
int pTipo_setMarca(pTipo* this, char* marca)
{
  int retorno = -1;
  if(this != NULL && marca != NULL && pTipo_isValidMarca(marca))
  {
    strncpy(this->marca, marca, MARCA_LEN);
    retorno = 0;
  }
  return retorno;
}
char* pTipo_getMarca(pTipo* this,int* flagError)
{
  *flagError = -1;
  char* aux= NULL;
  if(this != NULL && flagError != NULL )
  {
    aux = this->marca;
    *flagError = 0;
  }
  return aux;
}
int pTipo_isValidMarca(char* marca)
{
  int retorno = 0;

  if(marca != NULL && esAlfanumerico(marca)==1)
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------- FABRICA
int pTipo_setFabrica(pTipo* this, char* fabrica)
{
  int retorno = -1;
  if(this != NULL && fabrica != NULL && pTipo_isValidFabrica(fabrica))
  {
    strncpy(this->fabrica, fabrica, FABRICA_LEN);
    retorno = 0;
  }
  return retorno;
}
char* pTipo_getFabrica(pTipo* this,int* flagError)
{
  *flagError = -1;
  char* aux= NULL;
  if(this != NULL && flagError != NULL )
  {
    aux = this->fabrica;
    *flagError = 0;
  }
  return aux;
}
int pTipo_isValidFabrica(char* fabrica)
{
  int retorno = 0;

  if(fabrica != NULL && esAlfanumerico(fabrica)==1)
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------- TIPOTELA
int pTipo_setTipoTela(pTipo* this, char* tipoTela)
{
  int retorno = -1;
  if(this != NULL && tipoTela != NULL && isValidTipoTela(tipoTela))
  {
    strncpy(this->tipoTela, tipoTela, TIPOTELA_LEN);
    retorno = 0;
  }
  return retorno;
}
char* pTipo_getTipoTela(pTipo* this,int* flagError)
{
  *flagError = -1;
  char* auxtipoTela= NULL;
  if(this != NULL && flagError != NULL )
  {
    auxtipoTela = this->tipoTela;
    *flagError = 0;
  }
  return auxtipoTela;
}
int isValidTipoTela(char* tipoTela)
{
  int retorno = 0;
  if(tipoTela != NULL && esNombre(tipoTela))
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------------- NEW CON PARAMETROS TXT
pTipo* pTipo_newConParametrosTxt(char* idTipo, char* marca, char* fabrica, char* tipoTela)
{
  pTipo* pAux;

  pAux = pTipo_new(); // pido memoria

  if(pAux != NULL)
  {
    if( pTipo_setIdTipoTxt(pAux, idTipo)     <0 ||
      pTipo_setMarca(pAux, marca)       <0 ||
      pTipo_setFabrica(pAux, fabrica)   <0 ||
      pTipo_setTipoTela(pAux, tipoTela) <0)
    {
      pTipo_delete(pAux); // elimino memoria si no obtuvo los set
    }
  }
  else
  {
    printf("\n * No hay mas espacio en memoria");
  }
  return pAux;
}
//----------------------------------------------------------------------- SET - GET - IS VALID TXT
int pTipo_setIdTipoTxt(pTipo* this, char* id)
{
  int retorno = -1;
  if(this != NULL && id != NULL && pTipo_isValidIdTipoTxt(id))
  {
    this->idTipo = atoi(id);
    retorno = 0;
  }
  return retorno;
}
char* pTipo_getIdTipoTxt(pTipo* this,int* flagError)
{
  *flagError = -1;
  char* auxId = NULL;
  if(this != NULL && flagError != NULL)
  {
    sprintf(auxId, "%d", this->idTipo);
    *flagError = 0;
  }
  return auxId;
}
int pTipo_isValidIdTipoTxt(char* id)
{
  int retorno = 0;
  if(id != NULL && esNumerica(id, IDINT_LEN))
  {
    retorno = 1;
  }
  return retorno;
}
//* * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *
//----------------------------------------------------------------------- INIT ARRAY
/*
*\brief Incializa el array de punteros con NULL
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de cliente
*\return Retorna 0 si OK, -1 ERROR
*/
int pTipo_initArray(pTipo* arrayPunteros[], int limite)
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
//----------------------------------------------------------------------- BUSCAR
/*
*\brief Busca indice vacio en el array de punteros
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de puntero
*\return Retorna >= 0 si encuentra indice libre, -1 ERROR de parametros, -2 no encontró lugar libre
*/
int pTipo_buscarIndiceVacio(pTipo* arrayPunteros[], int limite)
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

int pTipo_buscarIndicePorId(pTipo* arrayPunteros[], int limite, int id)
{
  int retorno = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0 && id >= 0)
  {
    retorno = -2;
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] != NULL &&
         arrayPunteros[i]->idTipo == id)
      {
        retorno = i;
        break;
      }
    }
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
int pTipo_imprimirUno(pTipo* arrayPunteros[], int indice, int* flagError)
{
  *flagError = -1;

  if(arrayPunteros[indice] != NULL)
  {
    printf("ID TIPO: %-11d"
           "MARCA: %-21s"
         "FABRICA: %-23s"
         "TIPO DE TELA: %-20s",
          pTipo_getIdTipo(arrayPunteros[indice], flagError),
          pTipo_getMarca(arrayPunteros[indice], flagError),
          pTipo_getFabrica(arrayPunteros[indice], flagError),
          pTipo_getTipoTela(arrayPunteros[indice], flagError));
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
int pTipo_imprimirArray(pTipo* arrayPunteros[], int limite, int* flagError)
{
  *flagError = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0)
  {
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] != NULL)
      {
        printf("\n------------------------------------------------------------------------------------------------*\n");
        pTipo_imprimirUno(arrayPunteros, i, flagError);

        *flagError = 0;
      }
    }
  }
  return *flagError;
}

//----------------------------------------------------------------------- ELMIMINAR

int pTipo_delete(pTipo* this)// - DESTRUCTOR
{
  int retorno = -1;
  if(this != NULL)
  {
    free(this);
    retorno = 0;
  }
  return retorno;
}

int pTipo_eliminarIndiceArray(pTipo* arrayPunteros[], int limite,int indiceEliminar)
{
  int retorno = -1;

  if(arrayPunteros != NULL && indiceEliminar >= 0 && indiceEliminar < limite &&
     arrayPunteros[indiceEliminar] != NULL)
  {
    pTipo_delete(arrayPunteros[indiceEliminar]); // libera la direccion de memoria en la RAM
    arrayPunteros[indiceEliminar] = NULL; // apunto a NULL
    retorno = 0;
  }
  return retorno;
}

int pTipo_borrarIndicePorId(pTipo* arrayPunteros[], int limite, int minimoId, int maximoId, int reintentos)
{
  int retorno = -1;
  int indiceEliminar;
  int id;
  int flagError;

  if(arrayPunteros != NULL && limite > 0)
  {
    pTipo_imprimirArray(arrayPunteros, limite, &flagError);
    if(!flagError &&
       !utn_getNumero(&id, "\n - Ingrese ID a eliminar > ", "\n* ERROR *\n", 0, 999999999, reintentos))
    {
      indiceEliminar = pTipo_buscarIndicePorId(arrayPunteros, limite, id);
      if(indiceEliminar >= 0)
      {
        pTipo_eliminarIndiceArray(arrayPunteros, limite, indiceEliminar);
        retorno = 0;
      }
      else
      {
        printf("\n* EL ID INGRESADO NO EXISTE\n");
      }
    }

  }
  return retorno;
}
