/*
 * tipo.h
 *
 *  Created on: 11 may. 2021
 *      Author: julio
 */

#ifndef TIPO_H_
#define TIPO_H_


typedef struct
{
  int idTipo;
  char marca[50];
  char fabrica[50];
  char tipoTela[50];
  int status; // 0 es vacio, 1 es pendiente de pago y 2 es abonada
}Tipo;



#endif /* TIPO_H_ */


