/*
 * Nacionalidad.h
 *
 *  Created on: 11 may. 2021
 *      Author: julio
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#define SIZE_DESCRIPTION_NATION 512

typedef struct
{
    int idNationality;
    char descriptionNationality[SIZE_DESCRIPTION_NATION];
    int status; // 0 es vacio, 1 es pendiente de pago y 2 es abonada
}Producto;
#endif /* NACIONALIDAD_H_ */
