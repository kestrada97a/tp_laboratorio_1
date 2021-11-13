#include "BibliotecaGeneral.h"

//brief genera un id automatico que se va a emplear junto a otra funcion del Employee
//param int id
//return int id
int automaticId(int id)
{
	id++;

	return id;
}


//brief muestra el menu principal
//param void
//return void
void MenuPrincipal()
{
	printf("Menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
     "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
     "3. Alta de empleado\n"
     "4. Modificar datos de empleado\n"
     "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    "10. Salir\n");
}


//brief muetra el menu de editor de empleados
//param void
//return void
void MenuDelEditor()
{
	printf(	"\t1- Modificar Nombre\n"
			"\t2- Modificar Hs Trabajadas\n"
			"\t3- Modificar Sueldo\n"
			"\t4- Volver al menu principal\n");

}

//brief pide un entero a ingresar
//param char mensaje[]
//return int numeroIngresado
int ingresarEntero(char mensaje[])
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n'))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}
//brief pide un entero a ingresar pero limitado con un maximo incluido
//param char mensaje[]
//return int numeroIngresado
int ingresarEnteroConMaximo(char mensaje[],int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

//brief pide un string a ingresar
//param char mensaje[], char stringIngresado
//return void
void pedirString(char mensaje[], char stringIngresado[])
{
	int corroboracion;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	corroboracion=validacionString(stringIngresado);
	lowerToUpper(stringIngresado);
	while(corroboracion ==-1)
	{
		printf("Digito invalido. Ingrese letras: ");
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		corroboracion=validacionString(stringIngresado);
		lowerToUpper(stringIngresado);
	}
}

//brief transforma la primer letra de una oracion a UpperCase, usado junto a la funcion pedirString
//param char array[]
//return void
void lowerToUpper(char array[])
{
	char auxiliar[51];
	strcpy(auxiliar,array);
	strlwr(auxiliar);
	for(int i=0; i<strlen(auxiliar);i++)
	{
		auxiliar[0] = toupper(auxiliar[0]);
		break;
	}
	strcpy(array,auxiliar);
}

//brief valida que solo se escriban letras en un string, usado junto a la funcion pedirString
//param char array[]
//return int rtn
int validacionString(char array[])
{
	int rtn=0;
	for(int i=0;i<strlen(array);i++)
	{
		if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
		{
			if(array[i]!=' ' || array[i-1]==' ')
			{
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

//brief mensaje de error para corroborar que se hayan procesado bien las cosas
//param int datoACORROBORAR, char mensaje[], char mensajeError[]
//return void
void MensajeDeError(int corroboracion, char mensaje[], char mensajeError[])
{

	if(corroboracion>=0)
	{
		printf("%s",mensaje);
	}else {
		printf("%s",mensajeError);
	}

}

