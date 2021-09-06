/*
 ============================================================================
 Name        : ParcialLab_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "PosicionArancelaria.h"
#include "Articulo.h"
#include "collections/LinkedList.h"

#define TXT_MENU "MENU\n1)Leer archivos de Articulos y Posicion ArancelariaCSV\n2)Listar empleados\n3)Alta empleado\n4)Modificar\n5)Baja\n6)Escribir archivo CSV\n7)Salir\n"

#define OP_LEER			1
#define OP_LISTAR		2
#define OP_ALTA			3
#define OP_MODIF		4
#define OP_BAJA			5
#define OP_ESCRIBIR		6
#define OP_SALIR		7


int main(void) {
	setbuf(stdout,NULL);
	Dictionary* articulos;
	Dictionary* posicionArancel;
	int opcion;
	int idMax=-1;
	articulos = dict_new(0);
	posicionArancel= dict_new(0);
	do{
		if(utn_getEntero(TXT_MENU,"Error",&opcion,3,7,0)==0)
		{
			switch(opcion)
			{
				case OP_LEER:
				{
					articulo_parser("Articulo.csv",articulos,&idMax);
					posArancel_parser("PosicionArancelaria.csv",posicionArancel);
					articulo_setearValorInicialDeId(idMax);
					break;
				}
				case OP_LISTAR:
				{
					//emp_imprimirLista(empleados);
					break;
				}
				case OP_ALTA:
				{
					articulo_alta(articulos);
					break;
				}
				case OP_MODIF:
				{
					//emp_modificar(empleados);
					break;
				}
				case OP_BAJA:
				{
					//emp_borrar(empleados);
					break;
				}
				case OP_ESCRIBIR:
				{
					//emp_dump("empleados_out.csv",empleados);
					break;
				}
			}
		}
	}while(opcion!=OP_SALIR);
	return EXIT_SUCCESS;
}

