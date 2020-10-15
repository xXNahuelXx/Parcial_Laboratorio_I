/*
 * Validate.h
 *
 *  Created on: 20 sep. 2020
 *      Author: Nahuel
 */

#ifndef VALIDATE_H_
#define VALIDATE_H_
/**
 * @brief Valida que lo ingresado sea solo numeros.
 *
 * @param Recibe el dato como string.
 * @param Recibe el tamaño del dato.
 * @return Devuelve 1 si esta todo 0k, y 0 si hay un error.
 */
int ValidNumber(char*,int);

/**
 * @brief Valida que lo ingresado sea numeros y permita un punto (.).
 *
 * @param Recibe el dato como string.
 * @param Recibe el tamaño del dato.
 * @return Devuelve 1 si esta todo 0k, y 0 si hay un error.
 */
int ValidFloat(char*,int);

/**
 * @brief Valida que lo ingresado solo contenga letras.
 *
 * @param Recibe el dato como string.
 * @param Recibe el tamaño del dato.
 * @return Devuelve 1 si esta todo 0k, y 0 si hay un error.
 */
int ValidString (char*,int);

/**
 * @brief Valida que lo ingresado pueda contener letras y numeros.
 *
 * @param Recibe el dato como string.
 * @param Recibe el tamaño del dato.
 * @return Devuelve 1 si esta todo 0k, y 0 si hay un error.
 */
int ValidDirection(char*,int);

/**
 * @brief Valida que lo ingresado contenga 13 caracteres y guiones en las posiciones correspondientes.
 *
 * @param Recibe el dato como string.
 * @param Recibe el tamaño del dato.
 * @return Devuelve 1 si esta todo 0k, y 0 si hay un error.
 */
int ValidCuit(char*,int);

#endif /* VALIDATE_H_ */
