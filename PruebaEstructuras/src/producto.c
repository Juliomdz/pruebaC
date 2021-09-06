/*
 * producto.c
 *
 *  Created on: 11 may. 2021
 *      Author: julio
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include <string.h>
#include "producto.h"
#include "utn.h"

Producto* producto_new(void)
{
  Producto* auxProducto;
  auxProducto = (Producto*) malloc(sizeof(Producto));
  if(auxProducto!=NULL)
    {
      auxProducto->description[0]='\0';
      auxProducto->idNationality=0;
      auxProducto->idProduct=0;
      auxProducto->price=0;
      auxProducto->status=0;
    }
  return auxProducto;
}
Producto* producto_newParam(char* description,int* idProduct)
{
  Producto* auxProducto = producto_new();
  if(auxProducto != NULL)
  {
    if  (   producto_setDescription(auxProducto,description) < 0 ||
            producto_setId(auxProducto,idProduct) < 0 )
    {
      producto_delete(auxProducto);
      auxProducto = NULL;
      idProduct++;
    }
  }
  return auxProducto;
}
int producto_delete(Producto* this)
{
  int retorno = -1;
  if(this != NULL)
  {
    free(this);
    retorno = 0;
  }
  return retorno;
}
int producto_setDescription(Producto* this, char* description)
{
  int retorno = -1;
  if(this != NULL && description != NULL && isValidDescription(description) )
  {
    strcpy(this->description,description);
    retorno = 0;
  }
  return retorno;
}
char* producto_getDescription(Producto* this,int* flagError)
{
  *flagError = -1;
  char* auxDescription= NULL;
  if(this != NULL && flagError != NULL)
  {
    auxDescription = this->description;
    *flagError = 0;
  }
  return auxDescription;
}
int isValidDescription(char* description)
{
  return 1;
}
int producto_setId(Producto* this, int idProduct)
{
  int retorno = -1;
  if(this != NULL && isValidId(idProduct) )
  {
    this->idProduct = idProduct;
    retorno = 0;
  }
  return retorno;
}
int producto_getId(Producto* this,int* flagError)
{
  *flagError = -1;
  int auxId = -1;
  if(this != NULL && flagError != NULL )
  {
    auxId=this->idProduct;
    *flagError = 0;
  }
  return auxId;
}
int isValidId(int idProduct)
{
  return 1;
}
