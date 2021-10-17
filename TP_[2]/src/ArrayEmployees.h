/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: brake
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

int initEmployees(Employee list[], int len);
int printEmployees(Employee list[], int length);
void showEmployee(Employee empleado);


int automaticId(int id);
int addEmployee(Employee list[], int len, int* idAutomatico);
int removeEmployee(Employee list[], int len, int id);

int removerSeleccion(Employee list[], int len);
int buscarEmpleadoPorId(Employee list[], int len, int id);
int modificarEmpleado(Employee list[],int len);
int sortEmployees(Employee list[], int len, int opcion);

int contadorEmployees(Employee list[], int len);
float acumuladorSalary(Employee list[],int len);
int calculoEmployees(Employee list[], int len, float *totalSalario, int *totalEmpleados);
int bestEmployees(Employee list[],int len, float promedioSalario);

#endif /* ARRAYEMPLOYEES_H_ */
