#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int idAux=-1;
	FILE* pFile;
	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL)
		{
			idAux=parser_EmployeeFromText(pFile,pArrayListEmployee);
		}
		fclose(pFile);
	}
	return idAux;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int idAux=-1;
	FILE* pFile;
	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile!=NULL)
		{
			idAux=parser_EmployeeFromBinary(pFile ,pArrayListEmployee);
		}
	fclose(pFile);
	}
	return idAux;




}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
	int rtn=-1;
	char nombre[100];
	int horasTrabajadas;
	int sueldo;
	Employee* pEmployee;
	pEmployee = employee_new();
	pedirString("Ingrese nombre: ", nombre);
	horasTrabajadas=ingresarEntero("Ingrese horas trabajadas: ");
	sueldo=ingresarEntero("Ingrese sueldo: ");

	employee_setId(pEmployee,id);
	employee_setNombre(pEmployee,nombre);
	employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
	employee_setSueldo(pEmployee,sueldo);

	if(pArrayListEmployee!=NULL && pEmployee!=NULL)
	{
		rtn=ll_add(pArrayListEmployee, pEmployee);
	}


	    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int opcion;
	int posicionEmpleado;
	Employee* pEmployee;
	posicionEmpleado = employee_findEmployeeId(pArrayListEmployee, "Ingrese id del empleado que desea modificar:\n");
	if(posicionEmpleado!=-1)
	{
		char nombre[100];
		int horasTrabajadas;
		int sueldo;
		pEmployee = ll_get(pArrayListEmployee,posicionEmpleado);
		do{
			MenuDelEditor();
			opcion = ingresarEnteroConMaximo("Ingrese opcion: ",4);

			switch(opcion)
			{
			case 1:
			pedirString("Ingrese nombre: ", nombre);
			employee_setNombre(pEmployee,nombre);
			break;
			case 2:
			horasTrabajadas=ingresarEntero("Ingrese horas trabajadas: ");
			employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
			break;
			case 3:
			sueldo=ingresarEntero("Ingrese sueldo: ");
			employee_setSueldo(pEmployee,sueldo);
			break;
			}
		}while(opcion != 4);
		rtn=1;
		}
	 return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int opcion;
	int posicionEmpleado;
	Employee* pEmployee;
	posicionEmpleado = employee_findEmployeeId(pArrayListEmployee, "Ingrese ID del empleado que desea modificar:\n");
	if(posicionEmpleado!=-1)
	{
		printf("Esta seguro que desea eliminar? 1:si 2:no ");
		opcion=ingresarEnteroConMaximo("Ingrese opcion: ",3);
		if(opcion==1 && pArrayListEmployee!=NULL)
		{
			pEmployee = ll_get(pArrayListEmployee,posicionEmpleado);
			employee_delete(pEmployee);
			rtn=ll_remove(pArrayListEmployee,posicionEmpleado);
		}
	}
    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int lenList;
	lenList=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL)
	{
	 printf("ID\tNombre\tHs trabajadas\tSueldo\n");
	 for(int i=0;i<lenList;i++)
	 {
		 employee_printEmployee(pArrayListEmployee, i);
	 	rtn=1;
	 }
	}
		return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	printf("Ordenando Alfabeticamente por nombre. Espere un momento...\n");
	rtn=ll_sort(pArrayListEmployee,employee_sortByName,1);
	return rtn;


}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
	pFile=fopen(path,"w");
	if(pFile!=NULL)
	{
		rtn=SaveEmployeesAsText(pArrayListEmployee,pFile);
	}
	fclose(pFile);
	}
	  return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int rtn=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
    	pFile=fopen(path,"wb");
    	if(pFile!=NULL)
    	{
    		rtn=SaveEmployeesAsText(pArrayListEmployee,pFile);
    	}
    	fclose(pFile);
    }
    return rtn;
}


