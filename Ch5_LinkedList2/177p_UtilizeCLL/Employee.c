#include <stdio.h>
#include "Employee.h"

void ShowEmployeeInfo(Employee* pe)
{
	printf("Name: %s\n", pe->name);
	printf("ID: %d\n", pe->ID);
}