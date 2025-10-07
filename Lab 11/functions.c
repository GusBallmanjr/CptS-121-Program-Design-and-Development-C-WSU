/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 4/2/2025
*/

#include "Header.h"

int collect_data(FILE* input_stream, Employee employee_data[200])
{
	int count = 0;
	char temp[100] = "", space[1] = " ";
	while (!feof(input_stream))
	{
		fscanf(input_stream, "%s", employee_data[count].name);
		strcat(employee_data[count].name, space);
		fscanf(input_stream, "%s", temp);
		strcat(employee_data[count].name, temp);
		fscanf(input_stream, " %c", &employee_data[count].title);
		fscanf(input_stream, "%lf", &employee_data[count].hours_worked);
		fscanf(input_stream, "%lf", &employee_data[count].payrate);
		count++;
	}
	return count;
}

void compute_overtime(Employee employee_data[200], int number_of_employees, double overtime[200])
{
	for (int i = 0; i < number_of_employees; i++)
	{
		overtime[i] = employee_data[i].hours_worked - 80.0;
	}
}

void determine_payment(Employee employee_data[200], int number_of_employees, double overtime[200])
{
	for (int i = 0; i < number_of_employees; i++)
	{
		if (employee_data[i].title == 'B')
		{
			employee_data[i].payment = ((employee_data[i].hours_worked - overtime[i]) * employee_data[i].payrate) + ((1.5 * employee_data[i].payrate) * overtime[i]);
		}
		else if (employee_data[i].title == 'M')
		{
			employee_data[i].payment = ((employee_data[i].hours_worked - overtime[i]) * employee_data[i].payrate) + ((1.8 * employee_data[i].payrate) * overtime[i]);
		}
	}

}

double total_payroll(Employee employee_data[200], int number_of_employees)
{
	double total_payroll = 0;
	for (int i = 0; i < number_of_employees; i++)
	{
		total_payroll += employee_data[i].payment;
	}
	return total_payroll;
}

double max_payment(Employee employee_data[200], int number_of_employees)
{
	double max = employee_data[0].payment;
	for (int i = 1; i < number_of_employees; i++)
	{
		if (employee_data[i].payment > max)
		{
			max = employee_data[i].payment;
		}
	}
	return max;
}

double min_payment(Employee employee_data[200], int number_of_employees, double max)
{
	double min = max;
	for (int i = 0; i < number_of_employees; i++)
	{
		if (employee_data[i].payment < min)
		{
			min = employee_data[i].payment;
		}
	}
	return min;

}
