/*
 * Articulo.h
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#define LONG_STRING 255

typedef struct
{
	char codigoArticulo[LONG_STRING];
	char descripcion[LONG_STRING];
	char pais[LONG_STRING];
	float valorFob;
	float peso;
	float ancho;
	float altura;
	float profundidad;
	char posicionArancelaria[LONG_STRING];
	int idArticulo;
}Articulo;

#endif /* ARTICULO_H_ */

Articulo* articulo_new();
Articulo* articulo_newParam(char* codigoArticulo,char* descripcion,char* pais,float valorFob,float peso,float ancho,float altura,float profundidad,char* posicionArancelaria,int idAriculo);
//-------------------------GET & SET
void articulo_setearValorInicialDeId(int id);

int articulo_delete(Articulo* this);
int articulo_setCodigoArticulo(Articulo* this, char* CodigoArticulo);
char* articulo_getCodigoArticulo(Articulo* this,int* flagError);
int isValidCodigoArticulo(char* nombre);
int articulo_setDescripcion(Articulo* this, char* descripcion);
char* articulo_getDescripcion (Articulo* this,int* flagError);
int isValidDescripcion (char* descripcion );
int articulo_setPais(Articulo* this, char* pais);
char* articulo_getPais (Articulo* this,int* flagError);
int isValidPais (char* pais);
int articulo_setPosicionArancelaria(Articulo* this, char* posicionArancelaria);
char* articulo_getPosicionArancelaria (Articulo* this,int* flagError);
int isValidPosicionArancelaria (char* posicionArancelaria);
int articulo_setValorFob(Articulo* this,float valorFob);
float articulo_getValorFob(Articulo* this,int* flagError);
int isValidValorFob(float valorFob);
int articulo_setPeso(Articulo* this,float peso);
float articulo_getPeso(Articulo* this,int* flagError);
int isValidValorPeso(float valorFob);
int articulo_setAncho(Articulo* this,float ancho);
float articulo_getAncho(Articulo* this,int* flagError);
int isValidAncho(float ancho);
int articulo_setAltura(Articulo* this,float altura);
float articulo_getAltura(Articulo* this,int* flagError);
int isValidValorAltura(float altura);
int articulo_setProfundidad(Articulo* this,float profundidad);
float articulo_getProfundidad(Articulo* this,int* flagError);
int isValidProfundidad(float profundidad);
int articulo_setIdArticulo(Articulo* this, int idArticulo);
int articulo_getIdAriculo(Articulo* this,int* flagError);
int isValidId(int idArticulo);

//------------------------------ABMC-------------------------------------

#include "collections/Dictionary.h"

int articulo_parser(char nombreArchivo[],Dictionary* articulos,int* pIdMaxEncontrado);
