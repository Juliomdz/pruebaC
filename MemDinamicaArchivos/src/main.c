/*
 ============================================================================
 Name        : MemDinamicaArchivos.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pProducto.h"
#include "pNacionalidad.h"
#include "pTipo.h"
#include "informe.h"
#include "utn.h"

#define CANT_PRODUCTOS 1000
#define CANT_NACIO 50
#define CANT_TIPO 200

int main(void)
{
  int opcionMenu;
  pProducto* arrayProductos [CANT_PRODUCTOS]; // PRODUCTO
  pNacionalidad* arrayNacionalidad [CANT_NACIO]; // NACIONALIDAD
  pTipo* arrayTipo [CANT_TIPO]; // TIPO
  int idProducto = 0;
  int flagError;
  //-------------- ARCHIVOS
  FILE *pFile;
  pProducto* bufferProducto = NULL;
  pNacionalidad* bufferNacionalidad = NULL;
  pTipo* bufferTipo = NULL;
  int index;
  char idProductoTxt[IDINT_LEN];
  char descripcionTxt[DESCIPCION_LEN];
  char idNacionalidadTxt[IDINT_LEN];
  char idTipoTxt[IDINT_LEN];
  char precioPorUnidadTxt[IDINT_LEN];
  //--------------------
  char marcaTxt[MARCA_LEN];
  char fabricaTxt[FABRICA_LEN];
  char tipoTelaTxt[TIPOTELA_LEN];

  if(!pProducto_initArray(arrayProductos, CANT_PRODUCTOS) &&
     !pNacionalidad_initArray(arrayNacionalidad, CANT_NACIO) &&
     !pTipo_initArray(arrayTipo, CANT_TIPO))
  {
    printf("\n* INIT ARRAY PRODUCTO OK.\n");
    printf("* INIT ARRAY NACIONALIDAD OK.\n");
    printf("* INIT ARRAY TIPO OK.\n");
    //**************************************************************************************************************
    /*if(pProducto_agregarAlArray(arrayProductos, CANT_PRODUCTOS, idProducto+1, "Remera ",  12, 22, 5500)   >= 0 &&
       pProducto_agregarAlArray(arrayProductos, CANT_PRODUCTOS, idProducto+2, "Short ",   11, 21, 4500)   >= 0 &&
       pProducto_agregarAlArray(arrayProductos, CANT_PRODUCTOS, idProducto+3, "Buzo ",    12, 22, 22000)  >= 0 &&
       pProducto_agregarAlArray(arrayProductos, CANT_PRODUCTOS, idProducto+4, "Campera ", 13, 23, 105000) >= 0 &&
       pProducto_agregarAlArray(arrayProductos, CANT_PRODUCTOS, idProducto+5, "Jean ",    13, 23, 55000)  >= 0)
    {
       printf("\n* ALTA FORZADA ARRAY PRODUCTO OK.\n");
       if(pNacionalidad_agregarAlArray(arrayNacionalidad, CANT_NACIO, 11, "Argentina")      >= 0 &&
          pNacionalidad_agregarAlArray(arrayNacionalidad, CANT_NACIO, 12, "Estados Unidos") >= 0 &&
          pNacionalidad_agregarAlArray(arrayNacionalidad, CANT_NACIO, 13, "Italia")         >= 0)
       {
         printf("* ALTA FORZADA ARRAY NACIONALIDAD OK.\n");
         if(pTipo_agregarAlArray(arrayTipo, CANT_TIPO, 21, "Nike",   "Fabrica Puma", "Lana")          >= 0 &&
          pTipo_agregarAlArray(arrayTipo, CANT_TIPO, 22, "Tommy Hilfiger", "Fabrica Tommy", "Jean") >= 0 &&
            pTipo_agregarAlArray(arrayTipo, CANT_TIPO, 23, "Versace",   "Fabrica Versace", "Lino")    >= 0 )
         {
           printf("* ALTA FORZADA ARRAY TIPO OK.\n");
           printf("* - - - - - - - - - - - - - - - - - - - - - - - - - - - - *\n");
         }
       }
    }*/
    //**************************************************************************************************************
    /*pFile = fopen("archivoTipo.csv","w");
    if(pFile == NULL)
    {
      printf("\nNo se encontró archivo.");
    }
    else
    {
      for(i=0; i<3; i++)
      {
        fprintf(pFile, "%d,%s,%s,%s\n",idTipo+i+1, "Nike", "Fabrica", "Alogon");
      }
    }
    fclose(pFile);*/

    pFile = fopen("archivo.csv","r");
    if(pFile == NULL)
    {
      printf("\nNo se encontró archivo.");
    }
    else
    {
      index = 0;
      do
      {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",   idProductoTxt,
                                   descripcionTxt,
                                   idNacionalidadTxt,
                                   idTipoTxt,
                                   precioPorUnidadTxt) == 5)
        {
          printf("\n");
          printf("%s - %s - %s - %s - %s ",  idProductoTxt,
                             descripcionTxt,
                             idNacionalidadTxt,
                             idTipoTxt,
                             precioPorUnidadTxt);

          bufferProducto = pProducto_newConParametrosTxt(idProductoTxt,
                                   descripcionTxt,
                                   idNacionalidadTxt,
                                   idTipoTxt,
                                   precioPorUnidadTxt);
          if(bufferProducto != NULL)
          {
            arrayProductos[index] = bufferProducto;
            index++;
          }
        }
        else
        {
          break;
        }
      }while(!feof(pFile)); // hasta que sea 0 corta
    }
    fclose(pFile);
    //************************************************ PRODUCTO
    printf("\n");
    pFile = fopen("archivoNacionalidad.csv","r");
    if(pFile == NULL)
    {
      printf("\nNo se encontró archivo.");
    }
    else
    {
      index = 0;
      do
      {
        if(fscanf(pFile,"%[^,],%[^\n]\n", idNacionalidadTxt,
                                      descripcionTxt) == 2)
        {
          printf("\n");
          printf("%s - %s  ",  idNacionalidadTxt,
                     descripcionTxt);

          bufferNacionalidad = pNacionalidad_newConParametrosTxt(idNacionalidadTxt,
                                       descripcionTxt);
          if(bufferNacionalidad != NULL)
          {
            arrayNacionalidad[index] = bufferNacionalidad;
            index++;
          }
        }
        else
        {
          break;
        }
      }while(!feof(pFile)); // hasta que sea 0 corta
    }
    fclose(pFile);
    //************************************************ NACIONALIDAD
    printf("\n");
    pFile = fopen("archivoTipo.csv","r");
    if(pFile == NULL)
    {
      printf("\nNo se encontró archivo.");
    }
    else
    {
      index = 0;
      do
      {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idTipoTxt,
                                marcaTxt,
                                fabricaTxt,
                                tipoTelaTxt) == 4)
        {
          printf("\n");
          printf("%s - %s - %s - %s ", idTipoTxt,
                         marcaTxt,
                         fabricaTxt,
                           tipoTelaTxt);
          bufferTipo = pTipo_newConParametrosTxt(    idTipoTxt,
                                 marcaTxt,
                                 fabricaTxt,
                                 tipoTelaTxt);
          if(bufferTipo != NULL)
          {
            arrayTipo[index] = bufferTipo;
            index++;
          }
        }
        else
        {
          break;
        }
      }while(!feof(pFile)); // hasta que sea 0 corta
    }
    fclose(pFile);
    //**************************************************************************************************************
    do
    {
      if(!utn_getNumero(&opcionMenu,
              "\n"
              "\n* ============ \x1b[93m\x1b[44mMENU PRINCIPAL\x1b[0m\x1b[0m ============ *"
              "\n| ======================================== |"
              "\n|  1 - Alta                                |"
              "\n|  2 - Baja                                |"
              "\n|  3 - Modificacion                        |"
              "\n|  4 - LISTADO productos                   |"
              "\n|  5 - LISTADO ordenado por Precio         |"
              "\n|  6 - LISTADO ordenado por Descripción    |"
              "\n|  7 - Salir                               |"
              "\n* ---------------------------------------- *"
              "\n - Opcion >  "
              "",
              "\n  * ERROR *"
              "\n Opcion invalida\n", 1, 7, 999))
      {
        switch(opcionMenu)
        {
          case 1: // ALTA
            if(!informe_altaArrayPunterosProducto(arrayProductos, CANT_PRODUCTOS, &idProducto,
                                arrayNacionalidad, CANT_NACIO,
                                arrayTipo, CANT_TIPO))
              printf("\n * Producto dado de alta con exito");
            else
              printf("\n * No pudimos dar de alta su producto");
          break;
          case 2: // BAJA
            if(!pProducto_borrarIndicePorId(arrayProductos, CANT_PRODUCTOS))
              printf("\n * Producto dado de baja con exito");
            else
              printf("\n * No pudimos dar de baja su producto");
          break;
          case 3: // MODIFICACION
            if(!informe_menuModificarProducto(arrayProductos, CANT_PRODUCTOS,
                              arrayNacionalidad, CANT_NACIO,
                              arrayTipo, CANT_TIPO))
              printf("\n * Modificacion del producto ok ");
            else
              printf("\n * No pudimos modificar su producto");
          break;
          case 4: // LISTADO Productos.
            informe_imprimirProductos(arrayProductos, CANT_PRODUCTOS,
                                  arrayNacionalidad, CANT_NACIO,
                          arrayTipo, CANT_TIPO, &flagError);
            if(flagError == -1)
              printf("\n * Ocurrio un error al mostrar la lista de productos, intente mas tarde");
          break;
          case 5: // LISTADO ordenado por Precio
            if(!pProducto_ordenarPorPrecioUnidad(arrayProductos, CANT_PRODUCTOS))
            {
              printf("\n \x1b[93m\x1b[44m**--- ORDENADO POR PRECIO UNITARIO (+ a -) ---**\x1b[0m\x1b[0m");

              informe_imprimirProductos(arrayProductos, CANT_PRODUCTOS,
                            arrayNacionalidad, CANT_NACIO,
                            arrayTipo, CANT_TIPO, &flagError);
            }
          break;
          case 6: // LISTADO ordenado por Descripción
            if(!pProducto_ordenarPorDescripcion(arrayProductos, CANT_PRODUCTOS))
            {
              printf("\n \x1b[93m\x1b[44m**--- ORDENADO POR DESCRIPCION (A - Z) ---**\x1b[0m\x1b[0m");

              informe_imprimirProductos(arrayProductos, CANT_PRODUCTOS,
                              arrayNacionalidad, CANT_NACIO,
                              arrayTipo, CANT_TIPO, &flagError);
            }
          break;
        }
      }
    }while(opcionMenu != 7);
    //**************************************************************************************************************
  }
  return EXIT_SUCCESS;
}



