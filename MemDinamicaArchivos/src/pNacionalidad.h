/*
 * pNacionalidad.h
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */

#ifndef PNACIONALIDAD_H_
#define PNACIONALIDAD_H_


#include "pNacionalidad.h"

#define IDINT_LEN 10
typedef struct
{
  int idNacionalidad;
  char descripcion[50]; // con su nombre seria
}pNacionalidad;

//----------------------------------------------------------------------- CREAR
pNacionalidad* pNacionalidad_new(void);
//----------------------------------------------------------------------- NEW CON PARAMETROS
pNacionalidad* pNacionalidad_newConParametros(int idNacionalidad, char* descripcion);
//----------------------------------------------------------------------- NEW CON PARAMETROS TXT
pNacionalidad* pNacionalidad_newConParametrosTxt(char* idNacionalidad, char* descripcion);


int pNacionalidad_agregarAlArray(pNacionalidad* arrayPunteros[], int limite, int idNacionalidad, char* descripcion);

int pNacionalidad_delete(pNacionalidad* this);
//----------------------------------------------------------------------- SET - GIT - ISVALID
int pNacionalidad_setIdNacionalidad(pNacionalidad* this, int id);
int pNacionalidad_getIdNacionalidad(pNacionalidad* this, int* flagError);
int pNacionalidad_isValidIdNacionalidad(int id);

int pNacionalidad_setDescripcion(pNacionalidad* this, char* descripcion);
char* pNacionalidad_getDescripcion(pNacionalidad* this, int* flagError);
int pNacionalidad_isValidDescripcion(char* descripcion);
//---------------------------------------------------------------------- SET - GET - ISVALID TXT
int pNacionalidad_setIdNacionalidadTxt(pNacionalidad* this, char* id);
char* pNacionalidad_getIdNacionalidadTxt(pNacionalidad* this, int* flagError);
int pNacionalidad_isValidIdNacionalidadTxt(char* id);

//----------------------------------------------------------------------- BUSCAR
int pNacionalidad_buscarIndiceVacio(pNacionalidad* arrayPunteros[], int limite);
int pNacionalidad_buscarIndicePorId(pNacionalidad* arrayPunteros[], int limite, int id);

//----------------------------------------------------------------------- INIT ARRAY
int pNacionalidad_initArray(pNacionalidad* arrayPunteros[], int limite);

//----------------------------------------------------------------------- IMPRIMIR
int pNacionalidad_imprimirUno(pNacionalidad* arrayPunteros[], int indice, int* flagError);
int pNacionalidad_imprimirArray(pNacionalidad* arrayPunteros[], int limite, int* flagError);




#endif /* PNACIONALIDAD_H_ */
