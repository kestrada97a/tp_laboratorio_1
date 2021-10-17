#include "biblioteca.h"
///@GeneralBrief las funciones de abajo estan todas con float debido a la posibilidad de que el usuario ingrese numeros con decimales.
/// @fn float ingresarEntero(void)
/// @brief esta funcion ingresa un float
///
/// @return devuelve un float
float ingresarFloat (void)
{
	float entero;
	printf("escriba un numero: ");
	scanf("%f",&entero);

	return entero;
}
/// @fn float sumarDatos(float, float)
/// @brief esta funcion realiza una suma entre 2 parametros (float)
///
/// @param a
/// @param b
/// @return devuelve el resultado como un float
float sumarDatos(float a, float b)
{

	return a+b;

}
/// @fn float restarDatos(float, float)
/// @brief esta funcion realiza una resta entre 2 parametros (float)
///
/// @param a
/// @param b
/// @return devuelve el resultado como un float
float restarDatos(float a,float b)
{
	return a-b;
}

/// @fn float dividirDatos(float, float)
/// @brief esta funcion realiza una division entre 2 parametros (float)
///
/// @param a
/// @param b
/// @return devuelve el resultado como un float
float dividirDatos(float a,float b)
{
	return a/b;
}

/// @fn float multiplicarDatos(float, float)
/// @brief esta funcion realiza una multiplicacion entre 2 parametros (float)
///
/// @param a
/// @param b
/// @return devuelve el resultado como un float
float multiplicarDatos(float a,float b)
{
	return a*b;
}

/// @fn float factorialDatos(float)
/// @brief esta funcion realiza el factorial de un parametro (float)
///
/// @param a
/// @return y tambien lo devuelve como un float
float factorialDatos(float a)
{
	float factorial=1;
	for (; a>0;a--)
	{
		factorial = factorial*a;
	}

	return factorial;
}
