/*
 ============================================================================
 Name        : PruebaEstructuras.c
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
#include "producto.h"
#include "utn.h"
#define SIZE_PRODUCTOS 100

int main(void) {
  char auxDescription[SIZE_DESCRIPTION_PROD];
  int IdProduct=0;
  Producto arrayProductos[SIZE_PRODUCTOS];

	printf("holis"); /* prints  */
utn_getText(auxDescription, "Ingrese la descripción del producto.", "Eso no es una descripcion valida.", SIZE_DESCRIPTION_PROD, 3);
arrayProductos[0](producto_newParam(auxDescription,&IdProduct));
printf("\n %s %d",arrayProductos[0].description, arrayProductos[0].idProduct);
	return EXIT_SUCCESS;
}
