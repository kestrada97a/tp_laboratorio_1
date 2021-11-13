#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BibliotecaGeneral.h"
#include "LinkedList.h"
#include "Employee.h"

#ifndef PARSER_H_
#define PARSER_H_


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int SaveEmployeesAsText(LinkedList* pArrayListEmployee, FILE* path);
int SaveEmployeesAsBinary(LinkedList* pArrayListEmployee, FILE* path);


#endif /* PARSER_H_ */
