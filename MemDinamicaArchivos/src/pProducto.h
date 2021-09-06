/*
 * pProducto.h
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */

#ifndef PPRODUCTO_H_
#define PPRODUCTO_H_


#define DESCIPCION_LEN 50
#define NACIONALIDAD_LEN 50
#define IDINT_LEN 10
#define PRECIOFLOAT_LEN 10

typedef struct
{
  int idProducto;
  char descripcion[DESCIPCION_LEN];
  int idNacionalidad;
  int idTipo;
  float precioPorUnidad;

}pProducto;
//----------------------------------------------------------------------- CREAR
pProducto* pProducto_new(void);

//----------------------------------------------------------------------- NEW CON PARAMETROS
pProducto* pProducto_newConParametros(int idProducto, char* descripcion,
                int idNacionalidad, int idTipo, float precioPorUnidad);

//----------------------------------------------------------------------- NEW CON PARAMETROS TXT
pProducto* pProducto_newConParametrosTxt(char* idProducto, char* descripcion,
                char* idNacionalidad, char* idTipo, char* precioPorUnidad);


int pProducto_agregarAlArray(pProducto* arrayPunteros[], int limite, int idProducto, char* descripcion,
                                                                 int idNacionalidad, int idTipo, float precioPorUnidad);

//----------------------------------------------------------------------- ELIMINAR
int pProducto_delete(pProducto* this);
int pProducto_eliminarIndiceArray(pProducto* arrayPunteros[], int limite,int indiceEliminar);
int pProducto_borrarIndicePorId(pProducto* arrayPunteros[], int limite);

//----------------------------------------------------------------------- SET - GET - ISVALID
int pProducto_setDescripcion(pProducto* this, char* descripcion);
char* pProducto_getDescripcion(pProducto* this, int* flagError);
int pProducto_isValidDescripcion(char* descripcion);

int pProducto_setIdProducto(pProducto* this, int id);
int pProducto_getIdProducto(pProducto* this, int* flagError);
int pProducto_isValidIdProducto(int id);

int pProducto_setIdNacionalidad(pProducto* this, int id);
int pProducto_getIdNacionalidad(pProducto* this, int* flagError);
int pProducto_isValidIdNacionalidad(int id);

int pProducto_setIdTipo(pProducto* this, int id);
int pProducto_getIdTipo(pProducto* this, int* flagError);
int pProducto_isValidIdTipo(int id);

int pProducto_setPrecioPorUnidad(pProducto* this, float precioPorUnidad);
float pProducto_getPrecioPorUnidad(pProducto* this, int* flagError);
int pProducto_isValidPrecioPorUnidad(float precio);
//----------------------------------------------------------------------- SET - GET - ISVALID TXT
int pProducto_setIdProductoTxt(pProducto* this, char* id);
char* pProducto_getIdProductoTxt(pProducto* this, int* flagError);
int pProducto_isValidIdProductoTxt(char* id);

int pProducto_setIdNacionalidadTxt(pProducto* this, char* id);
char* pProducto_getIdNacionalidadTxt(pProducto* this, int* flagError);
int pProducto_isValidIdNacionalidadTxt(char* id);

int pProducto_setIdTipoTxt(pProducto* this, char* id);
char* pProducto_getIdTipoTxt(pProducto* this, int* flagError);
int pProducto_isValidIdTipoTxt(char* id);

int pProducto_setPrecioPorUnidadTxt(pProducto* this, char* precioPorUnidad);
char* pProducto_getPrecioPorUnidadTxt(pProducto* this, int* flagError);
int pProducto_isValidPrecioPorUnidadTxt(char* precio);

//----------------------------------------------------------------------- INIT ARRAY
int pProducto_initArray(pProducto* arrayPunteros[], int limite);

//----------------------------------------------------------------------- BUSCAR
int pProducto_buscarIndiceVacio(pProducto* arrayPunteros[], int limite);
int pProducto_buscarIndicePorId(pProducto* arrayPunteros[], int limite, int id);

//----------------------------------------------------------------------- IMPRIMIR
int pProducto_imprimirUno(pProducto* arrayPunteros[], int indice, int* flagError);
int pProducto_imprimirArray(pProducto* arrayPunteros[], int limite, int* flagError);

//----------------------------------------------------------------------- OBTENER CADENA POR OPCION
int pProducto_obtenerCadenaPorOpcionNacionalidad(int opcion,int cadenaLen ,char* opcionCadenaObtenida);

//---------------------------------------------------- ORDENAR POR PRECIO, MAYOR A MENOR
int pProducto_ordenarPorPrecioUnidad(pProducto* arrayPunteros[], int limite);

//----------------------------------------------------  ORDENAR POR DESCRIPCION, A - Z
int pProducto_ordenarPorDescripcion(pProducto* arrayPunteros[], int limite);



#endif /* PPRODUCTO_H_ */
