/*
 * ClienteyPublicacion.c
 *
 *  Created on: 11 oct. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ClienteyPublicacion.h"
#include "Gets.h"
#define FREE 1
#define FULL 0
#define ACTIVO 0
#define PAUSADO 1

int CliAndPub_AltaPublicacion(sCliente* listC,int lenC,sPublicacion* listP,int lenP)
{
	int retorno=-1;
	int indexC;
	int indexP;
	sCliente bufferC;
	sPublicacion bufferP;
	if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
	{
		if(GetInt("Ingrese Id del cliente: ","No se encontro ese Id, ingrese un dato valido!\n",&bufferC.idCliente,2)==0
				&& Cliente_BuscarPorId(listC, lenC,bufferC.idCliente,&indexC)==0
				&& Publicacion_BuscarLibre(listP,lenP,&indexP)==0
				&& GetInt("Ingrese numero de rubro: ","Ingrese un dato valido!\n",&bufferP.numRubro,2)==0
				&& GetString("Ingrese el texto del aviso: ","Ingrese un dato valido!\n",bufferP.textoAviso,sizeof(bufferP.textoAviso),2)==0)
		{
			listP[indexP]=bufferP;
			listP[indexP].idPublicacion=Publicacion_GenerarId();
			listP[indexP].idCliente=listC[indexC].idCliente;
			printf("#Id de publicacion: %d\n",listP[indexP].idPublicacion);
			listP[indexP].isEmpty=FULL;
			listP[indexP].estado=ACTIVO;
			retorno=0;
		}
	}
	return retorno;
}

int CliAndPub_ImprimirPubConCli(sPublicacion* list,int len,int id)
{
	int retorno=-1;
	int i;
	char estado[11];
	if(list!=NULL && len>0 && id>0)
	{
		printf("%5s %10s %20s %10s","IDP","RUBRO","AVISO","ESTADO\n");
		for(i=0;i<len;i++)
		{

			if(list[i].isEmpty==FULL && list[i].idCliente==id)
			{
				if(list[i].estado==ACTIVO)
				{
					sprintf(estado,"ACTIVO");
				}
				else
				{
					sprintf(estado,"PAUSADO");
				}
				printf("%5d %10d %20s %10s\n",list[i].idPublicacion,list[i].numRubro,list[i].textoAviso,estado);
				retorno=0;
			}
			else if(list[i].isEmpty==FREE)
			{
				retorno=-1;
			}
		}
	}
	return retorno;
}

int CliAndPub_ImprimirInfodeClixPub(sPublicacion* list,int len,int indexP,sCliente* listC,int lenC)
{
	int retorno=-1;
	int i;
	char estado[11];
	if(list!=NULL && len>0 && indexP>0 && listC!=NULL && lenC>0)
	{
		printf("%5s %15s %15s %15s\n_____________________________________________________\n","IDC","NOMBRE","APELLIDO","CUIT");
		for(i=0;i<lenC;i++)
		{
			if(list[indexP].isEmpty==FULL && list[indexP].idCliente==listC[i].idCliente)
			{
				if(list[i].estado==ACTIVO)
				{
					sprintf(estado,"ACTIVO");
				}
				else
				{
					sprintf(estado,"PAUSADO");
				}
				printf("%5d %15s %15s %15s\n",listC[i].idCliente,listC[i].nombre,listC[i].apellido,listC[i].cuit);
				retorno=0;
			}
		}
	}
	return retorno;
}

int CliAndPub_ImprimirConTodosSusDatos(sCliente* listC,int lenC,sPublicacion* listP,int lenP)
{
	int retorno=-1;
	int i;
	int j;
	char estado[15];
	int flag;
	if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
	{
		printf("%4s %10s %10s %15s %4s %5s %20s %6s\n","IDC","NOMBRE","APELLIDO","CUIT","IDP","RUBRO","AVISO","ESTADO");
		for(i=0;i<lenC;i++)
		{
			if(listC[i].isEmpty==FULL)
			{
				flag=1;
				printf("%4d %10s %10s %15s",listC[i].idCliente,listC[i].nombre,listC[i].apellido,listC[i].cuit);
				for(j=0;j<lenP;j++)
				{
					if(listP[j].isEmpty==FULL && listP[j].estado==ACTIVO && listC[i].idCliente==listP[j].idCliente)
					{
						if (listP[j].estado == ACTIVO)
						{
							sprintf(estado, "ACTIVO");
						}
						else
						{
							sprintf(estado, "PAUSADO");
						}
						printf("%4d %5d %20s %6d\n",listP[j].idPublicacion,listP[j].numRubro,listP[j].textoAviso,listP[j].estado);
						flag=0;
					}
				}
				if(flag==1)
				{
					printf("\nSin publicaciones!\n");
				}
			}
		}
	}
	return retorno;
}

int  CliAndPub_ImprimirCantDeAvisosActivos(sCliente* listC,int lenC,sPublicacion* listP,int lenP)
{
	int retorno=-1;
	int i;
	int j;
	int cont=0;
	if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
	{
		printf("%5s %15s %15s %15s\n_____________________________________________________\n","IDC","NOMBRE","APELLIDO","CUIT");
		for(i=0;i<lenC;i++)
		{
			if(listC[i].isEmpty==FULL)
			{
				for(j=0;j<lenP;j++)
				{
					if(listC[i].idCliente==listP[j].idCliente && listP[j].estado==ACTIVO)
					{
						cont++;
					}
				}
				printf("%5d %15s %15s %15s",listC[i].idCliente,listC[i].nombre,listC[i].apellido,listC[i].cuit);
				printf("\tCantidad de avisos activos: %d\n",cont);
				cont=0;
			}
		}
		retorno=cont;
	}
	return retorno;
}

int CliAndPub_BajaCliente(sCliente* list,int len,int id,sPublicacion* listP,int lenP)
{
	int retorno=-1;
    char bufferChar;
    char confirm;
    int leave=0;
    int indexC;
    int i;

    if(list!=NULL && len>0 && id>0 && Cliente_BuscarPorId(list,len,id,&indexC)==0 )
    {
    	if(indexC!=-1)
		{
    		do
			{
				if(GetChar("Seguro desea eliminar? (s/n): ", "Ingrese un dato valido!\n",&bufferChar,2)==0)
				{
					confirm=tolower(bufferChar);
					if(confirm == 'n')
					{
						retorno = 1;
						break;
					}
					else
					{
						if (confirm == 's')
						{
							for(i=0;i<lenP;i++)
							{
								if(listP[i].idCliente==list[indexC].idCliente)
								{
									listP[i].isEmpty=FREE;
								}
							}
							list[indexC].isEmpty=FREE;
							retorno = 0;
							leave=1;
						}
					}
				}
				system("pause");
				system("cls");
			}while(leave!=1);
		}
    }
    return retorno;
}

int CliAndPub_Modificar(sCliente* listC,int lenC,sPublicacion* listP,int lenP,int indexP,int opcion)
{
    int retorno=-1;
    char bufferChar;
    char confirmar;
    int leave;

    if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
    {
		if (indexP!=-1)
		{
			do
			{
				if(opcion==5)
				{
					if (GetChar("Seguro desea pausar esta publicacion? (s/n): ","Ingrese un dato valido!\n", &bufferChar,2) == 0)
					{
						confirmar=tolower(bufferChar);
						if (confirmar=='n')
						{
							retorno = 1;
							break;
						}
						else
						{
							if (confirmar=='s')
							{
								listP[indexP].estado=PAUSADO;
								retorno = 0;
								leave = 1;
							}
						}
					}
				}
				if (opcion == 6)
				{
					if (GetChar("Seguro desea reanudar esta publicacion? (s/n): ","Ingrese un dato valido!\n", &bufferChar, 2) == 0)
					{
						confirmar = tolower(bufferChar);
						if (confirmar == 'n')
						{
							retorno = 1;
							break;
						}
						else
						{
							if (confirmar == 's')
							{
								listP[indexP].estado = ACTIVO;
								retorno = 0;
								leave = 1;
							}
						}
					}
				}
				system("pause");
				system("cls");
			} while (leave != 1);
		}
    }
    return retorno;
}
