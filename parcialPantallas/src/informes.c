/*
 * informes.c
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informes.h"

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].cuit==cuit)
            {
                indexPantalla = pantalla_isEmptyIndice(&pantallas[i]);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precioPorDia,
                                    (arrayC[i].dias * pantallas[indexPantalla].precioPorDia),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}
int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_isEmptyIndice(&pantallas[i]);
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias);
                }


        }

        retorno = 0;
    }
    return retorno;
}

