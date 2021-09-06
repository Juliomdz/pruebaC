/*
 * pProducto.c
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "pProducto.h"
#include "utn.h"

//----------------------------------------------------------------------- CREAR
pProducto* pProducto_new(void)
{
  return (pProducto*) malloc (sizeof(pProducto) * 1);
}

pProducto* pProducto_newConParametros(int idProducto, char* descripcion,
                    int idNacionalidad, int idTipo, float precioPorUnidad)
{
  pProducto* pAux;

  pAux = pProducto_new(); // pido memoria

  if(pAux != NULL)
  {
    if( pProducto_setIdProducto(pAux, idProducto)           <0 ||
      pProducto_setDescripcion(pAux, descripcion)         <0 ||
      pProducto_setIdNacionalidad(pAux, idNacionalidad)   <0 ||
      pProducto_setIdTipo(pAux, idTipo)                   <0 ||
      pProducto_setPrecioPorUnidad(pAux, precioPorUnidad) <0)
    {
      pProducto_delete(pAux); // elimino memoria si no obtuvo los set
    }
  }
  else
  {
    printf("\n * No hay mas espacio en memoria");
  }
  return pAux;
}

int pProducto_agregarAlArray(pProducto* arrayPunteros[], int limite, int idProducto, char* descripcion,
                                                                 int idNacionalidad, int idTipo, float precioPorUnidad)
{
  int retorno = -1;
  int indiceVacio;

  if(arrayPunteros != NULL && limite > 0)
  {
    indiceVacio = pProducto_buscarIndiceVacio(arrayPunteros, limite);
    if(indiceVacio >= 0)
    {
      arrayPunteros[indiceVacio] = pProducto_newConParametros(idProducto, descripcion, idNacionalidad, idTipo, precioPorUnidad);
      retorno = indiceVacio;
    }
  }
  return retorno;
}
//-----------------------------------------------------------------------
int pProducto_setDescripcion(pProducto* this, char* descripcion)
{
  int retorno = -1;
  if(this != NULL && descripcion != NULL && pProducto_isValidDescripcion(descripcion))
  {
    strncpy(this->descripcion, descripcion, DESCIPCION_LEN);
    retorno = 0;
  }
  return retorno;
}

char* pProducto_getDescripcion(pProducto* this,int* flagError)
{
  *flagError = -1;
  char* aux = NULL;
  if(this != NULL && flagError != NULL )
  {
    aux = this->descripcion;
    *flagError = 0;
  }
  return aux;
}
int pProducto_isValidDescripcion(char* descripcion)
{
  int retorno = 0;

  if(descripcion != NULL && esAlfanumerico(descripcion)==1)
  {
    retorno = 1;
  }
  return retorno;
}
//-----------------------------------------------------------------------
int pProducto_setIdProducto(pProducto* this, int id)
{
  int retorno = -1;
  if(this != NULL && pProducto_isValidIdProducto(id))
  {
    this->idProducto = id;
    retorno = 0;
  }
  return retorno;
}

int pProducto_getIdProducto(pProducto* this,int* flagError)
{
  *flagError = -1;
  int auxId = -1;
  if(this != NULL && flagError != NULL )
  {
    auxId=this->idProducto;
    *flagError = 0;
  }
  return auxId;
}

int pProducto_isValidIdProducto(int id)
{
  int retorno = 0;
  if(id >= 0)
  {
    retorno = 1;
  }
  return retorno;
}
//-----------------------------------------------------------------------
int pProducto_setIdNacionalidad(pProducto* this, int id)
{
  int retorno = -1;
  if(this != NULL && pProducto_isValidIdNacionalidad(id))
  {
    this->idNacionalidad = id;
    retorno = 0;
  }
  return retorno;
}

int pProducto_getIdNacionalidad(pProducto* this,int* flagError)
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

int pProducto_isValidIdNacionalidad(int id)
{
  int retorno = 0;
  if(id >= 0)
  {
    retorno = 1;
  }
  return retorno;
}
//-----------------------------------------------------------------------
int pProducto_setIdTipo(pProducto* this, int id)
{
  int retorno = -1;
  if(this != NULL && pProducto_isValidIdTipo(id))
  {
    this->idTipo = id;
    retorno = 0;
  }
  return retorno;
}

int pProducto_getIdTipo(pProducto* this,int* flagError)
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

int pProducto_isValidIdTipo(int id)
{
  int retorno = 0;
  if(id >= 0)
  {
    retorno = 1;
  }
  return retorno;
}

//-----------------------------------------------------------------------
int pProducto_setPrecioPorUnidad(pProducto* this, float precioPorUnidad)
{
  int retorno = -1;
  if(this != NULL && pProducto_isValidPrecioPorUnidad(precioPorUnidad))
  {
    this->precioPorUnidad = precioPorUnidad;
    retorno = 0;
  }
  return retorno;
}

float pProducto_getPrecioPorUnidad(pProducto* this,int* flagError)
{
  *flagError = -1;
  float aux = -1;
  if(this != NULL && flagError != NULL )
  {
    aux = this->precioPorUnidad;
    *flagError = 0;
  }
  return aux;
}

int pProducto_isValidPrecioPorUnidad(float precio)
{
  int retorno = 0;
  if(precio > 0)
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------------- NEW CON PARAMETROS TXT
pProducto* pProducto_newConParametrosTxt(char* idProducto, char* descripcion,
                    char* idNacionalidad, char* idTipo, char* precioPorUnidad)
{
  pProducto* pAux;

  pAux = pProducto_new(); // pido memoria

  if(pAux != NULL)
  {
    if( pProducto_setIdProductoTxt(pAux, idProducto)           <0 ||
      pProducto_setDescripcion(pAux, descripcion)            <0 ||
      pProducto_setIdNacionalidadTxt(pAux, idNacionalidad)   <0 ||
      pProducto_setIdTipoTxt(pAux, idTipo)                   <0 ||
      pProducto_setPrecioPorUnidadTxt(pAux, precioPorUnidad) <0)
    {
      pProducto_delete(pAux); // elimino memoria si no obtuvo los set
    }
  }
  else
  {
    printf("\n * No hay mas espacio en memoria");
  }
  return pAux;
}
//----------------------------------------------------------------------- SET - GET - ISVALID TXT
int pProducto_setIdProductoTxt(pProducto* this, char* id)
{
  int retorno = -1;
  if(this != NULL && id != NULL && pProducto_isValidIdProductoTxt(id))
  {
    this->idProducto = atoi(id);
    retorno = 0;
  }
  return retorno;
}

char* pProducto_getIdProductoTxt(pProducto* this, int* flagError)
{
  *flagError = -1;
  char* auxId = NULL;

  if(this != NULL && flagError != NULL )
  {
    sprintf(auxId, "%d", this->idProducto);
    *flagError = 0;
  }
  return auxId;
}

int pProducto_isValidIdProductoTxt(char* id)
{
  int retorno = 0;
  if(id != NULL && esNumerica(id, IDINT_LEN))
  {
    retorno = 1;
  }
  return retorno;
}
//------------------------------------------------------------
int pProducto_setIdNacionalidadTxt(pProducto* this, char* id)
{
  int retorno = -1;
  if(this != NULL && id != NULL && pProducto_isValidIdNacionalidadTxt(id))
  {
    this->idNacionalidad = atoi(id);
    retorno = 0;
  }
  return retorno;
}
char* pProducto_getIdNacionalidadTxt(pProducto* this, int* flagError)
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
int pProducto_isValidIdNacionalidadTxt(char* id)
{
  int retorno = 0;
  if(id != NULL && esNumerica(id, IDINT_LEN))
  {
    retorno = 1;
  }
  return retorno;
}
//------------------------------------------------------------
int pProducto_setIdTipoTxt(pProducto* this, char* id)
{
  int retorno = -1;
  if(this != NULL && id != NULL && pProducto_isValidIdTipoTxt(id))
  {
    this->idTipo = atoi(id);
    retorno = 0;
  }
  return retorno;
}
char* pProducto_getIdTipoTxt(pProducto* this,int* flagError)
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
int pProducto_isValidIdTipoTxt(char* id)
{
  int retorno = 0;
  if(id != NULL && esNumerica(id, IDINT_LEN))
  {
    retorno = 1;
  }
  return retorno;
}
//----------------------------------------------------------------
int pProducto_setPrecioPorUnidadTxt(pProducto* this, char* precioPorUnidad)
{
  int retorno = -1;
  if(this != NULL && precioPorUnidad != NULL && pProducto_isValidPrecioPorUnidadTxt(precioPorUnidad))
  {
    this->precioPorUnidad = atof(precioPorUnidad);
    retorno = 0;
  }
  return retorno;
}

char* pProducto_getPrecioPorUnidadTxt(pProducto* this, int* flagError)
{
  *flagError = -1;
  char* aux = NULL;
  if(this != NULL && flagError != NULL )
  {
    sprintf(aux, "%f", this->precioPorUnidad);
    *flagError = 0;
  }
  return aux;
}

int pProducto_isValidPrecioPorUnidadTxt(char* precio)
{
  int retorno = 0;
  if(precio != NULL && esFlotante(precio, PRECIOFLOAT_LEN))
  {
    retorno = 1;
  }
  return retorno;
}
//* * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *
//----------------------------------------------------------------------- INIT ARRAY
/*
*\brief Incializa el array de puntero con NULL
*\param arrayPunteros Puntero al array de punteros
*\param limite del array de cliente
*\return Retorna 0 si OK, -1 ERROR
*/
int pProducto_initArray(pProducto* arrayPunteros[], int limite)
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
int pProducto_buscarIndiceVacio(pProducto* arrayPunteros[], int limite)
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

