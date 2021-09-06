/*
 * calculosTransporte.c
 *
 *  Created on: 22 jun. 2021
 *      Author: julio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PosicionArancelaria.h"
#include "Articulo.h"
#include "costosTransporte.h"
#include "calculosTransporte.h"

int calc_fleteMaritimo(Articulo* pArticulo,CostosTransporte* costos,float* costoMaritimo)
{
  int retorno =-1;
  float ancho;
  float altura;
  float profundidad;
  float axuMetroCubicosArticulo;
  float valorContenedor;
  float metrosCubicosContenedor;
  float precioPorMetroCubico;

  if(pArticulo != NULL && costos!=NULL)
    {
      articulo_getAncho(pArticulo,&ancho);
      articulo_getAltura(pArticulo,&altura);
      articulo_getProfundidad(pArticulo,&profundidad);
      axuMetroCubicosArticulo=(ancho/100)*(altura/100)*(profundidad/100);
      costos_getValorContenedor(costos, &valorContenedor);
      costos_getMetrosCubicosContenedor(costos, &metrosCubicosContenedor);
      precioPorMetroCubico=valorContenedor/metrosCubicosContenedor;
      *costoMaritimo=(precioPorMetroCubico*axuMetroCubicosArticulo);
      retorno =1;
    }
return retorno;
}

int calc_CostoFinalMaritimo(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal)
{
  int retorno =-1;
  float costoMaritimo;
  float valorFob;
  float porcentajeSeguro;
  float seguro;

  if(pArticulo != NULL && pPosArancel!=NULL && costos!=NULL)
    {
      articulo_getValorFob(pArticulo,&valorFob);
      calc_fleteMaritimo(pArticulo,costos,&costoMaritimo);
      posArancel_getSeguro(pPosArancel,&porcentajeSeguro);
      seguro=valorFob*porcentajeSeguro;
      *costoFinal=(valorFob+seguro+costoMaritimo);
      retorno=1;
    }
  return retorno;
}

int calc_CostoMaritimoConImpuestos(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal)
{
  int retorno =-1;
  float baseImponible;
  float porcentajeImportacion;
  float porcentajeTasa;
  float tasaAplicada=0;
  float ImportacionAplicada=0;

  if(pArticulo != NULL && pPosArancel!=NULL && costos!=NULL)
    {
      posArancel_getImportacion(pPosArancel,&porcentajeImportacion);
      posArancel_getTasaEstadistica(pPosArancel, &porcentajeTasa);
      calc_CostoFinalMaritimo(pArticulo,pPosArancel,costos,&baseImponible);
      tasaAplicada=baseImponible*porcentajeTasa;
      ImportacionAplicada=baseImponible*ImportacionAplicada;
      *costoFinal=baseImponible+ImportacionAplicada+tasaAplicada;
      retorno =1;
    }
  return retorno;
}

int calc_fleteAereo(Articulo* pArticulo,CostosTransporte* costos,float* costoAereo)
{
  int retorno =-1;
  float ancho;
  float peso;
  float altura;
  float profundidad;
  float axuCentimetrosCubicosArticulo;
  float constanteVolumetrica;
  float precioVolumetrico;
  float precioPorKilo;
  float auxVolumetrico;
  float auxPeso;

  if(pArticulo != NULL && costos!=NULL)
    {
      articulo_getPeso(pArticulo, &peso);
      articulo_getAncho(pArticulo,&ancho);
      articulo_getAltura(pArticulo,&altura);
      articulo_getProfundidad(pArticulo,&profundidad);
      axuCentimetrosCubicosArticulo=(ancho)*(altura)*(profundidad);
      costos_getConstanteVolumetrica(costos, &constanteVolumetrica);
      costos_getPrecioPorKilo(costos, &precioPorKilo);
      precioVolumetrico=axuCentimetrosCubicosArticulo/constanteVolumetrica;
      auxVolumetrico=(precioVolumetrico*precioPorKilo);
      auxPeso=(peso*precioPorKilo);
      if(auxPeso>=auxVolumetrico)
        {
          *costoAereo=auxPeso;
        }
      else
        {
          *costoAereo=auxVolumetrico;
        }
      retorno =1;
    }
return retorno;
}

int calc_CostoFinalAereo(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal)
{
  int retorno =-1;
  float costoAereo;
  float valorFob;
  float porcentajeSeguro;
  float seguro;

  if(pArticulo != NULL && pPosArancel!=NULL && costos!=NULL)
    {
      articulo_getValorFob(pArticulo,&valorFob);
      calc_fleteAereo(pArticulo,costos,&costoAereo);
      posArancel_getSeguro(pPosArancel,&porcentajeSeguro);
      seguro=valorFob*porcentajeSeguro;
      *costoFinal=(valorFob+seguro+costoAereo);
      retorno=1;
    }
  return retorno;
}

int calc_CostoAereoConImpuestos(Articulo* pArticulo,PosicionArancelaria* pPosArancel,CostosTransporte* costos,float* costoFinal)
{
  int retorno =-1;
  float baseImponible;
  float porcentajeImportacion;
  float porcentajeTasa;
  float tasaAplicada=0;
  float ImportacionAplicada=0;

  if(pArticulo != NULL && pPosArancel!=NULL && costos!=NULL)
    {
      posArancel_getImportacion(pPosArancel,&porcentajeImportacion);
      posArancel_getTasaEstadistica(pPosArancel, &porcentajeTasa);
      calc_CostoFinalAereo(pArticulo,pPosArancel,costos,&baseImponible);
      tasaAplicada=baseImponible*porcentajeTasa;
      ImportacionAplicada=baseImponible*ImportacionAplicada;
      *costoFinal=baseImponible+ImportacionAplicada+tasaAplicada;
      retorno =1;
    }
  return retorno;
}
