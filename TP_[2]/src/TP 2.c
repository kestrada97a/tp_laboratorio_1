/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Generala.h"
#define TAM 1000

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int idAutomatico=1;
	int auxiliar=0;
	float totalSalario=0;
	int totalEmpleados=0;
	float promedioSalario=0;
	int arribaDelPromedio=0;
	int flag =0;


	Employee list[TAM];

	initEmployees(list, TAM);

	do
	{
		int flag =0;
		menu();
		opcion=PedirEnteroAlternativo("Ingrese Opcion: \n",5);
		switch(opcion)
		{
		case 1:
		flag=1;
		addEmployee(list, TAM, &idAutomatico);
		break;
		case 2:
		if(flag==0)
		{
			printf("primero de de alta: \n");
		}
		else if(flag==1)
		{
		modificarEmpleado(list, TAM);
		}
		break;
		case 3:
		if(flag==0)
				{
				printf("primero de de alta: \n");
				}


			else if(flag==1){
		if(!removerSeleccion(list,TAM))
		{
		printf("operacion existosa");
		}
			}
		break;
		case 4:
		if(flag==0)
		{
		printf("primero de de alta: \n");}
		else
		{
		auxiliar = PedirEnteroAlternativo("Ingrese Opcion: \n"
				"	1| sortEmployees por apellido/sector\n"
				"	2| total y promedio de los salarios, y cuantos empleados superan el promedio.\n", 2);

			if(auxiliar==1)
			{
				auxiliar=PedirEnteroAlternativo("Ingrese opcion: \n"
						"1. sortEmployees por apellido.\n"
						"2. sortEmployees por sector.\n",2);
				switch(auxiliar)
						{
							case 1:
							sortEmployees(list,TAM,1);
							printEmployees(list, TAM);
							break;
							case 2:
							sortEmployees(list,TAM,2);
							printEmployees(list, TAM);
							break;
						}
			}
			if(auxiliar==2)
			{

				calculoEmployees(list, TAM, &totalSalario, &totalEmpleados);
				if(totalEmpleados==0)
				{
					printf("error no se puede dividir por 0\n");
				}
				else
				{
				promedioSalario=totalSalario/totalEmpleados;
				arribaDelPromedio=bestEmployees(list, TAM, promedioSalario);
				printf("El total de los empleados es %d, con un salario total de %.2f, y su promedio de %.2f; aquellos que superan el salario promedio son %d\n",totalEmpleados,totalSalario,promedioSalario,arribaDelPromedio);
				}
			}
		}
			break;



		}

	}while(opcion!=5);


	return EXIT_SUCCESS;
}
