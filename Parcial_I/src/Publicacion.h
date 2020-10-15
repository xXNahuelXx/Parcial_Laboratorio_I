/*
 * Publicacion.h
 *
 *  Created on: 10 oct. 2020
 *      Author: Nahuel
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#include "Cliente.h"

typedef struct
{
	int idPublicacion;
	int idCliente;
	int numRubro;
	char textoAviso[64];
	int isEmpty;
	int estado;

}sPublicacion;

/**
 * @brief Inicia el campo isEmpty en FREE del listado de publicaciones.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @return Retorna -1 si hubo error, o 0 si esta todo 0k.
 */
int Publicacion_Init(sPublicacion*,int);

/**
 * @brief Funcion para no cargar manualmente los datos pedidos.
 *
 * @param Recibe la lista de publicacines.
 * @param Recibe el tamaño de la lista de clientes.
 */
void Publicacion_Hardcodeo(sPublicacion*,int);

/**
 * @brief Busca un indice libre donde puedan cargargarse los datos.
 *
 * @param Recibe la lista de publicacines.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe el puntero donde se va a guardar el indice.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Publicacion_BuscarLibre(sPublicacion*,int,int*);

/**
 * @brief Genera un nuevo Id para la publicacion.
 *
 * @return Retorna el Id.
 */
int Publicacion_GenerarId(void);

/**
 * @brief  Busca el indice de una publicacion por medio de un Id ingresado.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @param Recibe el Id el cual sera buscado dentro de la lista.
 * @param Recibe el puntero donde se va a guardar el indice.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Publicacion_BuscarPorId(sPublicacion*,int,int,int*);

/**
 * @brief Busca el indice de una publicacion por medio de un Id de cliente ingresado.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @param Recibe el Id el cual sera buscado dentro de la lista.
 * @param Recibe el puntero donde se va a guardar el indice.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Publicacion_BuscarPorIddeCliente(sPublicacion*,int,int,int*);

/**
 * @brief Imprime la informacion basica de la publicacion.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Publicacion_Imprimir(sPublicacion*,int);

#endif /* PUBLICACION_H_ */
