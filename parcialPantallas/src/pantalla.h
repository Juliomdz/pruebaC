/*
 * pantalla.h
 *
 *  Created on: 27 abr. 2021
 *      Author: julio
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_
#define SIZE_NOMBRE 512
#define SIZE_DIRECCION 1024
#define SIZE_TIPO 32
typedef struct
{
    char nombre[SIZE_NOMBRE];
    char direccion[SIZE_DIRECCION];
    float precioPorDia;
    char tipo[SIZE_TIPO];
    int idPantalla;
    int isEmpty;
}Pantalla;

int pantalla_init(Pantalla* array,int limite);
int pantalla_imprimir(Pantalla* pPantalla);
int pantalla_imprimirArray(Pantalla* array,int limite);
int pantalla_mostrarDebug(Pantalla* array,int limite);
int pantalla_alta(Pantalla* pPantalla,int limite, int indice, int* id);
int pantalla_baja(Pantalla* array,int limite, int id);
int pantalla_modificacion(Pantalla* array,int limite, int id);
int pantalla_ordenarNombre(Pantalla* array,int limite);
int pantalla_ordenarNombrePrecio(Pantalla* arrayPantalla,int limite);
int pantalla_isEmptyIndice(Pantalla* pPantalla);
int pantalla_buscarID(Pantalla* arrayPantalla,int limite, int valorBuscado, int indiceRespuesta);
int pantalla_altaForzada(Pantalla* pPantalla,int limite,char* nombre,char* direccion, float precio, char* tipo, int indice,int* id);
int pantalla_buscarLugarLibre(Pantalla* arrayPantalla,int* indiceLibre,int limite);
int get_option(int* pOpcion,int opciones);
int get_ledOLcd(char* pRespuesta);

#endif /* PANTALLA_H_ */
