/*
	Programmer: Gus Ballman
	Class: cptS 121; Lab Section 07
	Lab 05
*/

#include "Lab5.h"

double read_calculate_sum(FILE* infile)
{
	double sum = 0.0, a = 0.0;
	while (!feof(infile))
	{
		fscanf(infile, "%lf", &a);
		sum = sum + a;
	}
	return sum;
}

double determine_tax_bracket(double sum)
{
	char income_level = '\0';

	if (sum < 15000)
	{
		income_level = 'l';
		return income_level;
	}
	else if (sum < 200000)
	{
		income_level = 'm';
		return income_level;
	}
	else
	{
		income_level = 'h';
		return income_level;
	}
}

double read_calculate_average(FILE *infile)
{
	double b = 0.0, sum = 0.0;
	int num = 0;

	while (!feof(infile))
	{
		fscanf(infile, "%lf", &b);
		sum = sum + b;
		num++;
	}
	return (sum / num);
}

int greatest_common_divisor(int number1, int number2)
{
	int num1 = abs(number1), num2 = abs(number2);
	int gcd = 0, r1 = num1 % num2, r2 = 0, r3 = 0;

	if (r1 == 0)
	{
		gcd = num2;
		return gcd;
	}

	else
	{
		r2 = num2 % r1;
		if (r2 == 0)
		{
			gcd = r1;
			return gcd;
		}
		while (r2 != 0)
		{
			r3 = r1 % r2;
			r1 = r2 % r3;
			r2 = r3 % r1;
		}
		gcd = r1;
	}
	return gcd;
}

double determine_max(FILE* infile)
{
	double a = 0.0, max = 0.0;
	while (!feof(infile))
	{
		fscanf(infile, "%lf", &a);
		if (a > max)
		{
			max = a;
		}
	}
	return max;
}

double determine_min(FILE* infile)
{
	double a = 0.0, min = 1000000000000000000;
	while (!feof(infile))
	{
		fscanf(infile, "%lf", &a);
		if (a < min)
		{
			min = a;
		}
	}
	return min;
}