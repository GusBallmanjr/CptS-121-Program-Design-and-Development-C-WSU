/*
	Programmer: Gus Ballman
	Class: CptS 121, Lab Section 07
	Date: 2/7/2025
	Description: This program reads GPA, Class_standing, age, and id numbers for five different students from an
	input file and uses those values to calculate the average GPA, the average class_standing, the average age,
	the lowest GPA, the highest GPA, and the standard deviation of the GPAs. With these calculated values, the
	program will print the values into an output file.
*/

#ifndef PA3_h
#define PA3_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
	Frunction Name: read_double()
	Date Created: 1/4/2025
	Description: This function reads a double precision number from the input file.
	Inputs: The input is the name of the input variable that is attached to the input file.
	Output: The output is a double precision number read from the input file.
*/
double read_double(FILE*);

/*
	Frunction Name: read_integer()
	Date Created: 1/4/2025
	Description: This function reads an integer number from the input file.
	Inputs: The input is the name of the input variable that is attached to the input file.
	Output: The output is an integer number read from the input file.
*/
int read_integer(FILE*);

/*
	Frunction Name: calculate_sum()
	Date Created: 1/4/2025
	Description: This function calculated the sum of five double precision numbers.
	Inputs: The inputs are five different double precision numbers.
	Output: The output is the double precision value of the sum of the five numbers.
*/
double calculate_sum(double, double, double, double, double);

/*
	Frunction Name: calculate_mean()
	Date Created: 1/4/2025
	Description: This function caclulates the mean or average of a double precision number divided by an integer.
	Inputs: The input is a double precision value that represents a sum of numbers.
	Output: The output is the double precision value of the average value of the "sum" value divided by however many inputs there where to calculate the sum.
*/
double calculate_mean(double, int);

/*
	Frunction Name: calculate_deviation()
	Date Created: 1/4/2025
	Description: This function caclulates the deviation a double precision number has from a calculated mean.
	Inputs: The inputs are two double precision numbers that represents the number from which it is calculating the dveiation and the calculated value of the mean.
	Output: The output is a double precision number that represents the deviation a number has from a calculated mean.
*/
double calculate_deviation(double, double);

/*
	Frunction Name: calculate_variance()
	Date Created: 1/4/2025
	Description: This function caclulates the variance of a set of five different deviation values.
	Inputs: The inputs are five different double precision deviation values and an integer number that represents however many deviation values are inputed (in this case it would be five).
	Output: The output is a double precision number that represents the variance a set of five different deviation numbers have divided by the number of deviation values inputed.
*/
double calculate_variance(double, double, double, double, double, int);

/*
	Frunction Name: calculate_standard_deviation()
	Date Created: 1/4/2025
	Description: This function caclulates the standard deviation from a variance value.
	Inputs: The input is a double precision number for the variance value.
	Output: The output is a double precision number that represents the calculated standard deviation.
*/
double calculate_standard_deviation(double);

/*
	Frunction Name: find_max()
	Date Created: 1/4/2025
	Description: This function finds the maximum value out of a set of five different inputed numbers.
	Inputs: The inputs are five different double precision numbers.
	Output: The output is a double precision number that represents the maximum value calculated from a set of five different numbers.
*/
double find_max(double, double, double, double , double);

/*
	Frunction Name: find_min()
	Date Created: 1/4/2025
	Description: This function finds the minimum value out of a set of five different inputed numbers.
	Inputs: The inputs are five different double precision numbers.
	Output: The output is a double precision number that represents the minimum value calculated from a set of five different numbers.
*/
double find_min(double, double, double, double, double);

/*
	Frunction Name: print_double()
	Date Created: 1/4/2025
	Description: This function prints a double precision value into an output file.
	Inputs: The inputs are the name of the variable assosiated with the output file and the double precision number in which it will print into the output file.
	Output: There is no output(s).
*/
void print_double(FILE*, double);

#endif