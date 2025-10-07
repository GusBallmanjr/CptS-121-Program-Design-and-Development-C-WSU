/*
	Programmer: Gus Ballman
	Class: cptS 121; Lab Section 07
	Lab 05
*/

#ifndef LAB5_H
#define LAB5_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double read_calculate_sum(FILE* infile);
double determine_tax_bracket(double sum);
double read_calculate_average(FILE* infile);
int greatest_common_divisor(int number1, int number2);
double determine_max(FILE* infile);
double determine_min(FILE* infile);

#endif