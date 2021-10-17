#include "ArrayEmployees.h"
#include "Generala.h"
#define TRUE 1
#define FALSE 0
#define INFINITO 999999999

///inicia todos los empleados como Vacios.
/// parametros: el array de los empleados, con su tamaño
int initEmployees(Employee list[], int len)
{
	int rtn=-1;
	if(list!=NULL && len>0)
	{
	for(int i=0;i<len;i++)
	{
		list[i].isEmpty=TRUE;
		rtn=0;
	}
	}
	return rtn;

}

///muestra un solo empleado, es para usarlo junto con otra funcion
/// parametros: el dato que va a mostrar
void showEmployee(Employee empleado)
{
		printf("%1d	%3s	%16s	%15.2f%18d\n",empleado.id,empleado.name, empleado.lastName,empleado.salary,empleado.sector);
}

///usa la funcion de showEmployee para mostrar todos los empleados del array
/// parametros: el array de los empleados, con su tamaño
int printEmployees(Employee list[], int length)
{
	int rtn=-1;
	printf("ID	NOMBRE		APELLIDO		 SALARIO		SECTOR\n");
	for(int i = 0; i<length; i++)
	{
		if (list[i].isEmpty==FALSE)
		{
			showEmployee(list[i]);
			rtn=0;
		}

	}
	return rtn;;
}




///asigna id automaticamente
/// paramtro, el id generico
int automaticId(int id)
{
	id++;
	return id;
}

///carga empleados
/// parametros: el array de los empleados, con su tamaño, junto con el puntero del id automatico
int addEmployee(Employee list[], int len, int* idAutomatico)
{
	int rtn=-1;
	int auxID;
	int posicionACargar=-1;
	auxID=*idAutomatico;

	if(list!=NULL && list>0)
	{
		for(int i=0;i<len;i++)
		{
			if (list[i].isEmpty==TRUE)
			{
				posicionACargar=i;
				break;
			}
		}

		if(posicionACargar!=-1)
		{
			list[posicionACargar].id = auxID;
			pedirString("Ingrese nombre: ", list[posicionACargar].name);
			pedirString("Ingrese apellido: ", list[posicionACargar].lastName);
			list[posicionACargar].salary = PedirFlotanteAlternativo("Ingrese salario: ");
			list[posicionACargar].sector = PedirEnteroAlternativo("Ingrese sector: ",INFINITO);
			auxID++;
			list[posicionACargar].isEmpty=FALSE;

			rtn=0;
			*idAutomatico = auxID;
		}


	}

return rtn;
}

///Remueve un empleado especifico se usa junto con la funcion de abajo
/// parametros: el array de los empleados, con su tamaño, y el id de empleado
int removeEmployee(Employee list[], int len, int id)
{
	int retorno = -1;
	if (list != NULL && len >0 && id>0)
	{
		for (int i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty ==FALSE)
			{
				list[i].isEmpty = TRUE;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// remueve un empleado especifico del ARRAY que usa como parametro
/// parametro del array con su tamaño
int removerSeleccion(Employee list[], int len)
{
	int retorno=-1;
	int idBaja;
	int msjError;
	if(list != NULL && len>0)
	{
		if(!printEmployees(list, len))
		{
		idBaja= PedirEnteroAlternativo("Ingrese el ID del empleado que desea remover: \n", 1000);

		if(!removeEmployee(list, len, idBaja))
		{
			msjError=0;
			retorno=0;
		}

		}
		AlertMessage(msjError, "Se elimino el ID\n", "Error - no se elimino\n");

	}
	return retorno;
}


///busca un empleado por su id especifico
///parametro de array con su tamaño y el id
int buscarEmpleadoPorId(Employee list[], int len, int id)
{
	int rtn=1;
	if(list !=NULL && len>0)
	{
		for (int i =0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE && list[i].id==id)
			{
				rtn=i;
				break;
			}
		}
	}
	return rtn;
}

///modifica un empleado
/// parametro el array con su tamaño
int modificarEmpleado(Employee list[],int len)
{
	int submenu;
	int id;
	int rtn=-1;
	if (list!=NULL && list>0)
	{
		printEmployees(list, len);
		id=PedirEnteroAlternativo("Ingrese opcion: ", 9999);
		for(int i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty == FALSE)
			{
			 printf("Que desea modificar: \n"
				     "1) Modificar nombre\n"
				     "2) Modificar apellido\n"
				     "3) Modificar salario\n"
				     "4) Modificar sector\n");
			 submenu = PedirEnteroAlternativo("Ingrese opcion: ", 4);
			 switch(submenu)
			 {
			 case 1:
				 pedirString("ingrese nombre: ", list[i].name);
				 break;
			 case 2:
				 pedirString("ingrese apellido: ", list[i].lastName);
				 break;
			 case 3:
				 list[i].salary=PedirFlotanteAlternativo("Ingrese salario: ");
				 break;
			 case 4:
				 list[i].sector=PedirEnteroAlternativo("Ingrese sector: ", 99999);
				 break;
			 }
			 rtn=0;
			 break;
			}
		}
	}
	return rtn;
}

///ordena un empleado del array especifico
/// parametro del ar ray con su tamaño, y la opcion a la cual se quiere sortEmployees
int sortEmployees(Employee list[], int len, int opcion)
{
	int i;
	int j;
	Employee auxiliar;
	int rtn=-1;
	switch(opcion)
	{
	case 1:
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(strcmp(list[i].lastName,list[j].lastName)>0)
			{
				auxiliar = list[i];
				list[i]=list[j];
				list[j]=auxiliar;
				rtn=0;
			}
		}
	}
	break;
	case 2:
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(list[i].sector>list[j].sector)
			{
				auxiliar=list[i];
				list[i]=list[j];
				list[j]=auxiliar;
				rtn=0;
			}
		}
	}
	}
	return rtn;

}


///contador de empleados necesaria para el submenu del 4.
/// parametro del array con su tamaño
int contadorEmployees(Employee list[],int len)
{
	int auxiliarEmployees=0;
	if(list!=NULL && list>0)
	{
		for(int i =0;i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				auxiliarEmployees++;
			}
		}
	}

	return auxiliarEmployees;
}
///acumulador de salarios necesaria para el submenu del 4.
/// parametro del array con su tamaño
float acumuladorSalary(Employee list[],int len)
{
	float acumulador=0;
	if(list!=NULL && list>0)
	{
		for (int i=0; i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				acumulador=acumulador+list[i].salary;
			}
		}
	}

	return acumulador;
}

///hace el calculo necesario para el submenu del 4.
/// parametro del array con su tamaño, mas el puntero del salario total y el empleado total anteriores
int calculoEmployees(Employee list[], int len, float *totalSalario, int *totalEmpleados)
{
	int rtn=-1;
	float auxiliarSalario;
	int auxiliarEmpleados;
	if(list!= NULL && list>0)
	{
		auxiliarSalario=acumuladorSalary(list, len);
		auxiliarEmpleados=contadorEmployees(list, len);
		rtn=0;
	}
	*totalSalario=auxiliarSalario;
	*totalEmpleados=auxiliarEmpleados;
	return rtn;
}

///hace el calculo necesario para el submenu del 4.
/// parametro del array con su tamaño
int bestEmployees(Employee list[],int len, float promedioSalario)
{
	int auxiliar=0;
	if(list!= NULL && list>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].salary>promedioSalario)
			{
				auxiliar++;
			}
		}
	}
	return auxiliar;

}
