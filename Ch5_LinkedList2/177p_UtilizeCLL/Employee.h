#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#define _CRT_SECURE_NO_WARNINGS

typedef struct _employee
{
	char name[10];
	int ID;
} Employee;

void ShowEmployeeInfo(Employee* pe);

#endif