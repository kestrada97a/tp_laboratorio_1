#include "Employee.h"
#include <stdio.h>
//brief Crea memoria para un nuevo elemento empleado
//param void
//param void
//return pEmployee
Employee* employee_new()
{
	Employee* pEmployee;
	pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}


//brief	agrega los datos al puntero del empleado
//param char* idStr, char* nombreStr, char* HorasTrabajadasStr, char* SueldoStr
//return pEmployee
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee;
	pEmployee = employee_new();
	if(pEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		employee_setId(pEmployee, atoi(idStr));
		employee_setNombre(pEmployee,nombreStr);
		employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
		employee_setSueldo(pEmployee, atoi(sueldoStr));
	}
	return pEmployee;
}

//brief eliminar un elemento empleado
//param Employee* this
//return void
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

//brief agrega un id a un elemento empleado
//param int id
//return int
int employee_setId(Employee* this,int id)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->id=id;
		rtn = 1;
	}

	return rtn;
}

//brief selecciona un id de un elemento empleado
//param int id
//retur int
int employee_getId(Employee* this,int* id)
{
	int rtn = -1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		rtn = 1;
	}

	return rtn;
}

//brief agrega un nombre a un elemento empleado
//param int id
//retur int
int employee_setNombre(Employee* this,char* nombre)
{
	int rtn = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		rtn = 1;
	}

	return rtn;
}

//brief selecciona un nombre de un elemento empleado
//param int id
//retur int

int employee_getNombre(Employee* this,char* nombre)
{
	int rtn = -1;
	if(this!=NULL && nombre !=NULL)
	{
		strcpy(nombre,this->nombre);
		rtn = 1;
	}

	return rtn;
}


//brief agrega HorasTrabajadas a un elemento empleado
//param int id
//retur int
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		rtn = 1;
	}

	return rtn;
}


//brief selecciona las horasTrabajadas de un elemento empleado
//param int id
//retur int
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn = -1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		rtn = 1;
	}

	return rtn;
}


//brief agrega un sueldo a un elemento empleado
//param int id
//retur int
int employee_setSueldo(Employee* this,int sueldo)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->sueldo=sueldo;
		rtn = 1;
	}

	return rtn;
}


//brief selecciona un sueldo de un elemento empleado
//param int id
//retur int
int employee_getSueldo(Employee* this,int* sueldo)
{
	int rtn = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		rtn = 1;
	}

	return rtn;
}


//brief busca el Id de un empleado en especifico
//param char mensaje[]
//retur int idBuscado
int employee_findEmployeeId(LinkedList* pArrayListEmployee, char mensaje[])
{
	int idAux;
	int idDeLista;
	int idBuscado=-1;
	int lenArray;
	Employee* pEmployeeAuxiliar;

	if(pArrayListEmployee!=NULL)
	{
		idAux=ingresarEntero(mensaje);
		lenArray=ll_len(pArrayListEmployee);

		for(int i=0;i<lenArray;i++)
	{
		pEmployeeAuxiliar=ll_get(pArrayListEmployee,i);
		employee_getId(pEmployeeAuxiliar,&idDeLista);

		if(idDeLista==idAux)
		{
			idBuscado=i;
			break;
		}
		}
	}


		return idBuscado;
}


//brief imprime un empleado en especifico
//param int i
//retur void
void employee_printEmployee(LinkedList* pArrayListEmployee, int i)
{
	Employee* pEmployee;
	int id;
	char nombre[100];
	int horasTrabajadas;
	int sueldo;

	pEmployee= ll_get(pArrayListEmployee,i);
	employee_getId(pEmployee,&id);
	employee_getNombre(pEmployee,nombre);
	employee_getHorasTrabajadas(pEmployee,&horasTrabajadas);
	employee_getSueldo(pEmployee,&sueldo);
	printf("%d\t%s\t%d\t%d\n", id,nombre,horasTrabajadas,sueldo);

}

//brief ordena empleados por nombre
//param void* primerDato, void* segundoDato
int employee_sortByName(void* primerDato, void* segundoDato)
{
	Employee* unEmpleado;
	Employee* otroEmpleado;
	int comparacion =-1;
	unEmpleado=(Employee*) primerDato;
	otroEmpleado=(Employee*) segundoDato;
	if(unEmpleado!=NULL && otroEmpleado!=NULL)
	{
		comparacion = strcmp(unEmpleado->nombre, otroEmpleado->nombre);
	}
	return comparacion;
}
