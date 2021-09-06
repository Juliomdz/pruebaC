/*
 * informes.h
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);

int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


#endif /* INFORMES_H_ */
