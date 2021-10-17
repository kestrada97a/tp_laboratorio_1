#include "Generala.h"



///pide un entero
/// parametros: mensaje que se desea poner, y el numero maximo
int pedirEntero(char message[], int num){
    int option;
    printf("%s", message);
    scanf("%d", &option);
    fflush(stdin);
    while(option <0 || option > num)
    {
        printf("\nERROR.%s", message);
        scanf("%d", &option);
        fflush(stdin);
    }
    return option;
}
///funcion que fue encontrada en internet, verifica q sea un entero y lo devuelve
/// el array, con el numero maximoi
int PedirEnteroAlternativo(char mensaje[], int maximo)
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


///ingresa un float
/// parametros: mensaje que se desea poner
float pedirFloat(char mensaje [])
{
	float numeroIngresado;
	printf("%s \n",mensaje);
	scanf("%f",&numeroIngresado);
	fflush(stdin);
	return numeroIngresado;
}

///funcion que fue encontrada en internet
/// verifica que sea un flotante y lo devuelve
float PedirFlotanteAlternativo(char mensaje[])
{
		float numeroIngresado;
		char term;
		printf("%s",mensaje);
		while(scanf("%f%c", &numeroIngresado, &term) != 2 || term != '\n')
		{
			printf("Digito invalido. %s",mensaje);
			fflush(stdin);
		}
		return numeroIngresado;
}

///pide un string
/// parametros: mensaje que se desea poner, y el lugar donde se desea guardar el string
void pedirString(char mensaje [], char stringAuxiliar[])
{
	int auxiliar;
	printf("%s \n",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringAuxiliar);
	auxiliar=ValidacionDeStrings(stringAuxiliar);
	UpperLower(stringAuxiliar);
	while(auxiliar==-1)
	{
		printf("Error. Reingrese solo letras: \n");
		fflush(stdin);
		scanf("%[^\n]",stringAuxiliar);
		auxiliar=ValidacionDeStrings(stringAuxiliar);
		UpperLower(stringAuxiliar);
	}

}


///es el menu
void menu (void)
{
	printf("Elija una opcion: \n"
			"1. ALTAS\n"
			"2. MODIFICAR\n"
			"3. BAJA\n"
			"4. INFORMAR\n"
			"	1| ordenar por apellido/sector\n"
			"	2| total y promedio de los salarios, y cuantos empleados superan el promedio.\n"
			"5. SALIR.\n");

}

///mensaje de alerta en caso de desearlo
/// parametros: numero de control, mensaje en caso de que vaya todo bien, y en caso de que vaya todo mal
void AlertMessage(int num, char messageA[], char messageB[]){
    if(num==0){
        printf("%s\n",messageA);
    } else{
        printf("%s\n",messageB);
    }

}

///valida que sea un string(cadena de caracteres)
/// parametros: el array que se va a validar
int ValidacionDeStrings(char array[])
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

///cambia las primeras letras en minuscula a mayuscula
/// te pide como parametro el array que vas a modificar
void UpperLower(char array[])
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



