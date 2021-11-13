#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "BibliotecaGeneral.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int opcion;
	int auxId=1000;
	int corroboracion;
	int flagMenu=-1;
	LinkedList* pArrayListEmployee=NULL;
	pArrayListEmployee=ll_newLinkedList();
	do
	{
		MenuPrincipal();
		opcion=ingresarEnteroConMaximo("Ingrese opcion: ", 11);
		switch(opcion)
		{
		case 1:
			auxId=controller_loadFromText("data.csv", pArrayListEmployee);
			MensajeDeError(auxId, "carga con exito\n", "error en la carga\n");
			break;
		case 2:
			auxId=controller_loadFromBinary("data.csv", pArrayListEmployee);
			MensajeDeError(auxId, "carga con exito\n", "error en la carga\n");
			break;
		case 3:
			auxId=automaticId(auxId);
			corroboracion=controller_addEmployee(pArrayListEmployee, auxId);
			MensajeDeError(corroboracion, "carga con exito\n", "error en la carga\n");
			flagMenu = 1;

			break;
		case 4:
			if(flagMenu==1)
			{
					controller_ListEmployee(pArrayListEmployee);
					corroboracion=controller_editEmployee(pArrayListEmployee);
					MensajeDeError(corroboracion, "carga con exito\n", "error en la carga\n");
			}
			else
			{
				printf("Cargue un empleado primero.\n");
			}
			break;
		case 5:
			if(flagMenu==1)
			{
				controller_ListEmployee(pArrayListEmployee);
				corroboracion=controller_removeEmployee(pArrayListEmployee);
				MensajeDeError(corroboracion, "eliminacion con exito\n", "error en la eliminacion\n");

			}
			else
			{
				printf("Cargue un empleado primero.\n");
			}
			break;
		case 6:
			if(flagMenu==1)
			{
				corroboracion=controller_ListEmployee(pArrayListEmployee);
			}
			else
			{
				printf("Cargue un empleado primero.\n");
			}
			break;
		case 7:
			if(flagMenu==1)
			{
				corroboracion=controller_sortEmployee(pArrayListEmployee);
			}
			else
			{
				printf("Cargue un empleado primero.\n");
			}
			break;
		case 8:
			if(flagMenu==1)
			{
				corroboracion=controller_saveAsText("data.csv", pArrayListEmployee);
				MensajeDeError(corroboracion, "accion exitosa\n", "error en la accion\n");
			}
			else
			{
				printf("Cargue un empleado primero.\n");
			}
			break;
		case 9:
			if(flagMenu==1)
			{
				corroboracion=controller_saveAsBinary("data.csv", pArrayListEmployee);
			}
			else
			{
				printf("Cargue un empleado primero.\n");
			}
			break;
		case 10:
			printf("adios");
			break;

		}

	}while(opcion!=10);
	ll_deleteLinkedList(pArrayListEmployee);




    return 0;
}