int pProducto_buscarIndicePorId(pProducto* arrayPunteros[], int limite, int id)
{
  int retorno = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0 && id >= 0)
  {
    retorno = -2;
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] != NULL &&
         arrayPunteros[i]->idProducto == id)
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
int pProducto_imprimirUno(pProducto* arrayPunteros[], int indice, int* flagError)
{
  *flagError = -1;
  char bufferNacionalidad[NACIONALIDAD_LEN];
  int aux;

  aux = pProducto_getIdNacionalidad(arrayPunteros[indice], flagError);

  if(arrayPunteros != NULL &&
     !pProducto_obtenerCadenaPorOpcionNacionalidad(aux, NACIONALIDAD_LEN, bufferNacionalidad))
  {
    printf("\x1b[92mID PRODUCTO: %-7d\x1b[0m"
         "DESCRIPCION: %-15s"
         "ID NACIONALIDAD: %-15d"
         "ID TIPO: %-12d"
         "PRECIO UNITARIO: $ %-8.2f",
          pProducto_getIdProducto(arrayPunteros[indice], flagError),
          pProducto_getDescripcion(arrayPunteros[indice], flagError),
          pProducto_getIdNacionalidad(arrayPunteros[indice], flagError),
          pProducto_getIdTipo(arrayPunteros[indice], flagError),
          pProducto_getPrecioPorUnidad(arrayPunteros[indice], flagError));
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
int pProducto_imprimirArray(pProducto* arrayPunteros[], int limite, int* flagError)
{
  *flagError = -1;
  int i;
  if(arrayPunteros != NULL && limite > 0)
  {
    for(i=0; i<limite; i++)
    {
      if(arrayPunteros[i] != NULL)
      {
        printf("\n=============================================================================="
            "==================================================*\n");
        pProducto_imprimirUno(arrayPunteros, i, flagError);
        *flagError = 0;
      }
    }
  }
  return *flagError;
}

//----------------------------------------------------------------------- ELIMINAR

int pProducto_delete(pProducto* this)// - DESTRUCTOR
{
  int retorno = -1;
  if(this != NULL)
  {
    free(this);
    retorno = 0;
  }
  return retorno;
}

int pProducto_eliminarIndiceArray(pProducto* arrayPunteros[], int limite, int indiceEliminar)
{
  int retorno = -1;

  if(arrayPunteros != NULL && indiceEliminar >= 0 && indiceEliminar < limite &&
     arrayPunteros[indiceEliminar] != NULL)
  {
    pProducto_delete(arrayPunteros[indiceEliminar]); // libera la direccion de memoria en la RAM
    arrayPunteros[indiceEliminar] = NULL; // apunto a NULL
    retorno = 0;
  }
  return retorno;
}

int pProducto_borrarIndicePorId(pProducto* arrayPunteros[], int limite)
{
  int retorno = -1;
  int indiceEliminar;
  int id;
  int flagError = -1;

  if(arrayPunteros != NULL && limite > 0)
  {
    pProducto_imprimirArray(arrayPunteros, limite, &flagError);
    if(!flagError &&
       !utn_getNumero(&id, "\n - Ingrese ID a eliminar > ", "\n * ERROR *\n", 0, 999999999, 2))
    {
      indiceEliminar = pProducto_buscarIndicePorId(arrayPunteros, limite, id);
      if(indiceEliminar >= 0)
      {
        pProducto_eliminarIndiceArray(arrayPunteros, limite, indiceEliminar);
        retorno = 0;
        pProducto_imprimirUno(arrayPunteros, indiceEliminar, &flagError);
      }
      else
      {
        printf("\n* EL ID INGRESADO NO EXISTE\n");
      }
    }
  }
  return retorno;
}


//----------------------------------------------------------------------- OBTENER CADENA POR OPCION
/*
*\brief Obtiene una cadena segun la opcion entera elegida en el alta del array de punteros
*\param int opcion: Numero int, las opciones de los case
*\param int cadenaLen: Limite de la cadena a copiar
*\param char opcionCadenaObtenida: puntero al array a ser copiado
*\return void
*/
int pProducto_obtenerCadenaPorOpcionNacionalidad(int opcion,int cadenaLen ,char* opcionCadenaObtenida)
{
  int retorno = -1;
  char buffer[4096];

  if(opcion >= 0 && cadenaLen > 0 && opcionCadenaObtenida != NULL)
  {
    switch(opcion)
    {
      case 11:
        strncpy(buffer, "ARGENTINA", cadenaLen);
        break;
      case 12:
        strncpy(buffer, "EE.UU", cadenaLen);
        break;
      case 13:
        strncpy(buffer, "ITALIA", cadenaLen);
        break;
    }
    strncpy(opcionCadenaObtenida, buffer, cadenaLen);
    retorno = 0;
  }
  return retorno;
}

//----------------------------------------------------------------------- ORDENAR POR PRECIO, MAYOR A MENOR
/*
\brief Ordena precio por unidad de mayor a menor
\param lista Puntero al array de punteros
\param limite Limite del array de punteros
\return Retorna 0 si OK, .1 Error
*/
int pProducto_ordenarPorPrecioUnidad(pProducto* arrayPunteros[], int limite) // de mayor precio a menor precio
{
  int retorno = -1;
    int flagSwap;
    int i;
    float precioUno, precioDos;
    int flagErrorUno, flagErrorDos;
    pProducto* buffer; // genero un buffer para pasar la direccion de memoria donde se aloja ese

    if(arrayPunteros != NULL && limite > 0)
    {
      do // empieza iterar hasta que termine de swapear y retorna 0
      {
        flagSwap = 0; // SI HAGO SWAP CAMBIA DE VALOR
        for(i=0; i<(limite-1); i++)
        {
        if(arrayPunteros[i] != NULL && arrayPunteros[i+1] != NULL)
        {
          precioUno = pProducto_getPrecioPorUnidad(arrayPunteros[i], &flagErrorUno);
          precioDos = pProducto_getPrecioPorUnidad(arrayPunteros[i+1], &flagErrorDos);

          if(flagErrorUno==0 && flagErrorDos==0)
          {
            if(precioUno < precioDos)
            {
              flagSwap = 1;
              buffer = arrayPunteros[i];
              arrayPunteros[i] = arrayPunteros[i+1];
              arrayPunteros[i+1] = buffer;
            }
          }
        }
        }
      }while(flagSwap);
      retorno = 0;
    }
    return retorno;
}
//----------------------------------------------------------------------- ORDENAR POR DESCRIPCION, A - Z
/*
\brief Ordena alfabeticamente de la [A] - [Z] el array de punteros
\param lista Puntero al array de punteros
\param limite Limite del array de punteros
\return Retorna 0 si OK, .1 Error
*/
int pProducto_ordenarPorDescripcion(pProducto* arrayPunteros[], int limite) // de la [A] - [Z] alfabeticamente
{
  int retorno = -1;
    int flagSwap;
    int i;
    char descripcionUno[DESCIPCION_LEN], descripcionDos[DESCIPCION_LEN];
    int flagErrorUno, flagErrorDos;
    pProducto* buffer;

    if(arrayPunteros != NULL && limite > 0)
    {
      retorno = 0;
      do // empieza iterar hasta que termine de swapear y retorna 0
      {
        flagSwap = 0;
        for(i=0; i<(limite-1); i++)
        {
          if(arrayPunteros[i] != NULL && arrayPunteros[i+1] != NULL)
        {
            strncpy(descripcionUno, pProducto_getDescripcion(arrayPunteros[i], &flagErrorUno), DESCIPCION_LEN);
            strncpy(descripcionDos, pProducto_getDescripcion(arrayPunteros[i+1], &flagErrorDos), DESCIPCION_LEN);

          if(flagErrorUno==0 && flagErrorDos==0)
          {
            if(strncmp(descripcionUno, descripcionDos, DESCIPCION_LEN) > 0)
            {
              flagSwap = 1;
              buffer = arrayPunteros[i];
              arrayPunteros[i] = arrayPunteros[i+1];
              arrayPunteros[i+1] = buffer;
            }
          }
        }
        }
      }while(flagSwap);
    }
    return retorno;
}

