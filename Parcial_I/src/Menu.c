/*
 * Menu.c
 *
 *  Created on: 9 oct. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Menu.h"
#include "Gets.h"
#include "Informes.h"
#define CLIENTES 100
#define PUBLICACIONES 1000
#define RUBROS 1000

void Menu()
{
	int opcion;
	int bufferId;
	int i=0;
	int iPub=0;
	int bufferIndex;
	int opcionMod;
	int opcionSubMenu;
	int indexInfo;
	int rtInfo;
	int rtOtraInfo;
	int goBack;
	int bufferIndexP;
	char bufferChar;
	char salir;
	sCliente aCliente[CLIENTES];
	sPublicacion aPublicacion[PUBLICACIONES];
	sRubro aRubro[RUBROS];



	if(Cliente_Init(aCliente,CLIENTES)==0 && Publicacion_Init(aPublicacion, PUBLICACIONES)==0)
	{
		Cliente_Hardcodeo(aCliente, CLIENTES);
		Publicacion_Hardcodeo(aPublicacion, PUBLICACIONES);
		i=1;
		iPub=1;
		do
		{
			GetOption("**********************\n>       MENU         <\n**********************\n\n"
				"1).Alta de cliente\n2).Modificar datos del cliente\n"
				"3).Baja de cliente\n4).Publicar\n5).Pausar Publicacion\n"
				"6).Reanudar Publicacion\n7).Imprimir Clientes\n"
				"8).Informar\n9).Salir\nIngrese una opcion: ","Ingrese un dato valido!\n",&opcion,2,1,9);

			switch(opcion)
			{
				case 1:
					system("cls");
					if(Cliente_Alta(aCliente,CLIENTES)==0)
					{
						printf(">>> Cliente dado de alta con exito! <<<\n");
						i++;
					}
					else
					{
						printf(">>> No pudo ser dado de alta! <<<\n");
					}
					break;
				case 2:
					if(i>0 && Cliente_Imprimir(aCliente, CLIENTES)==0)
					{

						switch(Cliente_Modificar(aCliente,CLIENTES))
						{
							case 0:
								printf(">>> Modificado con exito <<<\n");
								break;
							case 1:
								printf(">>> No se han realizado cambios <<<\n");
								break;
							case -1:
								printf(">>> No se pudo realizar ninguna modificacion <<<\n");
								break;
						}
					}
					else
					{
						printf("Pimero debe dar de alta un cliente!\n");
					}
					break;
				case 3:
				if (i>0 && Cliente_Imprimir(aCliente, CLIENTES)==0
						&& GetInt("Ingrese el Id del empleado que desea eliminar: ","No se encontro ese Id, ingrese un dato valido!\n",&bufferId,2)==0
						&& Cliente_BuscarPorId(aCliente, CLIENTES,bufferId,&bufferIndex)==0)
				{

					if(Publicacion_BuscarPorIddeCliente(aPublicacion, PUBLICACIONES,bufferId,&bufferIndexP)==0)
					{
						CliAndPub_ImprimirPubConCli(aPublicacion, PUBLICACIONES,bufferId);
					}
					else
					{
						printf("No tiene publicaciones!\n");
					}
					switch(CliAndPub_BajaCliente(aCliente, CLIENTES, bufferId, aPublicacion, PUBLICACIONES))
					{
						case 0:
							printf(">>> Eliminado con exito <<<\n");
							//i--;
							//iPub--;
							break;
						case 1:
							printf(">>> No se han realizado cambios <<<\n");
							break;
						case -1:
							printf(">>> No se pudo eliminar <<<\n");
							break;
					}
				}
				else
				{
					printf("Pimero debe dar de alta un cliente!\n");
				}
					break;
				case 4:
					if (i>0 && Cliente_Imprimir(aCliente, CLIENTES)==0)
					{
						CliAndPub_AltaPublicacion(aCliente, CLIENTES, aPublicacion, PUBLICACIONES);
						iPub++;
					}
					else
					{
						printf("Pimero debe dar de alta un cliente!\n");
					}
					break;
				case 5:
					if(i>0 && iPub>0)
					{
						opcionMod=5;
						if(Publicacion_Imprimir(aPublicacion, PUBLICACIONES)==0
								&& GetInt("Ingrese Id de la publicacion: ","No se encontro ese Id, ingrese un dato valido!\n",&bufferId,2)==0
								&& Publicacion_BuscarPorId(aPublicacion, PUBLICACIONES,bufferId,&bufferIndex)==0
								&& CliAndPub_ImprimirInfodeClixPub(aPublicacion, PUBLICACIONES,bufferIndex,aCliente, CLIENTES)==0)
						{
							switch(CliAndPub_Modificar(aCliente, CLIENTES, aPublicacion, PUBLICACIONES,bufferIndex,opcionMod))
							{
								case 0:
									printf(">>> Modificado con exito! <<<\n");
									break;
								case -1:
									printf(">>> No pudo ser modificado! <<<\n");
									break;
								case 1:
									printf(">>> No se realizaron cambios! <<<");
									break;
							}
						}
					}
					else
					{
						printf("Debe tener minimo el alta de un ciente y de una publicacion para ingresar a esta opcion!\n");
					}
					break;
				case 6:
					if(i>0 && iPub>0)
					{
						opcionMod = 6;
						if (Publicacion_Imprimir(aPublicacion, PUBLICACIONES) == 0
							&& GetInt("Ingrese Id de la publicacion: ","No se encontro ese Id, ingrese un dato valido!\n",&bufferId, 2)== 0
							&& Publicacion_BuscarPorId(aPublicacion, PUBLICACIONES,bufferId, &bufferIndex) == 0
							&& CliAndPub_ImprimirInfodeClixPub(aPublicacion,PUBLICACIONES, bufferIndex, aCliente, CLIENTES)== 0)
						{
							switch(CliAndPub_Modificar(aCliente, CLIENTES, aPublicacion,PUBLICACIONES, bufferIndex, opcionMod))
							{
								case 0:
									printf(">>> Modificado con exito! <<<\n");
									break;
								case -1:
									printf(">>> No pudo ser modificado! <<<\n");
									break;
								case 1:
									printf(">>> No se realizaron cambios! <<<\n");
									break;
							}
						}
					}
					else
					{
						printf("Debe tener minimo el alta de un ciente y de una publicacion para ingresar a esta opcion!\n");
					}
					break;
				case 7:
					if(i>0 && iPub>0)
					{
						CliAndPub_ImprimirCantDeAvisosActivos(aCliente, CLIENTES, aPublicacion, PUBLICACIONES);
					}
					else
					{
						printf("Debe tener minimo el alta de un ciente y de una publicacion para ingresar a esta opcion!\n");
					}
					break;
				case 8:
					if(i>0 && iPub>0)
					{
						do
						{
							if(GetOption("**********************\n>       SUBMENU      <\n**********************\n\n1).Cliente con mas avisos\n2).Cantidad de avisos pausados"
									"\n3).Rubro con mas avisos\n4).Volver al menu principal\n"
									"Ingrese una opcion: ","Ingrese un dato valido!\n",&opcionSubMenu,2,1,4)==0)
							{
								switch(opcionSubMenu)
								{
									case 1:
										indexInfo=Informes_CliconmasAvisos(aCliente, CLIENTES, aPublicacion, PUBLICACIONES);
										printf("El cliente con mas avisos es:\n%d %s %s\n",aCliente[indexInfo].idCliente,aCliente[indexInfo].nombre,aCliente[indexInfo].apellido);
										break;
									case 2:
										rtInfo=Informes_CantAvisosPausado(aPublicacion, PUBLICACIONES);
										printf("La cantidad de avisos pausados es de: %d\n",rtInfo);
										break;
									case 3:
										if(Informes_GenerarRubros(aRubro, RUBROS, aPublicacion)==0)
										{
											rtOtraInfo=Informes_RubroConMasAvisos(aRubro, RUBROS, aPublicacion, PUBLICACIONES);
											printf("El rubro con mas avisos es: %d\n",rtOtraInfo);
										}
										else
										{
											printf("Error!\n");
										}

										break;
									case 4:
										goBack=1;
										break;
								}
							}
						}while(goBack!=1);
					}
					else
					{
						printf("Debe tener minimo el alta de un ciente y de una publicacion para ingresar a esta opcion!\n");
					}
					break;
				case 9:
					if(GetChar("Seguro desea salir? (s/n): ","Ingrese un dato valido!\n",&bufferChar,2)==0)
					{
						salir=tolower(bufferChar);
						if(salir=='s')
						{
							printf("\n>>> SALIDA CON EXITO <<<\n\n\n");
							opcion=5;
						}
						else if(salir=='n')
						{
							opcion=0;
						}
					}
					break;
			}
			system("pause");
			system("cls");
		}while(opcion!=9);
	}
}

