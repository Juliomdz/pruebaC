/*
 * calculosTransporte.h
 *
 *  Created on: 22 jun. 2021
 *      Author: julio
 */

#ifndef CALCULOSTRANSPORTE_H_
#define CALCULOSTRANSPORTE_H_
#include "calculosTransporte.h"
#include "collections/LinkedList.h"
#include "collections/Dictionary.h"
#include "PosicionArancelaria.h"
#include "Articulo.h"
#include "costosTransporte.h"


int calc_fleteMaritimo(Articulo* pArticulo,CostosTransporte* costos,float* costoMaritimo);
int calc_CostoFinalMaritimo(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal);
int calc_CostoMaritimoConImpuestos(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal);

int calc_fleteAereo(Articulo* pArticulo,CostosTransporte* costos,float* costoAereo);
int calc_CostoFinalAereo(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal);
int calc_CostoAereoConImpuestos(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal);

#endif /* CALCULOSTRANSPORTE_H_ */
