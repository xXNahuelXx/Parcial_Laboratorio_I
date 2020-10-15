/*
 * Cliente.h
 *
 *  Created on: 9 oct. 2020
 *      Author: Nahuel
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	char nombre[51];
	char apellido[51];
	char cuit[15];
	int idCliente;
	int isEmpty;
}sCliente;

/**
 * @brief Inicia la lista de clientes con el estado isEmpty==FREE.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 * @return
 */
int Cliente_Init(sCliente*,int);

/**
 * @brief Funcion para no cargar manualmente los datos pedidos.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 */
void Cliente_Hardcodeo(sCliente*,int);

/**
 * @brief Busca un indice libre donde puedan cargargarse los datos.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 * @param Recibe el puntero donde se va a guardar el indice.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Cliente_BuscarLibre(sCliente*,int,int*);

/**
 * @brief Genera un nuevo Id para cliente.
 *
 * @return Retorna el Id.
 */
int Cliente_GenerarId(void);

/**
 * @brief Busca el indice de un cliente por medio de un Id ingresado.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 * @param Recibe el Id el cual sera buscado dentro de la lista.
 * @param Recibe el puntero donde se va a guardar el indice.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Cliente_BuscarPorId(sCliente*,int,int,int*);

/**
 * @brief Imprime la informacion basica del cliente.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Cliente_Imprimir(sCliente*,int);

/**
 * @brief Se da de alta un cliente, cambiando su estado isEmpty a FULL.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 * @return Retorna 0 si esta todo 0k, y -1 si hubo error.
 */
int Cliente_Alta(sCliente*,int);

/**
 * @brief Modifica la informacion del cliente.
 *
 * @param Recibe la lista de clcientes.
 * @param Recibe el tamaño de la lista.
 * @return Retorna -1 si hubo un error, 1 si no hubieron cambios y 0 si se modifico correctamente.
 */
int Cliente_Modificar(sCliente*,int);


#endif /* CLIENTE_H_ */
