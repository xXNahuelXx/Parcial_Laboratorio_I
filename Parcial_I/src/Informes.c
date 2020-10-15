/*
 * Informes.c
 *
 *  Created on: 11 oct. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"
#define FULL 0
#define FREE 1
#define ACTIVO 0
#define PAUSADO 1

int Informes_CliconmasAvisos(sCliente* listC,int lenC,sPublicacion* listP,int lenP)
{
	int retorno=-1;
	int i;
	int cont;
	int max;
	if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
	{
		for(i=0;i<lenC;i++)
		{
			if(listC[i].isEmpty==FULL)
			{
				cont=Informes_ContAvisos(listP, lenP, listC[i].idCliente);
				if(i==0 || cont>max)
				{
					max=cont;
					retorno=i;
				}
				else if(cont==max)
				{
					printf("No se encontro un maximo!\n");
				}
			}
		}
	}
	return retorno;
}

int Informes_ContAvisos(sPublicacion* list,int len,int id)
{
	int retorno=-1;
	int i;
	int auxCont=0;
	if(list!=NULL &&  len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idCliente==id)
			{
				auxCont++;
			}
		}
		retorno=auxCont;
	}
	return retorno;
}

int Informes_CantAvisosPausado(sPublicacion* list,int len)
{
	int retorno=-1;
	int i;
	int cont=0;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL && list[i].estado==PAUSADO)
			{
				cont++;
			}
		}
		retorno=cont;
	}
	return retorno;
}

int Informes_InitRubro(sRubro* list,int len)
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

int Informes_MiListadeRubros(sRubro* list,int len,int rubro)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0 && rubro>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FULL && list[i].rubro==rubro)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int Informes_GenerarRubros(sRubro* listR,int lenR,sPublicacion* listP)
{

	int i;
	int retorno=-1;
	int indexR=0;

	if (Informes_InitRubro(listR,RUBROS)==0 && listR != NULL && lenR > 0 && listP != NULL)
	{
		for(i=0;i<lenR;i++)
		{
			if(Informes_MiListadeRubros(listR, lenR,listP[i].numRubro)==-1 && listP[i].isEmpty==FULL)
			{
				listR[indexR].rubro=listP[i].numRubro;
				listR[indexR].isEmpty=FULL;
				indexR++;
			}
		}
		retorno=0;
	}
	return retorno;
}

int Informes_ContRubros(sPublicacion* list,int len,int rubro)
{
	int retorno=-1;
	int i;
	int auxCont=0;
	if(list!=NULL &&  len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].numRubro==rubro)
			{
				auxCont++;
			}
		}
		retorno=auxCont;
	}
	return retorno;
}
int Informes_RubroConMasAvisos(sRubro* listR,int lenR,sPublicacion* listP,int lenP)
{
	int retorno = -1;
	int i;
	int cont;
	int max;
	if (listR != NULL && lenR > 0 && listP != NULL && lenP > 0)
	{
		for (i=0;i<lenR;i++)
		{
			if (listR[i].isEmpty==FULL)
			{
				cont=Informes_ContRubros(listP, lenP, listR[i].rubro);
				if (i == 0 || cont > max)
				{
					max=cont;
					retorno=listR[i].rubro;
				}
				else if(cont==max)
				{
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

int Informes_printOne(sRubro list)
{
	int result = -1;

	if (list.isEmpty == FULL)
	{
		printf("\n%10d\n", list.rubro);
		result = 0;
	}
	return result;
}

int Informes_printList(sRubro* list, int len)
{
	int result = -1;
	int i;

	if (list != NULL && len > 0)
	{
		printf("%10s\n", "RUBRO");
		for (i = 0; i < len; i++)
		{
			Informes_printOne(list[i]);
		}
		result = 0;
	}
	return result;
}

int Informes_CliConMasAvisosActivos(sCliente* listC,int lenC,sPublicacion* listP,int lenP)
{
	int retorno=-1;
	int i;
	int cont;
	int max;
	if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
	{
		for(i=0;i<lenC;i++)
		{
			if(listC[i].isEmpty==FULL)
			{
				cont=Informes_ContAvisos(listP, lenP, listC[i].idCliente);
				if(i==0 || cont>max)
				{
					max=cont;
					retorno=i;
				}
				else if(cont==max)
				{
					printf("No se encontro un maximo!\n");
				}
			}
		}
	}
	return retorno;
}

int Informes_ContAvisosActivos(sPublicacion* list,int len,int id)
{
	int retorno=-1;
	int i;
	int auxCont=0;
	if(list!=NULL &&  len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idCliente==id && list[i].estado==ACTIVO)
			{
				auxCont++;
			}
		}
		retorno=auxCont;
	}
	return retorno;
}

int Informes_CliConMasAvisosPausados(sCliente* listC,int lenC,sPublicacion* listP,int lenP)
{
	int retorno=-1;
	int i;
	int cont;
	int max;
	if(listC!=NULL && lenC>0 && listP!=NULL && lenP>0)
	{
		for(i=0;i<lenC;i++)
		{
			if(listC[i].isEmpty==FULL)
			{
				cont=Informes_ContAvisos(listP, lenP, listC[i].idCliente);
				if(i==0 || cont>max)
				{
					max=cont;
					retorno=i;
				}
				else if(cont==max)
				{
					printf("No se encontro un maximo!\n");
				}
			}
		}
	}
	return retorno;
}

int Informes_ContAvisosPausados(sPublicacion* list,int len,int id)
{
	int retorno=-1;
	int i;
	int auxCont=0;
	if(list!=NULL &&  len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idCliente==id && list[i].estado==PAUSADO)
			{
				auxCont++;
			}
		}
		retorno=auxCont;
	}
	return retorno;
}
