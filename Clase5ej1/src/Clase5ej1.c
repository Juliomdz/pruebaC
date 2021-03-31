/*
 ============================================================================
 Name        : Clase5ej1.c
 Author      : Julio Mendez
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

int main(void)
{
    char letra;

  if(utn_getCharacter(&letra,"Letra? [A/B]:","ERROR!\n",'A','B',2)==0)
  {
    printf("La letra es: %c",letra);
  }
  return 0;
}
