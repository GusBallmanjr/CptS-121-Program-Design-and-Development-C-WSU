/*
	Programmer: Gus Ballman
	Class: CptS 121, Lab Section 07
	Date: 2/7/2025
	Description: This program reads GPA, Class_standing, age, and id numbers for five different students from an
	input file and uses those values to calculate the average GPA, the average class_standing, the average age,
	the lowest GPA, the highest GPA, and the standard deviation of the GPAs. With these calculated values, the
	program will print the values into an output file.
*/

#include "PA3.h"

int main(void)
{
	FILE* input_stream = NULL, * output_stream = NULL; //define pointer variables that correspond with the input and output files.
	input_stream = fopen("input.dat", "r");

	//definition of variables used in main():
	double id1 = 0.0, id2 = 0.0, id3 = 0.0, id4 = 0.0, id5 = 0.0,
		gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0,
		age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0,
		sum_gpa = 0.0, sum_class = 0.0, sum_age = 0.0, stnd_dev_gpa = 0.0,
		gpa_max = 0.0, gpa_min = 0.0, gpa_mean = 0.0, age_mean = 0.0,
		class_stand_mean = 0.0, deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0,
		deviation4 = 0.0, deviation5 = 0.0, variance = 0.0, class_stand_sum = 0.0;

	int class_standing1 = 0, class_standing2 = 0, class_standing3 = 0,
		class_standing4 = 0, class_standing5 = 0;

	//read all data from the input file:
	id1 = read_double(input_stream); //The defining of the id numbers is unnecessary but I was not sure how to skip over the values when reading them from the input file.
	gpa1 = read_double(input_stream);
	class_standing1 = read_integer(input_stream);
	age1 = read_double(input_stream);

	id2 = read_double(input_stream);
	gpa2 = read_double(input_stream);
	class_standing2 = read_integer(input_stream);
	age2 = read_double(input_stream);

	id3 = read_double(input_stream);
	gpa3 = read_double(input_stream);
	class_standing3 = read_integer(input_stream);
	age3 = read_double(input_stream);

	id4 = read_double(input_stream);
	gpa4 = read_double(input_stream);
	class_standing4 = read_integer(input_stream);
	age4 = read_double(input_stream);

	id5 = read_double(input_stream);
	gpa5 = read_double(input_stream);
	class_standing5 = read_integer(input_stream);
	age5 = read_double(input_stream);

	fclose(input_stream);

	//Output and calculation of variables that will be printed in output file:
	output_stream = fopen("output.dat", "w");

	sum_gpa = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	gpa_mean = calculate_mean(sum_gpa, 5);

	deviation1 = calculate_deviation(gpa1, gpa_mean);
	deviation2 = calculate_deviation(gpa2, gpa_mean);
	deviation3 = calculate_deviation(gpa3, gpa_mean);
	deviation4 = calculate_deviation(gpa4, gpa_mean);
	deviation5 = calculate_deviation(gpa5, gpa_mean);

	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);
	stnd_dev_gpa = calculate_standard_deviation(variance);

	gpa_max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);
	gpa_min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);

	class_stand_sum = calculate_sum(class_standing1, class_standing2, class_standing3, class_standing4, class_standing5);
	class_stand_mean = calculate_mean(class_stand_sum, 5);

	sum_age = calculate_sum(age1, age2, age3, age4, age5);
	age_mean = calculate_mean(sum_age, 5);

	//print calculated values into the output file:
	print_double(output_stream, gpa_mean);
	print_double(output_stream, class_stand_mean);
	print_double(output_stream, age_mean);
	print_double(output_stream, stnd_dev_gpa);
	print_double(output_stream, gpa_min);
	print_double(output_stream, gpa_max);

	fclose(output_stream);

	return 0;
}