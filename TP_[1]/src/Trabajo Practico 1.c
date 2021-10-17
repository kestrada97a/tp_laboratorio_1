/*
 ============================================================================
 Trabajo practico numero 1
 Estrada Kevin, Division F
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
int main(void)
{
	setbuf(stdout,NULL);
	float a;
	float b;
	int opcion;
	printf("1. Ingresar 1er operando (A=x)\n");
	printf("2. Ingresar 1er operando (B=y)\n");
	printf("3. Calcular las siguientes\n");
	printf("   a) Calcular la suma (A + B)\n");
	printf("   b) Calcular la resta (A - B)\n");
	printf("   c) Calcular la division (A/B)\n");
	printf("   d) Calcular la multiplicacion (A*B)\n");
	printf("   e) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("Seleccione una opción: \n");
	scanf("%d",&opcion);


	while(opcion!=5)
	{
		switch(opcion)
		{
		case 1:
			a = ingresarFloat();
			break;
		case 2:
			b = ingresarFloat();
			break;
		case 3:
			sumarDatos(a,b);
			restarDatos(a,b);
			dividirDatos(a,b);
			multiplicarDatos(a,b);
			factorialDatos(a);
			factorialDatos(b);
			break;
		case 4:
			printf("a) El resultado de %.1f + %.1f es: %.1f\n",a,b,sumarDatos(a,b));
			printf("b) El resultado de %.1f - %.1f es: %.1f\n",a,b,restarDatos(a,b));
			if (!(b==0))
			{
			printf("c) El resultado de %.1f/%.1f es: %.2f\n",a,b,dividirDatos(a,b));
			}
			else
			{
				printf("no es posible dividir por cero\n");
			}
			printf("d) El resultado de %.1f*%.1f es: %.2f\n",a,b,multiplicarDatos(a,b));
			if((a<0 || b<0) || (a != (int)a || b != (int) b))
				{
				printf("el factorial trabaja solo con numeros naturales\n");
				}
			else
			{
				printf("e) El factorial de %.1f es: %.1f y el factorial de %.1f es: %.1f\n",a,factorialDatos(a),b,factorialDatos(b));
			}
			break;
		}///separador mágico.

		printf("\n");
		printf("1. Ingresar 1er operando (A=%.1f)\n",a);
		printf("2. Ingresar 1er operando (B=%.1f)\n",b);
		printf("3. Calcular las siguientes\n");
		printf("   a) Calcular la suma (%.1f + %.1f)\n",a,b);
		printf("   b) Calcular la resta (%.1f - %.1f)\n",a,b);
		printf("   c) Calcular la division (%.1f/%.1f)\n",a,b);
		printf("   d) Calcular la multiplicacion (%.1f*%.1f)\n",a,b);
		printf("   e) Calcular el factorial (%.1f! y %.1f!)\n",a,b);
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("\n");
		printf("Seleccione una opción: \n");
		scanf("%d",&opcion);
		printf("\n");

	}


	return EXIT_SUCCESS;
}
