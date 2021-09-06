/*
 ============================================================================
 Name        : parcialPantallas.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "utn.h"
#include "contratacion.h"
#include "informes.h"
#define SIZE_ARRAY_PANTALLAS 100
#define SIZE_ARRAY_CONTRATACIONES 1000

int main()
{
    Pantalla arrayPantallas[SIZE_ARRAY_PANTALLAS];
    Contratacion arrayContrataciones[SIZE_ARRAY_CONTRATACIONES];
    int menu ;
    int auxiliarId;
    int idPantalla=0;
    int auxiliarIndice=0;

    if(pantalla_init(arrayPantallas,SIZE_ARRAY_PANTALLAS))
      {
        printf("Array de Pantallas inicializado correctamente");
      }

    if(contratacion_init(arrayContrataciones, SIZE_ARRAY_CONTRATACIONES))
      {
        printf("Array de Contrataciones inicializado correctamente");
      }


    pantalla_altaForzada(arrayPantallas,SIZE_ARRAY_PANTALLAS,"Caballito","San Martin 50",50,"0",0,&idPantalla);
    pantalla_altaForzada(arrayPantallas,SIZE_ARRAY_PANTALLAS,"La Boca","Billinghurst 250",2000,"0",1,&idPantalla);
    pantalla_altaForzada(arrayPantallas,SIZE_ARRAY_PANTALLAS,"San Telmo","Cerrito 300",3000,"0",2,&idPantalla);
    pantalla_altaForzada(arrayPantallas,SIZE_ARRAY_PANTALLAS,"Nuñez","Libertador 3000",1000,"1",3,&idPantalla);
    pantalla_altaForzada(arrayPantallas,SIZE_ARRAY_PANTALLAS,"Palermo","Cabildo 1500",5000,"1",4,&idPantalla);


    cont_altaForzada(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS,0,"video.avi","20911911915",100,0);
    cont_altaForzada(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS,1,"video1.avi","20911911915",400,1);
    cont_altaForzada(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS,2,"video2.avi","30911911915",300,2);
    cont_altaForzada(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS,3,"video3.avi","30911911915",400,3);
    cont_altaForzada(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS,4,"video4.avi","40911911915",500,4);

    informar_ConsultaFacturacion(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS,"20911911915");
    informar_ListarContrataciones(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas,SIZE_ARRAY_PANTALLAS);


    do
    {
        if(utn_getNumero(&menu,"1.Alta Pantallas"
                         "\n2.Baja Pantallas"
                         "\n3.Modificar Pantallas"
                         "\n4.Mostrar Pantallas"
                         "\n5.Ordenar Pantallas"
                         "\n6.Mostrar Debug pantallas"
                         "\n7.Contratar Publicidad"
                         "\n8.Baja publicidad"
                         "\n9.Modificar Publicidad"
                         "\n10.Mostrar Contrataciones"
                         "\n11.mostrar debug contrataciones"
                         "\n12.Salir\n","\nNo valida\n",1,12,1))
          {
            switch(menu)
            {
            case 1:
                if(pantalla_buscarLugarLibre(arrayPantallas,&auxiliarIndice,SIZE_ARRAY_PANTALLAS))
                  {
                    if(pantalla_alta(arrayPantallas,SIZE_ARRAY_PANTALLAS,auxiliarIndice, &idPantalla))
                      {
                      printf("\nPantalla dada de alta con exito.");
                      }
                  }
                break;
            case 2:
              utn_getNumero(&auxiliarId,"ID?","\nNumero valida\n",0,200,2);
                pantalla_baja(arrayPantallas,SIZE_ARRAY_PANTALLAS,auxiliarId);
                break;
            case 3:
              utn_getNumero(&auxiliarId,"ID?","\nNumero valida\n",0,200,2);
                pantalla_modificacion(arrayPantallas,SIZE_ARRAY_PANTALLAS,auxiliarId);
                break;
            case 4:
                pantalla_imprimirArray(arrayPantallas,SIZE_ARRAY_PANTALLAS);
                break;
            case 5:
                pantalla_ordenarNombre(arrayPantallas,SIZE_ARRAY_PANTALLAS);
                break;
            case 6:
                pantalla_mostrarDebug(arrayPantallas,SIZE_ARRAY_PANTALLAS);
                break;
            case 7:
                contratacion_alta(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES,arrayPantallas, SIZE_ARRAY_PANTALLAS);
                break;
            case 8:
                contratacion_baja(arrayContrataciones,SIZE_ARRAY_CONTRATACIONES);
                break;
            case 9:
                contratacion_modificacion(arrayContrataciones, SIZE_ARRAY_CONTRATACIONES);
                break;
            case 10:
                contratacion_mostrar(arrayContrataciones, SIZE_ARRAY_CONTRATACIONES, arrayPantallas,SIZE_ARRAY_PANTALLAS);
                break;
            case 11:
                contratacion_mostrarDebug(arrayContrataciones, SIZE_ARRAY_CONTRATACIONES);
                break;
            }
          }

    }while(menu != 12);

    return 0;
}
