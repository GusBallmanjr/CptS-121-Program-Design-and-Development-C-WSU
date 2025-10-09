/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 4/2/2025
*/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct employee
{
	char name[100]; // employee's name - last, first
	char title; // title 'B' or 'M'
	double hours_worked; // total number of hours worked
	double payrate; // pay rate per hour
	double payment; // total payment for the pay period – you will compute!
} Employee;

int collect_data(FILE* input_stream, Employee employee_data[200]);
void compute_overtime(Employee employee_data[200], int number_of_employees, double overtime[200]);
void determine_payment(Employee employee_data[200], int number_of_employees, double overtime[200]);
double total_payroll(Employee employee_data[200], int number_of_employees);
double max_payment(Employee employee_data[200], int number_of_employees);
double min_payment(Employee employee_data[200], int number_of_employees, double max);


#endif
