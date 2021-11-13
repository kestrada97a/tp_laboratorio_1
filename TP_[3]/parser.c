#include "parser.h"
#include <stdio.h>
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int idAux;
	char idStr[100];
	char nombreStr[100];
	char horasTrabajadasStr[100];
	char sueldoStr[100];
	Employee* pEmployee;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
		pEmployee = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
		ll_add(pArrayListEmployee, pEmployee);
		employee_getId(pEmployee,&idAux);
		}
	    return idAux;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int idAux=-1;
	int i=0;
	Employee* pEmployee;
	while(!feof(pFile))
	{
		pEmployee=employee_new();
		fread(pEmployee,sizeof(pEmployee),1,pFile);
		if (pEmployee!=NULL)
		{
			i++;
			pEmployee=ll_get(pArrayListEmployee, i);
			employee_getId(pEmployee,&idAux);
		}
	}
	return idAux;

}
//brief Guarda los datos de los empleados en el archivo data.csv(modo texto)
//param path char
//param pArrayListEmlpoyee LinkedList*
//return int
int SaveEmployeesAsText(LinkedList* pArrayListEmployee, FILE* path)
{
	int rtn=-1;
	Employee* pEmployee;
	int id;
	char nombre[100];
	int horasTrabajadas;
	int sueldo;
	int length;
	length = ll_len(pArrayListEmployee);
	fprintf(path,"ID,Nombre,Horas Trabajadas,Sueldo\n");
	for(int i=0;i<length;i++)
	{
		pEmployee=ll_get(pArrayListEmployee,i);
		employee_getId(pEmployee,&id);
		employee_getNombre(pEmployee,nombre);
		employee_getHorasTrabajadas(pEmployee,&horasTrabajadas);
		employee_getSueldo(pEmployee,&sueldo);
		fprintf(path,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
		rtn=1;
	}
	return rtn;
}

//brief Guarda los datos de los empleados en el archivo data.csv(modo binario)
//param path char
//param pArrayListEmlpoyee LinkedList*
//return int

int SaveEmployeesAsBinary(LinkedList* pArrayListEmployee, FILE* path)
{
	int rtn=-1;
	Employee* pEmployee;
	int length;
	length = ll_len(pArrayListEmployee);
	for(int i=0;i<length;i++)
	{
		pEmployee=ll_get(pArrayListEmployee,i);
		fwrite(pEmployee,sizeof(pEmployee),1,path);
		rtn=1;
	}
	return rtn;
}
