/*
 * ClienteyPublicacion.h
 *
 *  Created on: 11 oct. 2020
 *      Author: Nahuel
 */

#ifndef CLIENTEYPUBLICACION_H_
#define CLIENTEYPUBLICACION_H_

#include "Cliente.h"
#include "Publicacion.h"

/**
 * @brief Se da de alta una publicacion.
 *
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @return Retorna -1 si hubo error, o si esta todo 0k.
 */
int CliAndPub_AltaPublicacion(sCliente*,int,sPublicacion*,int);

/**
 * @brief Imprime las publicaciones con los clientes asociados.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @param Recibe el Id de cliente a buscar.
 * @return Retorna -1 si hubo error, 0 si todo esta 0k.
 */
int CliAndPub_ImprimirPubConCli(sPublicacion*,int,int);

/**
 * @brief Imprime informacion del cliente por cada publicacion.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @param Recibe el indice de la publicacion.
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @return Retorna -1 si hubo error, 0 si todo esta 0k.
 */
int CliAndPub_ImprimirInfodeClixPub(sPublicacion*,int,int,sCliente*,int);

/**
 * @brief Imprime los datos del cliente con sus publicaicones.
 *
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @return Retorna -1 si hubo error, 0 si todo esta 0k.
 */
int CliAndPub_ImprimirConTodosSusDatos(sCliente*,int,sPublicacion*,int);

/**
 * @brief Calcula e imprime la cantidad de avisos activos.
 *
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @return Retorna -1 si hubo error, 0 si todo esta 0k.
 */
int CliAndPub_ImprimirCantDeAvisosActivos(sCliente*,int,sPublicacion*,int);

/**
 * @brief Se realiza tanto la baja del cliente como la de publicacion que le pertenezca.
 *
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe el Id del cliente que se desea dar de baja.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @return Retorna -1 si hubo error, 0 si todo esta 0k.
 */
int CliAndPub_BajaCliente(sCliente*,int,int,sPublicacion*,int);

/**
 * @brief Se realiza la modificacion de la publicaicio.
 *
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones.
 * @param Recibe el indice de la publicacion que se desea modificar.
 * @param Recibe la opcion a contamplar para saber si desea ser pausada o reanudada.
 * @return Retorna -1 si no se pudo modificar, 0 si se pudo modificar, 1 si no hubieron cambios.
 */
int CliAndPub_Modificar(sCliente*,int,sPublicacion*,int,int,int);
#endif /* CLIENTEYPUBLICACION_H_ */
