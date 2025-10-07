/*
	Programmer: Gus Ballman
	Class: cptS 121; Lab Section 07
	Lab 05
*/

#include "Lab5.h"

int main(void)
{
	//Task 1: *************************************************
	FILE *input_stream1 = fopen("salaries.txt", "r");
	double sum = 0.0;
	char income_level = '\0';

	sum = read_calculate_sum(input_stream1);

	fclose(input_stream1);

	income_level = determine_tax_bracket(sum);

	printf("Income level is %c\n", income_level);

	//Task 2: **************************************************
	FILE* input_stream2 = fopen("data.txt", "r");
	FILE* output_stream2 = fopen("outputs.txt", "w");
	double average = 0.0;
	
	average = read_calculate_average(input_stream2);
	fprintf(output_stream2, "The average is %.4lf.", average);

	fclose(input_stream2);
	fclose(output_stream2);

	//Task 3: *************************************************
	int gcd = 0, num1 = 0, num2 = 0;

	printf("Enter an integer: ");
	scanf("%d", &num1);

	printf("Enter an integer: ");
	scanf("%d", &num2);

	gcd = greatest_common_divisor(num1, num2);
	printf("The greatest common divisor is %d.\n", gcd);

	//Task 4: *************************************************
	double max = 0.0, min = 0.0;
	FILE* input_stream3 = fopen("max_min.txt", "r");
	FILE* input_stream4 = fopen("min.txt", "r");

	max = determine_max(input_stream3);
	printf("The maximum value found in file was %.2lf\n", max);

	min = determine_min(input_stream4);
	printf("The minimum value found in file was %.2lf\n", min);

	fclose(input_stream3);
	fclose(input_stream4);

	return 0;
}