/*
 * Gets.h
 *
 *  Created on: 20 sep. 2020
 *      Author: Nahuel
 */

#ifndef GETS_H_
#define GETS_H_

/**
 * @brief Pide una opcion.
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Dato donde será guardado lo ingresado.
 * @param Cantidad de reintentos.
 * @param El minimo que puede ingresar.
 * @param El maximo que puede ingresar.
 * @return Devuelve 0 si está todo 0k, o -1 si hay error-
 */
int GetOption(char*,char*,int*,int,int,int);

/**
 * @brief Pide el ingreso de numeros.
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Puntero donde se va a guardar el dato ingresado.
 * @param Reintentos en caso de ingresar un dato erroneo.
 * @return Devuelve 0 si esta todo 0k, o -1 si hubo error.
 */
int GetInt(char*,char*,int*,int);

/**
 * @brief Pide el ingreso de una opcion como caracter s/n.
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Puntero donde se va a guardar el dato ingresado.
 * @param Reintentos en caso de ingresar un dato erroneo.
 * @return Devuelve 0 si esta todo 0k, o -1 si hubo error.
 */
int GetChar(char*,char*,char*,int);

/**
 * @brief Pide el ingreso de un flotante, se puede ingresar como entero o agregar un punto (.).
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Puntero donde se va a guardar el dato ingresado.
 * @param Reintentos en caso de ingresar un dato erroneo.
 * @return Devuelve 0 si esta todo 0k, o -1 si hubo error.
 */
float GetFloat(char*,char*,float*,int);

/**
 * @brief Pide el ingreso de algo tipo string.
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Puntero donde se va a guardar el dato ingresado.
 * @param El tamaño que del string.
 * @param Reintentos en caso de ingresar un dato erroneo.
 * @return Devuelve 0 si esta todo 0k, o -1 si hubo error.
 */
int GetString(char*,char*,char*,int,int);

/**
 * @brief Pide el ingreso de una direccion, puede ser alfanumerica.
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Puntero donde se va a guardar el dato ingresado.
 * @param El tamaño que del string.
 * @param Reintentos en caso de ingresar un dato erroneo.
 * @return Devuelve 0 si esta todo 0k, o -1 si hubo error.
 */
int GetDirection(char*,char*,char*,int,int);

/**
 * @brief Pide el ingreso de un cuit con el formato xx-xxxxxxxx-x.
 *
 * @param Mensaje que pide el ingreso del dato.
 * @param Mensaje de error.
 * @param Puntero donde se va a guardar el dato ingresado.
 * @param Reintentos en caso de ingresar un dato erroneo.
 * @return Devuelve 0 si esta todo 0k, o -1 si hubo error.
 */
int GetCuit(char*,char*,char*,int);

#endif /* GETS_H_ */
