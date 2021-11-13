/*
 * BibliotecaGeneral.h
 *
 *  Created on: 8 nov. 2021
 *      Author: brake
 */

#ifndef BIBLIOTECAGENERAL_H_
#define BIBLIOTECAGENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

void MenuPrincipal(void);
void MenuDelEditor(void);
int ingresarEntero(char mensaje[]);
int ingresarEnteroConMaximo(char mensaje[],int maximo);
void pedirString(char mensaje[], char stringIngresado[]);
void lowerToUpper(char array[]);
int validacionString(char array[]);
void MensajeDeError(int corroboracion, char mensaje[], char mensajeError[]);
int automaticId(int id);

#endif /* BIBLIOTECAGENERAL_H_ */
