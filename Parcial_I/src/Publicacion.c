/*
 * Publicacion.c
 *
 *  Created on: 10 oct. 2020
 *      Author: Nahuel
 */
#include "Publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Menu.h"
#include "Gets.h"
#define FREE 1
#define FULL 0
#define ACTIVO 0
#define PAUSADO 1

int Publicacion_Init(sPublicacion* list,int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=FREE;
			retorno=0;
		}
	}
	return retorno;
}

void Publicacion_Hardcodeo(sPublicacion* list,int len)
{
	int idPublicacion[5]= {1000,1001,1002,1003,1004};
	int idCliente[5]= {100,100,101,103,104};
	int numRubro[5]= {5,3,5,3,7};
    char textoAviso[5][51]= {"Llame ya","Llame ahora","Actualizate","Fumiga tu casa","Exorcismos"};
    int estado[5]={ACTIVO,PAUSADO,PAUSADO,ACTIVO,ACTIVO};

    int i;

    for(i=0; i<5; i++)
    {
    	list[i].idPublicacion=idPublicacion[i];
    	list[i].idCliente=idCliente[i];
    	list[i].numRubro=numRubro[i];
        strcpy(list[i].textoAviso,textoAviso[i]);
        list[i].isEmpty=FULL;
        list[i].estado=estado[i];
    }
}

int Publicacion_BuscarLibre(sPublicacion* list,int len,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FREE)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int Publicacion_GenerarId(void)
{
	static int id=1004;
	id++;
	return id;
}

int Publicacion_BuscarPorId(sPublicacion* list,int len,int id,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL &&  len>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idPublicacion==id)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int Publicacion_BuscarPorIddeCliente(sPublicacion* list,int len,int id,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL &&  len>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idCliente==id)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int Publicacion_Imprimir(sPublicacion* list,int len)
{
    int i;
    int retorno=-1;
    char estado[15];

	if(list!=NULL && len>0)
	{
		printf("%5s %10s %20s %10s\n________________________________________________\n","ID","RUBRO","AVISO","ESTADO");
		for(i=0; i<len; i++)
		{
			if (list[i].isEmpty==FULL)
			{
				if (list[i].estado==ACTIVO)
				{
					sprintf(estado, "ACTIVO");
				}
				else
				{
					sprintf(estado, "PAUSADO");
				}
				printf("%5d %10d %20s %10s\n", list[i].idPublicacion,list[i].numRubro, list[i].textoAviso, estado);
				retorno = 0;
			}
		}
	}
    printf("\n\n");
    return retorno;
}
