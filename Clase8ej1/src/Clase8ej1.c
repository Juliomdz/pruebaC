/*
 ============================================================================
 Name        : Clase8ej1.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "arr.h"
#include "utn.h"

#define QTY_PERSONAS 5

typedef struct
{
  float peso;
  float medida;
  char nombre[50];
  char apellido[50];

}Persona;

int main(void) {

  Persona arrayPersona[QTY_PERSONAS];
  arrayPersona[0].peso= 56.7 ;
  arrayPersona[0].medida= 1.67 ;
  strncpy(arrayPersona[0].nombre,"Jorge", 50);
  strncpy(arrayPersona[0].apellido,"Campos", 50);

  arrayPersona[1].peso= 75.4 ;
  arrayPersona[1].medida= 1.73 ;
  strncpy(arrayPersona[1].nombre,"Hugo", 50);
  strncpy(arrayPersona[1].apellido,"Sanchez", 50);

  arrayPersona[2].peso= 85.2 ;
  arrayPersona[2].medida= 1.89 ;
  strncpy(arrayPersona[2].nombre,"Omar", 50);
  strncpy(arrayPersona[2].apellido,"Sivori", 50);

  arrayPersona[3].peso= 66.8 ;
  arrayPersona[3].medida= 1.69 ;
  strncpy(arrayPersona[3].nombre,"Oscar", 50);
  strncpy(arrayPersona[3].apellido,"Mas", 50);

  arrayPersona[4].peso= 80.3 ;
  arrayPersona[4].medida= 1.91 ;
  strncpy(arrayPersona[4].nombre,"Eduardo", 50);
  strncpy(arrayPersona[4].apellido,"Dominguez", 50);


  Persona masPesado;
  Persona masAlto;
  int i;
   for(i=0;i<QTY_PERSONAS;i++)
     {
       if(i==0 || arrayPersona[i].peso > masPesado.peso)
         {
           masPesado = arrayPersona[i];
         }
       if(i==0 || arrayPersona[i].medida > masAlto.medida)
         {
           masAlto = arrayPersona[i];
         }
     }
   printf("\nLa persona mas pesada es %s %s con un peso de %.2f",masPesado.nombre, masPesado.apellido, masPesado.peso);
   printf("\nLa persona mas alta es %s %s con una estatura de %.2f",masAlto.nombre, masAlto.apellido, masAlto.medida);

	return 0;
}
