/*
 * Articulo.c
 *
 *  Created on: 16 jun. 2021
 *      Author: marco
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Articulo.h"
#include "utn.h"
#include "collections/LinkedList.h"

static int contador=0; // NO ES LOCAL DE LA FUNCION

void articulo_setearValorInicialDeId(int id)
{
	contador = id;
}

int articulo_generarId(void)
{
	contador++;
	return contador;
}

Articulo* articulo_new(void)
{
	return (Articulo*) malloc(sizeof(Articulo));
}

Articulo* articulo_newParam(char* codigoArticulo,char* descripcion,char* pais,float valorFob,float peso,float ancho,float altura,float profundidad,char* posicionArancelaria,int idArticulo)
{
	Articulo* auxArticulo = articulo_new();
	if(auxArticulo != NULL)
	{
		if  ( 	articulo_setCodigoArticulo(auxArticulo,codigoArticulo) < 0 ||
				articulo_setDescripcion(auxArticulo,descripcion) < 0 ||
				articulo_setPais(auxArticulo,pais) < 0 ||
				articulo_setValorFob(auxArticulo,valorFob) < 0 ||
				articulo_setPeso(auxArticulo,peso) < 0 ||
				articulo_setAncho(auxArticulo,ancho) < 0 ||
				articulo_setAltura(auxArticulo,altura) < 0 ||
				articulo_setProfundidad(auxArticulo,profundidad) < 0 ||
				articulo_setPosicionArancelaria(auxArticulo,posicionArancelaria) < 0 ||
				articulo_setIdArticulo(auxArticulo,idArticulo) < 0)
		{
			articulo_delete(auxArticulo);
			auxArticulo = NULL;
		}
	}
	return auxArticulo;;
}

int articulo_delete(Articulo* this)
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
int articulo_setCodigoArticulo(Articulo* this, char* CodigoArticulo)
{
	int retorno = -1;
	if(this != NULL && CodigoArticulo != NULL && isValidCodigoArticulo(CodigoArticulo))
	{
		strcpy(this->codigoArticulo,CodigoArticulo);
		retorno = 0;
	}
	return retorno;
}

char* articulo_getCodigoArticulo(Articulo* this,int* flagError)
{
	*flagError = -1;
	char* codigoArticulo= NULL;
	if(this != NULL && flagError != NULL )
	{
		codigoArticulo = this->codigoArticulo;
		*flagError = 0;
	}
	return codigoArticulo;
}

int isValidCodigoArticulo(char* nombre)
{
	return 1;
}
//--------------------------------------Descripcion-------
int articulo_setDescripcion(Articulo* this, char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && isValidDescripcion (descripcion) )
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;
}

char* articulo_getDescripcion (Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxdescripcion= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxdescripcion = this->descripcion;
		*flagError = 0;
	}
	return auxdescripcion;
}


int isValidDescripcion (char* descripcion )
{
	return 1;
}
//-----------------------Pais-------------
int articulo_setPais(Articulo* this, char* pais)
{
	int retorno = -1;
	if(this != NULL && pais!= NULL && isValidPais (pais) )
	{
		strcpy(this->pais,pais);
		retorno = 0;
	}
	return retorno;
}

char* articulo_getPais (Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxpais= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxpais = this->pais;
		*flagError = 0;
	}
	return auxpais;
}

int isValidPais (char* pais)
{
	return 1;
}
//--------------------PosicionArancelaria
int articulo_setPosicionArancelaria(Articulo* this, char* posicionArancelaria)
{
	int retorno = -1;
	if(this != NULL && posicionArancelaria!= NULL && isValidPais (posicionArancelaria) )
	{
		strcpy(this->posicionArancelaria,posicionArancelaria);
		retorno = 0;
	}
	return retorno;
}

char* articulo_getPosicionArancelaria (Articulo* this,int* flagError)
{
	*flagError = -1;
	char* auxposicionArancelaria= NULL;
	if(this != NULL && flagError != NULL )
	{
		auxposicionArancelaria = this->posicionArancelaria;
		*flagError = 0;
	}
	return auxposicionArancelaria;
}

int isValidPosicionArancelaria (char* posicionArancelaria)
{
	return 1;
}

//------------------------ValorFob

int articulo_setValorFob(Articulo* this,float valorFob)
{
	int retorno = -1;
	if(this != NULL && valorFob>0 && isValidValorFob(valorFob) )
	{
		this->valorFob=valorFob;
		retorno = 0;
	}
	return retorno;
}

float articulo_getValorFob(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxValorFob=-1;
	if(this != NULL && flagError != NULL )
	{
		auxValorFob = this->valorFob;
		*flagError = 0;
	}
	return auxValorFob;
}

int isValidValorFob(float valorFob)
{
	return 1;
}
//------------------Peso--------------
int articulo_setPeso(Articulo* this,float peso)
{
	int retorno = -1;
	if(this != NULL && peso>0 && isValidValorPeso(peso))
	{
		this->peso=peso;
		retorno = 0;
	}
	return retorno;
}

float articulo_getPeso(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxPeso= -1;
	if(this != NULL && flagError != NULL )
	{
		auxPeso = this->peso;
		*flagError = 0;
	}
	return auxPeso;
}

int isValidValorPeso(float valorFob)
{
	return 1;
}
//---------------------Ancho--------
int articulo_setAncho(Articulo* this,float ancho)
{
	int retorno = -1;
	if(this != NULL && ancho>0 && isValidAncho(ancho))
	{
		this->ancho=ancho;
		retorno = 0;
	}
	return retorno;
}

float articulo_getAncho(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxAncho= -1;
	if(this != NULL && flagError != NULL )
	{
		auxAncho = this->ancho;
		*flagError = 0;
	}
	return auxAncho;
}

int isValidAncho(float ancho)
{
	return 1;
}

//---------------------Altura--------
int articulo_setAltura(Articulo* this,float altura)
{
	int retorno = -1;
	if(this != NULL && altura>0 && isValidAncho(altura) )
	{
		this->altura=altura;
		retorno = 0;
	}
	return retorno;
}

float articulo_getAltura(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxAltura= -1;
	if(this != NULL && flagError != NULL )
	{
		auxAltura = this->altura;
		*flagError = 0;
	}
	return auxAltura;
}

int isValidValorAltura(float altura)
{
	return 1;
}


//---------------------Profundidad--------
int articulo_setProfundidad(Articulo* this,float profundidad)
{
	int retorno = -1;
	if(this != NULL && profundidad>0 && isValidProfundidad(profundidad))
	{
		this->profundidad=profundidad;
		retorno = 0;
	}
	return retorno;
}

float articulo_getProfundidad(Articulo* this,int* flagError)
{
	*flagError = -1;
	float auxProfundidad= -1;
	if(this != NULL && flagError != NULL )
	{
		auxProfundidad = this->profundidad;
		*flagError = 0;
	}
	return auxProfundidad;
}

int isValidProfundidad(float profundidad)
{
	return 1;
}
//--------------------------ID---------------------

int articulo_setIdArticulo(Articulo* this, int idArticulo)
{
	int retorno = -1;
	if(this != NULL && isValidId(idArticulo) )
	{
		this->idArticulo = idArticulo;
		retorno = 0;
	}
	return retorno;
}

int articulo_getIdAriculo(Articulo* this,int* flagError)
{
	*flagError = -1;
	int auxIdArticulo = -1;
	if(this != NULL && flagError != NULL )
	{
		auxIdArticulo=this->idArticulo;
		*flagError = 0;
	}
	return auxIdArticulo;
}

int isValidId(int idArticulo)
{
	return 1;
}

//--------------------------------ABMC----------------------------------------------------------------------

int articulo_parser(char nombreArchivo[],Dictionary* articulos,int* pIdMaxEncontrado)
{
	FILE* pFile;
	char auxCodigoArticulo[LONG_STRING];
	char auxDescripcion[LONG_STRING];
	char auxPais[LONG_STRING];
	char auxValorFob[LONG_STRING];
	char auxPeso[LONG_STRING];
	char auxAncho[LONG_STRING];
	char auxAltura[LONG_STRING];
	char auxProfundidad[LONG_STRING];
	char auxPosicionArancelaria[LONG_STRING];
	char auxIdArticulo[LONG_STRING];
	float valorFob;
	float peso;
	float ancho;
	float altura;
	float profundidad;
	int idArticulo;
	int flagOnce=0;
	Articulo* pA;
	int indice=-1;
	int idMax;
	pFile = fopen(nombreArchivo,"r");
	if(pFile!=NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxCodigoArticulo,auxDescripcion,auxPais,auxValorFob,auxPeso,auxAncho,auxAltura,auxProfundidad,auxPosicionArancelaria,auxIdArticulo)==10)
			{
				if(flagOnce!=0 && esNumerica(auxValorFob) && esNumerica(auxPeso) && esNumerica(auxAncho) && esNumerica(auxAltura) && esNumerica(auxProfundidad)&& esNumerica(auxIdArticulo))
				{
					valorFob=atof(auxValorFob);
					peso=atof(auxPeso);
					ancho=atof(auxAncho);
					altura=atof(auxAltura);
					profundidad=atof(auxProfundidad);
					idArticulo=atof(auxIdArticulo);
					pA = articulo_newParam(auxCodigoArticulo,auxDescripcion,auxPais,valorFob,peso,ancho,altura,profundidad,auxPosicionArancelaria,idArticulo);
					if(pA!=NULL)
					{
						dict_insert(articulos,auxIdArticulo,pA);
						if(indice==0 || idArticulo>idMax)
						{
							idMax = idArticulo;
						}
						indice++;
					}
				}
			}
			else
			{
				flagOnce=1;
			}
		}
		while(feof(pFile)==0);
		fclose(pFile);
		*pIdMaxEncontrado = idMax; // lo escribo en la var externa
	}
	return indice; // devuelve cantidad leidos
}


int articulos_alta(Dictionary* articulos)
{
	int ret=-1;
	char codigoArticulo[255];
	char descripcion[255];
	char pais[255];
	float valorFob;
	float peso;
	float ancho;
	float altura;
	float profundidad;
	char posicionArancelaria[255];
	int idArticulo;
	Articulo* pA;
	if(utn_getNombre("Ingrese Nombre:","Error!!!! Reingrese Nombre:",auxNombre,3,255)==0 &&
	   utn_getNombre("Ingrese Apellido:","Error!!!! Reingrese Apellido:",auxApellido,3,255)==0 &&
	   utn_getTextoSoloNumeros("Ingrese Sueldo:","Error!!!! Reingrese Sueldo:",auxDni,3,255)==0)
	   {
			idEmp=emp_generarId();
			pE=empleado_newParam(auxNombre,auxApellido,auxDni,idEmp);
			sprintf(auxId,"%d",idEmp);
			if(pE!=NULL)
			{
				dict_insert(empleados, auxId, pE);
				ret=0;
				printf("-------------------------------------ALTA REALIZADA CORRECTAMENTE---------------------------------------\n");
			}
			else
			{
				empleado_delete(pE);
			}
	  }
	return ret;
}



