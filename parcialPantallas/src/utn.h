/*
 * utn.h
 *
 *  Created on: 16 abr. 2021
 *      Author: julio
 */

#ifndef UTN_H_
#define UTN_H_

/**
* \brief Recibe un string, lo recorre verificando que no quede un '\n' antes de la penultima posición y la valida
* \param char* string: Puntero al espacio de memoria donde se copiará la cadena obtenida
* \param limite: Define el tamaño del string
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int myGets(char* string, int limite);
/**
 * \brief Transforma una cadena de caractéres a números si es posible
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número entero o -1 (ERROR) si no
*/
int utn_getInt(int *pResultado);
/**
 * \brief Transforma una cadena de caractéres a números decimales si es posible
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número decimal o -1 (ERROR) si no
*/
int getFloat(float *pResultado);
/**
 * \brief Verifica que la cadena recibida contenga solamente números positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esNumerica(char* cadena, int limite);
/**
 * \brief Verifica que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos
*/
int utn_esDecimal(char* cadena, int limite);
/**
 * \brief Le pide al usuario un número entero entre un rango
 * \param int* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* mensaje: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int min: El rango mínimo para ingresar un número
 * \param int max: El rango máximo para ingresar un número
 * \param int reintentos: cantidad de veces que, en caso de error, se volverá a iterar
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getNumero(int* pNumero, const char* mensaje, const char* mensajeError, int min, int max,int reintentos);
/**
 * \brief Le pide al usuario un número racional
 * \param float* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* sError: Texto que nos indica que hubo un error
 * \param int reintentos: cantidad de veces que, en caso de error, se volverá a iterar
 * \return Retorna 0 (EXITO) si se obtiene un número racional o -1 (ERROR) si no
*/
int utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, int reintentos);
/**
 * \brief Suma dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la suma, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la suma o -1 (ERROR) si no
*/
int utn_sumar(float numeroA, float numeroB, float* pResultado);
/**
 * \brief Resta dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la resta, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no
*/
int utn_restar(float numeroA, float numeroB, float* pResultado);
/**
 * \brief Divide dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la división, que va a llegar al main mediante un puntero
 * \param const char* pDivisionPorCero: Mensaje de error si el divisor es cero
 * \return Retorna 0 (EXITO) si se pudo completar la division o -1 (ERROR) si no o si el divisor es 0
*/
int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero);
/**
 * \brief Multiplica dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la multiplicación, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la multiplicación o -1 (ERROR) si no
*/
int utn_multiplicar(float dividendo, float divisor, float* pResultado);
/**
 * \brief Factoriza un número ingresado y lo devuelve mediante un puntero
 * \param float numero: Número a ser factoriado
 * \param float* pResultado: El resultado de la factorización, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la factorisación o -1 (ERROR) si no
*/
int utn_factorial(float numero, float* pResultado);
/**
 * \brief Le pide al usuario una cadena de caracteres y la valida
 * \param char* pResultado: Puntero donde se almacena la cadena de caracteres
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int limite: El maximo de caracteres que se pueden ingresar
 * \param int reintentos: cantidad de veces que se puede reintentar en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_getText(char* pResultado, char* pMensaje, char* mensajeError, int limite, int reintentos);

/**
 * \brief Le pide al usuario un caracter y lo valida
 * \param char* pResultado: Puntero donde se almacena el caracter
 * \param  char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* mensajeError: Texto que nos indica que hubo un error
 * \param int reintentos: cantidad de veces que se puede reintentar en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int utn_GetChar(char* pResultado,char* pMensaje,char* mensajeError,int reintentos);
/**
 * \brief recibe un char y valida que sea un valor entre a y z
 * \param char* letra: Puntero donde se almacena el caracter
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no
*/
int esLetra(char* letra);

int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError);
int validarCuit(char* cadena, int limite);
#endif /* UTN_H_ */
