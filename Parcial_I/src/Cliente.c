/*
 * Cliente.c
 *
 *  Created on: 9 oct. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Cliente.h"
#include "Menu.h"
#include "Gets.h"
#define FREE 1
#define FULL 0

int Cliente_Init(sCliente* list,int len)
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

void Cliente_Hardcodeo(sCliente* list,int len)
{
    char nombre[5][51]= {"Ivan","Antonella","Eliana","Veronica","Kirk"};
    char apellido[5][51]= {"Ghigliotti","Tilbes","Barboza","Soria","Hammett"};
    char cuit[5][51]= {"20-41026881-8","27-41563668-1","27-2463559-0","27-12254336-5","20-1056998-7"};
    int idCliente[5]= {100,101,102,103,104};
    int i;

    for(i=0; i<5; i++)
    {
        list[i].idCliente=idCliente[i];
        strcpy(list[i].nombre,nombre[i]);
        strcpy(list[i].apellido,apellido[i]);
        strcpy(list[i].cuit,cuit[i]);
        list[i].isEmpty=FULL;
    }
}

int Cliente_BuscarLibre(sCliente* list,int len,int* pIndex)
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

int Cliente_GenerarId(void)
{
	static int id=104;
	id++;
	return id;
}

int Cliente_BuscarPorId(sCliente* list,int len,int id,int* pIndex)
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

int Cliente_Imprimir(sCliente* list,int len)
{
    int i;
    int retorno=-1;

	if(list!=NULL && len>0)
	{
		printf("%5s %15s %15s %15s\n_____________________________________________________\n","ID","NOMBRE","APELLIDO","CUIT");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==FULL)
			{
				printf("%5d %15s %15s %15s\n",list[i].idCliente,list[i].nombre,list[i].apellido,list[i].cuit);
				retorno=0;
			}
		}
	}
    printf("\n\n");
    return retorno;
}

int Cliente_Alta(sCliente* list,int len)
{
	int retorno=-1;
	int index;
	sCliente buffer;
	if(list!=NULL && len>0 && Cliente_BuscarLibre(list, len,&index)==0)
	{
		if(GetString("Ingrese su nombre: ","Ingrese un dato valido!\n",buffer.nombre,sizeof(buffer.nombre),2)==0
	       && GetString("Ingrese su apellido: ","Ingrese un dato valido!\n",buffer.apellido,sizeof(buffer.apellido),2)==0
		   && GetCuit("Ingrese su cuit xx-xxxxxxxx-x: ","Ingrese un dato valido o coloque los guiones donde se le indica!\n",buffer.cuit,2)==0)
		{
			buffer.idCliente=Cliente_GenerarId();
			list[index]=buffer;
			printf("#Su id es: %d\n",list[index].idCliente);
			list[index].isEmpty=FULL;
			retorno=0;
		}
	}
	return retorno;
}

int Cliente_Modificar(sCliente* list,int len)
{
    int retorno=-1;
    int flag=0;
    int option;
    int index;
    int goBack=0;
    sCliente buffer;


    if(list!=NULL && len>0 && GetInt("\nIngrese el ID del cliente a modificar: ", "No se encontro ese ID, ingrese un dato valido\n",&buffer.idCliente,2)==0
    		&& Cliente_BuscarPorId(list,len,buffer.idCliente,&index)==0)
    {
    	do
    	{
    	            printf("*********************************\n");
    	            printf("Id: %d\nNombre: %s\nApellido: %s\nCuit: %s\n",list[index].idCliente,
    	            	   list[index].nombre,
    	                   list[index].apellido,
    	                   list[index].cuit);
    	            printf("*********************************\n");
    	            if(GetOption("(1).Nombre\n(2).Apellido\n"
    	            		"(3).Cuit\n(4).Volver al menu principal\nQue desea modificar?: ", "Ingrese un dato valido!\n",&option,2,1,4)==0)
    	            {
						switch(option)
						{
						case 1:
							if(GetString("Ingrese nuevo nombre: ","Ingrese un dato valido!\n",buffer.nombre,sizeof(buffer.nombre),2)==0)
							{
								strncpy(list[index].nombre,buffer.nombre,sizeof(buffer.nombre));
								flag=1;
							}
							break;
						case 2:
							if(GetString("Ingrese nuevo apellido: ","Ingrese un dato valido!\n",buffer.apellido,sizeof(buffer.apellido),2)==0)
							{
								strncpy(list[index].apellido,buffer.apellido,sizeof(buffer.apellido));
								flag = 1;
							}
							break;
						case 3:
							if(GetCuit("Ingrese nuevo cuit xx-xxxxxxxx-x: ","Ingrese un dato valido o coloque los guiones donde se le indica!\n",buffer.cuit,2)==0)
							{
								strncpy(list[index].cuit,buffer.cuit,sizeof(buffer.cuit));
								flag=1;
							}
							break;
						case 4:
							if(flag==1)
							{
								retorno=0;
							}
							else
							{
								retorno=1;
							}
							goBack=1;
							break;
						}
    	            }
    	            system("pause");
    	            system("cls");
    	        }
    	        while(goBack!=1);
    }
    return retorno;
}


