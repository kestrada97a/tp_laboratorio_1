/*
 * Generala.h
 *
 *  Created on: 16 oct. 2021
 *      Author: brake
 */

#ifndef GENERALA_H_
#define GENERALA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


float pedirFloat(char mensaje []);
void pedirString(char mensaje [], char stringAuxiliar[]);
int pedirEntero(char message[], int num);
int PedirEnteroAlternativo(char mensaje[], int maximo);
float PedirFlotanteAlternativo(char mensaje[]);

int ValidacionDeStrings(char array[]);
void menu (void);
int validacionInt (int opcion, int min, int max);
int validacionLetra(int opcion);
void AlertMessage(int num, char messageA[], char messageB[]);
int subMenu(void);
void UpperLower(char array[]);




#endif /* GENERALA_H_ */
