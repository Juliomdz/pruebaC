/*
 * PosicionArancelaria.c
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "PosicionArancelaria.h"

PosicionArancelaria* posArancel_new(void)
{
	return (PosicionArancelaria*) malloc(sizeof(PosicionArancelaria));
}

PosicionArancelaria* posArancel_newParam(char* posicionArancelaria,float seguro,float importacion,float tasaEstadistica,int tipoDeLicencia)
{
	PosicionArancelaria* auxPoscAranc = posArancel_new();
	if(auxPoscAranc != NULL)
	{
		if  ( 	posArancel_setPosicionArancelaria(auxPoscAranc,posicionArancelaria) < 0 ||
				posArancel_setSeguro(auxPoscAranc,seguro) < 0 ||
				posArancel_setImportacion(auxPoscAranc,importacion) < 0 ||
				posArancel_setTasaEstadistica(auxPoscAranc,tasaEstadistica) < 0 ||
				posArancel_setTipoDeLicencia(auxPoscAranc,tipoDeLicencia) < 0 )
		{
			posArancel_delete(auxPoscAranc);
			auxPoscAranc = NULL;
		}
	}
	return auxPoscAranc;;
}

int posArancel_delete(PosicionArancelaria* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}
//-------------------------------------CodigoArticulo--------------------------------
int posArancel_setPosicionArancelaria(PosicionArancelaria* this, char* posicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && posicionArancelaria != NULL && isValidPosicionArancel(posicionArancelaria))
	{
		strcpy(this->posicionArancelaria,posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}

char* posArancel_getPosicionArancelaria(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	char* auxPosicionArancelaria= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxPosicionArancelaria = this->posicionArancelaria;
		*flagError = 0;
	}
	return auxPosicionArancelaria;
}

int isValidPosicionArancel(char* posicionArancelaria)
{
	return 1;
}

//------------------------Seguro

int posArancel_setSeguro(PosicionArancelaria* this,float seguro)
{
	int retorno = -1;
	if(this != NULL && seguro>0 && isValidSeguro(seguro) )
	{
		this->seguro=seguro;
		retorno = 0;
	}
	return retorno;
}

float posArancel_getSeguro(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxseguro= -1;
	if(this != NULL && flagError != NULL )
	{
		auxseguro = this->seguro;
		*flagError = 0;
	}
	return auxseguro;
}

int isValidSeguro(float auxseguro)
{
	return 1;
}

//------------------------importacion

int posArancel_setImportacion(PosicionArancelaria* this,float importacion)
{
	int retorno = -1;
	if(this != NULL && importacion>0 && isValidImportacion(importacion) )
	{
		this->importacion=importacion;
		retorno = 0;
	}
	return retorno;
}

float posArancel_getImportacion(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxImportacion= -1;
	if(this != NULL && flagError != NULL )
	{
		auxImportacion = this->importacion;
		*flagError = 0;
	}
	return auxImportacion;
}

int isValidImportacion(float importacion)
{
	return 1;
}

//------------------------tasaEstadistica

int posArancel_setTasaEstadistica(PosicionArancelaria* this,int tasaEstadistica)
{
	int retorno = -1;
	if(this != NULL && tasaEstadistica>0 && isValidTasaEstadistica(tasaEstadistica) )
	{
		this->tasaEstadistica=tasaEstadistica;
		retorno = 0;
	}
	return retorno;
}

float posArancel_getTasaEstadistica(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	float auxTasaEstadistica= -1;
	if(this != NULL && flagError != NULL )
	{
		auxTasaEstadistica = this->tasaEstadistica;
		*flagError = 0;
	}
	return auxTasaEstadistica;
}

int isValidTasaEstadistica(float tasaEstadistica)
{
	return 1;
}

//--------------------------tipoDeLicencia---------------------

int posArancel_setTipoDeLicencia(PosicionArancelaria* this, int tipoDeLicencia)
{
	int retorno = -1;
	if(this != NULL && isValidTipoDeLicencia(tipoDeLicencia) )
	{
		this->tipoDeLicencia = tipoDeLicencia;
		retorno = 0;
	}
	return retorno;
}

int posArancel_getTipoDeLicencia(PosicionArancelaria* this,int* flagError)
{
	*flagError = -1;
	int auxTipoDeLicencia = -1;
	if(this != NULL && flagError != NULL )
	{
		auxTipoDeLicencia=this->tipoDeLicencia;
		*flagError = 0;
	}
	return auxTipoDeLicencia;
}
int isValidTipoDeLicencia(int tipoDeLicencia)
{
	return 1;
}
//------------------------------------------------------------------------

int posArancel_parser(char nombreArchivo[],Dictionary* posicionesArancel)
{
	FILE* pFile;
	char posicionArancelaria[LONG_STRING];
	char seguro[LONG_STRING];//float
	char importacion[LONG_STRING];//float
	char tasaEstadistica[LONG_STRING];//float
	char tipoDeLicencia[LONG_STRING];
	float seguroAux;
	float importacionAux;
	float tasaEstadisticaAux;
	int tipoDeLicenciaAux;
	int flagOnce=0;
	PosicionArancelaria* pPosA;
	int indice=-1;
	pFile = fopen(nombreArchivo,"r");
	if(pFile!=NULL)
	{
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",posicionArancelaria,seguro,importacion,tasaEstadistica,tipoDeLicencia)==5)
			{
				if(flagOnce!=0 && esNumerica(seguro)==0 && esNumerica(importacion)==0 && esNumerica(tasaEstadistica)==0 && esNumerica(tipoDeLicencia)==0)
				{
					seguroAux=atof(seguro);
					importacionAux=atof(importacion);
					tasaEstadisticaAux=atof(tasaEstadistica);
					tipoDeLicenciaAux=atof(tipoDeLicencia);
					pPosA = posArancel_newParam(posicionArancelaria,seguroAux,importacionAux,tasaEstadisticaAux,tipoDeLicenciaAux);
					if(pPosA!=NULL)
					{
						dict_insert(posicionesArancel,posicionArancelaria,pPosA);
					}
					indice++;
				}
			}
			else
			{
				flagOnce=1;
			}
		}
		while(feof(pFile)==0);
		fclose(pFile);
	}
	return indice;//cantidad de leidos
}
