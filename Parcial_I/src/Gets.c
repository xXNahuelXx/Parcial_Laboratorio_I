/*
 * Gets.c
 *
 *  Created on: 20 sep. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Gets.h"
#include "Validate.h"

static int MyGets(char* string,int len)
{
	fflush(stdin);
	fgets (string,len,stdin);
	string[strlen(string)-1]='\0';
	return 0;
}

int GetOption(char* msj,char* msjError,int* pDato,int retries,int min,int max)
{
	int retorno=-1;
	int bufferInt;
	int resultScanf;
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0 && max>=min)
	{
		do
		{
			printf("%s",msj);
			fflush(stdin);
			resultScanf=scanf("%d",&bufferInt);
			if(resultScanf==1 && bufferInt>=min && bufferInt<=max)
			{
				*pDato=bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n",msjError,retries);
				retries--;
			}

		}while(retries>=0);
	}
	return retorno;
}

int GetInt(char* msj,char* msjError,int* pDato,int retries)
{
	int retorno=-1;
	char bufferInt[100];
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0)
	{
		do
		{
			printf("%s",msj);
			if(MyGets(bufferInt,100)==0 && ValidNumber(bufferInt,100)==1 && bufferInt[0]!='\0')
			{
				*pDato=atoi(bufferInt);
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n",msjError,retries);
				retries--;
			}
		}while(retries>=0);
	}
	return retorno;
}

int GetChar(char* msj,char* msjError,char* pDato,int retries)
{
	int retorno=-1;
	int resultScanf;
	char bufferLetter;
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>0)
	{
		do
		{
			printf("%s",msj);
			fflush(stdin);
			resultScanf=scanf("%c",&bufferLetter);
			if(resultScanf==1 && bufferLetter!='\0' && bufferLetter!=' ' && (bufferLetter=='s' || bufferLetter=='S' || bufferLetter=='n' || bufferLetter=='N'))
			{
				*pDato=bufferLetter;
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n",msjError,retries);
				retries--;
			}
		}while(retries>=0);
	}
	return retorno;
}

float GetFloat(char* msj,char* msjError,float* pDato,int retries)
{
	int retorno=-1;
	char bufferFloat[100];
	if (msj != NULL && msjError != NULL && pDato != NULL && retries >= 0)
	{
		do
		{
			printf("%s", msj);
			if (MyGets(bufferFloat, 100) == 0 && ValidFloat(bufferFloat, 100) == 1 && bufferFloat[0] != '\0')
			{
				*pDato = atof(bufferFloat);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n", msjError, retries);
				retries--;
			}
		} while (retries >= 0);
	}
	return retorno;
}

int GetString(char* msj,char* msjError,char* pDato,int len,int retries)
{
	int retorno=-1;
	char bufferString[100];
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0)
	{
		do
		{
			printf("%s",msj);
			if(MyGets(bufferString,100)==0 && ValidString(bufferString, 100) && bufferString[0]!='\0' &&  bufferString[0]!=' ' && strnlen(bufferString,100)>3)
			{
				strncpy(pDato,bufferString,len);
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n", msjError, retries);
				retries--;
			}
		}while(retries>=0);
	}
	return retorno;
}

int GetDirection(char* msj,char* msjError,char* pDato,int len,int retries)
{
	int retorno=-1;
	char bufferString[100];
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0)
	{
		do
		{
			printf("%s",msj);
			if(MyGets(bufferString,100)==0 && ValidDirection(bufferString, 100) && bufferString[0]!='\0' &&  bufferString[0]!=' ' && strnlen(bufferString,100)>3)
			{
				strncpy(pDato,bufferString,len);
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n", msjError, retries);
				retries--;
			}
		}while(retries>=0);
	}
	return retorno;
}

int GetCuit(char* msj,char* msjError,char* pDato,int retries)
{
	int retorno=-1;
	char bufferString[100];

	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0)
	{
		do
		{
			printf("%s",msj);
			if(MyGets(bufferString,100)==0 && ValidCuit(bufferString,100) && bufferString[0]!='\0' &&  bufferString[0]!=' ' && strnlen(bufferString,100)==13)
			{

				strncpy(pDato,bufferString,14);
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n", msjError, retries);
				retries--;
			}
		}while(retries>=0);
	}
	return retorno;
}
