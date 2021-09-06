/*
 * producto.h
 *
 *  Created on: 11 may. 2021
 *      Author: julio

1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando
 haya espacio disponible en el array.
 2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de
 la lista, dejando espacio disponible para un nuevo producto.
 3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá
 modificar el precio o el tipo.
 4. LISTADO Productos.
 5. LISTADO ordenado por precio.
 6. LISTADO ordenado por descripción
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#define SIZE_DESCRIPTION_PROD 512

typedef struct
{
    int idProduct;
    char description[SIZE_DESCRIPTION_PROD];
    int idNationality;
    float price;
    int status; // 0 es vacio, 1 es pendiente de pago y 2 es abonada
}Producto;

Producto* producto_new(void);
Producto* producto_newParam(char* description,int* idProduct);
int producto_delete(Producto* this);
int producto_setId(Producto* this, int idProducto);
int producto_getId(Producto* this,int* flagError);
int isValidId(int idProducto);
int producto_setDescription(Producto* this, char* description);
char* producto_getDescription(Producto* this,int* flagError);
int isValidDescription(char* description);
int producto_setIdNation(Producto* this, int idNationality);
int producto_getIdNation(Producto* this,int* flagError);
int isValidIdNation(int idNationality);
int producto_setPrice(Producto* this, float price);
int producto_getPrice(Producto* this,int* flagError);
int isValidPrice(float price);

#endif /* PRODUCTO_H_ */
