/*
 * PosicionArancelaria.h
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */

#ifndef POSICIONARANCELARIA_H_
#define POSICIONARANCELARIA_H_
#define LONG_STRING 255

typedef struct
{
	char posicionArancelaria[LONG_STRING];
	float seguro;
	float importacion;
	float tasaEstadistica;
	int tipoDeLicencia;
}PosicionArancelaria;


PosicionArancelaria* posArancel_new();
PosicionArancelaria* posArancel_newParam(char* posicionArancelaria,float seguro,float importacion,float tasaEstadistica,int tipoDeLicencia);
int posArancel_delete(PosicionArancelaria* this);
int posArancel_setPosicionArancelaria(PosicionArancelaria* this, char* posicionArancelaria);
char* posArancel_getPosicionArancelaria(PosicionArancelaria* this,int* flagError);
int isValidPosicionArancel(char* posicionArancelaria);
int posArancel_setSeguro(PosicionArancelaria* this,float seguro);
float posArancel_getSeguro(PosicionArancelaria* this,int* flagError);
int isValidSeguro(float auxseguro);
int posArancel_setImportacion(PosicionArancelaria* this,float importacion);
float posArancel_getImportacion(PosicionArancelaria* this,int* flagError);
int isValidImportacion(float importacion);
int posArancel_setTasaEstadistica(PosicionArancelaria* this,int tasaEstadistica);
float posArancel_getTasaEstadistica(PosicionArancelaria* this,int* flagError);
int isValidTasaEstadistica(float tasaEstadistica);
int posArancel_setTipoDeLicencia(PosicionArancelaria* this, int tipoDeLicencia);
int posArancel_getTipoDeLicencia(PosicionArancelaria* this,int* flagError);
int isValidTipoDeLicencia(int tipoDeLicencia);
//---------------------------------------------------------
#include "collections/Dictionary.h"

int posArancel_parser(char nombreArchivo[],Dictionary* posicionesArancel);

#endif /* POSICIONARANCELARIA_H_ */
