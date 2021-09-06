/*
 * contratacion.c
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio_ext.h>
#include "contratacion.h"
#include "utn.h"
#include "pantalla.h"

static int contratacion_buscarPorId(Contratacion* array, int limite, int id);
static int contratacion_proximoId();

int contratacion_init(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 1;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int contratacion_mostrarDebug(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %s - %d - %d - %s - %d - %d \n", array[i].cuit, array[i].idPantalla, array[i].dias, array[i].archivo, array[i].idContratacion, array[i].isEmpty);
        }
    }
    return retorno;
}

int contratacion_mostrar(Contratacion* array,int limite, Pantalla* arrayPantalla, int limitePantalla)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("cuit: %s - idpantall: %d - dias: %d - Nombre: %s - IdContrat: %d - %d \n",array[i].cuit, array[i].idPantalla, array[i].dias, array[i].archivo, array[i].idContratacion, array[i].isEmpty);
        }
    }
    return retorno;
}

int contratacion_alta(Contratacion* arrayContratacion,int limite, Pantalla* arrayPantalla, int limitePantallas)
{
    int retorno = -1;
    int i=0;
    int auxiliarIdPantalla = arrayPantalla[i].idPantalla;
    char auxiliarCuit[SIZE_CUIT];
    int auxiliarDias;
    char auxiliarArchivo[SIZE_NOMBRE_ARCHIVO];
    int indiceDarDeAlta;
    for(i=0;i<limitePantallas;i++)
    {
        if(!arrayPantalla[i].isEmpty)
        {
            if(arrayContratacion[i].isEmpty)
                printf("pantallas disponibles, id: %d tipo: %s\n",arrayPantalla[i].idPantalla, arrayPantalla[i].tipo);
        }
    }

    if((limite > 0 && arrayContratacion != NULL) && (limitePantallas > 0 && arrayPantalla != NULL))
    {
        i = buscarLugarLibre(arrayContratacion,limite);
        if(i >= 0)
        {
            if(!utn_getNumero(&indiceDarDeAlta,"ID? ","\nNumero invalido\n",0,999999,2))
            {
                if(indiceDarDeAlta>=0)
                {
                    if(auxiliarIdPantalla>=0)
                    {
                        if(!utn_getCuit(auxiliarCuit,"\ncuit cliente? ", "\neso no es un cuit"))
                        {
                            if(!utn_getNumero(&auxiliarDias,"\ncantidad de dias a contratar ","\ncantidad de dias ingresados no validos",1,365,2))
                            {
                                if(!utn_getText(auxiliarArchivo,"\nnombre archivo? Ej:(Video1) ", "nombre archivo invalido\n",  32,2))
                                {
                                    strcpy(arrayContratacion[auxiliarIdPantalla].cuit,auxiliarCuit);
                                    arrayContratacion[auxiliarIdPantalla].dias=auxiliarDias;
                                    strcpy(arrayContratacion[auxiliarIdPantalla].archivo,auxiliarArchivo);
                                    arrayContratacion[i].isEmpty=0;
                                    arrayContratacion[i].idContratacion = contratacion_proximoId();
                                    arrayContratacion[i].idPantalla = arrayPantalla[auxiliarIdPantalla].idPantalla; // preguntar
                                }
                            }
                        }
                    }
                }
            }

        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

int contratacion_baja(Contratacion* arrayContratacion,int limite)
{
    int retorno = -1;
    int indiceAEliminar;
    int i;
    char auxiliarCuitCliente[SIZE_CUIT];
    int auxiliarIdPantalla;

    utn_getCuit(auxiliarCuitCliente, "Ingrese el CUIT del cliente","CUIT INVALIDO");
    for(i=0; i<limite; i++)
    {
        if(arrayContratacion[i].cuit==auxiliarCuitCliente)
        {
            printf("id pantalla: %d dias de contrato: %d nombre archivo: %s idContrato: %d\n", arrayContratacion[i].idPantalla, arrayContratacion[i].dias, arrayContratacion[i].archivo, arrayContratacion[i].idContratacion);
        }
        else
        {
            printf("el cuit ingresado no tiene contrato de pantallas actualmente\n");
        }
    }
    utn_getNumero(&indiceAEliminar,"ingrese el Id del contrato de la pantalla que desea dar de baja\n", "Id no valido\n",0,999999,2);
    if(indiceAEliminar>=0)
    {
        auxiliarIdPantalla = contratacion_buscarPorId(arrayContratacion, limite, indiceAEliminar);
        if(auxiliarIdPantalla>=0)
        {
            retorno = 0;
            arrayContratacion[indiceAEliminar].isEmpty = 1;
        }
    }

    return retorno;
}

int contratacion_modificacion(Contratacion* arrayContratacion,int limiteContratacion)
{
    int retorno = -1;
    int auxiliarIdPantalla;
    int auxiliarDias;
    char auxiliarArchivo[SIZE_NOMBRE_ARCHIVO];
    int indiceAModificar;
    int i;
    char auxiliarCuitCliente[SIZE_CUIT];
    utn_getCuit(auxiliarCuitCliente,"ingrese el cuit del cliente\n", "CUIT INVALIDO");
    for(i=0; i<limiteContratacion; i++)
    {
        if(arrayContratacion[i].cuit==auxiliarCuitCliente)
        {
            printf("id pantalla: %d dias de contrato: %d nombre archivo: %s idContrato: %d\n", arrayContratacion[i].idPantalla, arrayContratacion[i].dias, arrayContratacion[i].archivo, arrayContratacion[i].idContratacion);
            /*printf("ingrese el id de la pantalla a modificar");
            scanf("%d", &indiceAModificar);*/
        }
        else
        {
            printf("el cuit ingresado no tiene contrato de pantallas actualmente\n");
        }
    }
    utn_getNumero(&indiceAModificar,"ID pantalla?","\nNumero invalido\n",0,999999,2);
    if(indiceAModificar>=0)
    {
        auxiliarIdPantalla = contratacion_buscarPorId(arrayContratacion, limiteContratacion, indiceAModificar);
        if(auxiliarIdPantalla>=0)
        {
            if(!utn_getNumero(&auxiliarDias,"\ncantidad de dias a contratar","\ncantidad de dias ingresados no validos",1,365,2))
            {
                if(!utn_getText(auxiliarArchivo,"\nnombre archivo? Ej:(Video1)", "nombre archivo invalido", 32,2))
                {
                    arrayContratacion[auxiliarIdPantalla].dias=auxiliarDias;
                    strcpy(arrayContratacion[auxiliarIdPantalla].archivo,auxiliarArchivo);
                    //arrayContratacion[i].isEmpty=0;
                    //arrayContratacion[i].idContratacion = contratacion_proximoId();
                }
            }
        }
        else
        {
            retorno = -3;
        }
        retorno = 0;
    }
    return retorno;
}

int buscarLugarLibre(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int contratacion_buscarPorId(Contratacion* array, int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int contratacion_proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int cont_altaForzada(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas,
              int idPantalla,char* archivo,char* cuit,int dias, int indice)
{
    int retorno = -1;

     if(limite > 0 && arrayC != NULL && indice >= 0)
        {
            if(pantallas[idPantalla].isEmpty ==1)
            {
                arrayC[indice].dias = dias;
                strncpy(arrayC[indice].cuit,cuit,SIZE_CUIT);
                strncpy(arrayC[indice].archivo,archivo,SIZE_NOMBRE_ARCHIVO);
                //
                arrayC[indice].idPantalla = idPantalla; // relacion
                arrayC[indice].isEmpty=0;
                arrayC[indice].idContratacion = contratacion_proximoId();
            }
            retorno = 0;
        }

    return retorno;
}
