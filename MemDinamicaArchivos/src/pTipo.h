/*
 * pTipo.h
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */

#ifndef PTIPO_H_
#define PTIPO_H_


#define MARCA_LEN 50
#define FABRICA_LEN 50
#define TIPOTELA_LEN 50
#define IDINT_LEN 10

typedef struct
{
  int idTipo;
  char marca[MARCA_LEN];
  char fabrica[FABRICA_LEN];
  char tipoTela[TIPOTELA_LEN];

}pTipo;

//----------------------------------------------------------------------- INIT ARRAY
int pTipo_initArray(pTipo* arrayPunteros[], int limite);

//----------------------------------------------------------------------- CREAR
pTipo* pTipo_new(void);
//----------------------------------------------------------------------- NEW CON PARAMETROS
pTipo* pTipo_newConParametros(int idTipo, char* marca, char* fabrica, char* tipoTela);
//----------------------------------------------------------------------- NEW CON PARAMETROS TXT
pTipo* pTipo_newConParametrosTxt(char* idTipo, char* marca, char* fabrica, char* tipoTela);

int pTipo_agregarAlArray(pTipo* arrayPunteros[], int limite, int idTipo, char* marca, char* fabrica, char* tipoTela);

//----------------------------------------------------------------------- ELIMINAR
int pTipo_delete(pTipo* this); // - DESTRUCTOR
int pTipo_eliminarIndiceArray(pTipo* arrayPunteros[], int limite,int indiceEliminar);
int pTipo_borrarIndicePorId(pTipo* arrayPunteros[], int limite, int minimoId, int maximoId, int reintentos);

//----------------------------------------------------------------------- SET - GET - IS VALID
int pTipo_setIdTipo(pTipo* this, int id);
int pTipo_getIdTipo(pTipo* this, int* flagError);
int pTipo_isValidIdTipo(int id);

int pTipo_setMarca(pTipo* this, char* marca);
char* pTipo_getMarca(pTipo* this,int* flagError);
int pTipo_isValidMarca(char* marca);

int pTipo_setFabrica(pTipo* this, char* fabrica);
char* pTipo_getFabrica(pTipo* this,int* flagError);
int pTipo_isValidFabrica(char* fabrica);

int pTipo_setTipoTela(pTipo* this, char* tipoTela);
char* pTipo_getTipoTela(pTipo* this,int* flagError);
int isValidTipoTela(char* tipoTela);
//----------------------------------------------------------------------- SET - GET - IS VALID TXT
int pTipo_setIdTipoTxt(pTipo* this, char* id);
char* pTipo_getIdTipoTxt(pTipo* this, int* flagError);
int pTipo_isValidIdTipoTxt(char* id);

//----------------------------------------------------------------------- BUSCAR
int pTipo_buscarIndiceVacio(pTipo* arrayPunteros[], int limite);
int pTipo_buscarIndicePorId(pTipo* arrayPunteros[], int limite, int id);

//----------------------------------------------------------------------- IMPRIMIR
int pTipo_imprimirUno(pTipo* arrayPunteros[], int indice, int* flagError);
int pTipo_imprimirArray(pTipo* arrayPunteros[], int limite, int* flagError);





#endif /* PTIPO_H_ */
