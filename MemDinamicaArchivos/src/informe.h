/*
 * informe.h
 *
 *  Created on: 20 may. 2021
 *      Author: julio
 */

#ifndef INFORME_H_
#define INFORME_H_

#include "informe.h"
#include "pProducto.h"
#include "pNacionalidad.h"
#include "pTipo.h"

//----------------------------------------------------------------------- ALTA DE PRODUCTO
int informe_altaArrayPunterosProducto(pProducto* arrayPproducto[], int limiteProductos, int* idProducto,
                      pNacionalidad* arrayPnacionalidad[], int limiteNacionalidad,
                      pTipo* arrayPtipo[], int limiteTipo);

//----------------------------------------------------------------------- MODIFICAR PRODUCTO
int informe_menuModificarProducto(pProducto* arrayPproducto[], int limiteProductos,
                  pNacionalidad* arrayPnacionalidad[], int limiteNacionalidad,
                  pTipo* arrayPtipo[], int limiteTipo);

//------------------------------------------------------------------ IMPRIMIR PRODUCTOS Y DETALLE
int informe_imprimirProductos(pProducto* arrayPproducto[], int limiteProductos,
                pNacionalidad* arrayPnacionalidad[], int limiteNacionalidad,
                pTipo* arrayPtipo[], int limiteTipo, int* flagError);

#endif /* INFORME_H_ */
