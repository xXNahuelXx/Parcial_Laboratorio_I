/*
 * Validate.c
 *
 *  Created on: 20 sep. 2020
 *      Author: Nahuel
 */
#include "Validate.h"

int ValidNumber(char* string,int len)
{
	int retorno = 1;
	int i;
	for(i=0; i<=len && string[i] != '\0';i++)
	{

		if(i==0 && (string[i]=='+' || string[i]=='-'))
		{
			continue;
		}
		if((string[0]=='\n' || string[i]==' ') || (string[i]<'0' || string[i]>'9'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int ValidFloat(char* string,int len)
{
    int retorno=1;
    int i=0;
    int contPunto=0;
    for(i=0; i<=len && string[i] != '\0';i++)
    {
		if (string[i] == '.')
		{
			contPunto++;
		}
		if (((string[0] == '\n' || string[i] == ' ') || (string[i] < '0' || string[i] > '9')) && (string[i] != '.' || contPunto > 1))
		{
			retorno = 0;
			break;
		}
    }
    return retorno;
}



int ValidString (char* string,int len)
{
	int retorno=1;
	int i;
	for(i=0; i<=len && string[i] != '\0';i++)
	{
		if((string[0]=='\n' || string[i]!=' ') && (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int ValidDirection(char* string,int len)
{
	int retorno=1;
	int i;
	for(i=0; i<=len && string[i] != '\0';i++)
	{
		if((string[0]=='\n' || string[i]!=' ') && (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z') && (string[i]<'0' || string[i]>'9'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int ValidCuit(char* string,int len)
{
	int retorno=1;
	int i;

	for(i=0; i<=len && string[i] != '\0';i++)
	{
		if((string[0]=='\n' || string[i]!=' ') && (string[i]<'0' || string[i]>'9') && (string[2]!='-' && string[11]!='-'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}
