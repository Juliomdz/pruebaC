/*
 * contratacion.h
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define SIZE_NOMBRE_ARCHIVO 128
#define SIZE_CUIT 12

typedef struct
{
    char cuit[SIZE_CUIT];
    int idPantalla;
    int dias;
    char archivo[SIZE_NOMBRE_ARCHIVO];
    int idContratacion;
    int isEmpty;
}Contratacion;
#include "pantalla.h"
int contratacion_init(Contratacion* array,int limite);
int contratacion_mostrar(Contratacion* array,int limite,Pantalla* arrayPantalla, int limitePantalla);
int contratacion_mostrarDebug(Contratacion* array,int limite);
int contratacion_alta(Contratacion* arrayContratacion,int limite, Pantalla* arrayPantalla, int limitePantallas);
int contratacion_baja(Contratacion* arrayContratacion,int limite);
int contratacion_modificacion(Contratacion* arrayContratacion,int limite);
int contratacion_ordenar(Contratacion* array,int limite, int orden);
int buscarLugarLibre(Contratacion* array,int limite);

int cont_altaForzada(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas,
              int idPantalla,char* archivo,char* cuit,int dias, int indice);

#endif /* CONTRATACION_H_ */
