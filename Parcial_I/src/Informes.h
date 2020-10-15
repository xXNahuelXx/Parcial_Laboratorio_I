/*
 * Informes.h
 *
 *  Created on: 11 oct. 2020
 *      Author: Nahuel
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "ClienteyPublicacion.h"
#define RUBROS 1000
typedef struct
{
	int rubro;
	int isEmpty;
}sRubro;

/**
 * @brief Calcula e informa el cliente con mas avisos.
 *
 * @param Recibe la lista de clientes.
 * @param Recibe el tamaño de la lista de clientes.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publiciones.
 * @return Retorna -1 si hubo error, sino la cantidad de avisos.
 */
int Informes_CliconmasAvisos(sCliente*,int,sPublicacion*,int);

/**
 * @brief Calculo e informa la cantidad de avisos pausados.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publiciones.
 * @return Retorna -1 si hubo error o la cantidad de avisos pausados.
 */
int Informes_CantAvisosPausado(sPublicacion*,int);

/**
 * @brief Inicia el campo isEmpty en FREE.
 *
 * @param Recibe la lista de rubros.
 * @param Recibe el tamaño de la lista de rubros.
 * @return Retorna -1 si hubo un error o 0 si esta todo 0k.
 */
int Informes_InitRubro(sRubro*,int);

/**
 * @brief Comprueba si existe el rubro.
 *
 * @param Recibe la lista de rubros.
 * @param Recibe el tamaño de la lista de rubros.
 * @param Recibe el rubro.
 * @return Retorna -1 si hubo error o no existe el rubro y 0 si existe.
 */
int Informes_MiListadeRubros(sRubro*,int,int);

/**
 * @brief Genera la lista de rubros.
 *
 * @param Recibe la lista de rubros.
 * @param Recibe el tamaño de la lista de rubros.
 * @param Recibe la lista de publicaciones.
 * @return Retorna -1 si hubo error o 0 si pudo crearse el rubro.
 */
int Informes_GenerarRubros(sRubro*,int,sPublicacion*);

/**
 * @brief Calcula e informa el rubro con mas avisos.
 *
 * @param Recibe la lista de rubros.
 * @param Recibe el tamaño de la lista de rubros.
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicacion.
 * @return
 */
int Informes_RubroConMasAvisos(sRubro*,int,sPublicacion*,int);

/**
 * @brief Imprime un rubro.
 *
 * @param Recibe el rubro.
 * @return Retorna -1 si hubi error, o 0 si esta todo 0k.
 */
int Informes_printOne(sRubro);

/**
 * @brief Imprime la lista de rubros.
 *
 * @param Recibe la lista de rubros.
 * @param Recibe el tamaño de la lista de rubros.
 * @return Retorna -1 si hubo un error, o 0 si esta todo 0k.
 */
int Informes_printList(sRubro*,int);

/**
 * @brief Cuenta la cantidad de avisos.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones
 * @param Recibe el id por el cual luego se va a contar si coincide con el id de la lista de publicacion.
 * @return Retorna -1 si hubo un error o la cantidad de avisos contados.
 */
int Informes_ContAvisos(sPublicacion*,int,int);

/**
 * @brief Cuenta la cantidad de rubros.
 *
 * @param Recibe la lista de publicaciones.
 * @param Recibe el tamaño de la lista de publicaciones
 * @param Recibe el rubro por el cual luego se va a contar si coincide con el id de la lista de publicacion.
 * @return Retorna -1 si hubo un error o la cantidad de rubros contados.
 */
int Informes_ContRubros(sPublicacion*,int,int);

#endif /* INFORMES_H_ */
