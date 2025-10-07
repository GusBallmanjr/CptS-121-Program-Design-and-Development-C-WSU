/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
*/

#include "Lab4.h"

int main(void)
{
	//Task 1:
	double weight = 0.0, height_ft = 0.0, height_in = 0.0, bmr = 0.0, calories = 0.0;
	int age = 0;
	char gender = '\0', activity = '\0';
	FILE* input_stream = NULL, * output_stream = NULL;

	input_stream = fopen("inputs.txt", "r");

	age = read_integer(input_stream);
	gender = read_character(input_stream);
	weight = read_double(input_stream);
	height_ft = read_double(input_stream);
	activity = read_character(input_stream);

	height_in = convert_ft_in(height_ft);

	bmr = calculate_bmr(weight, height_in, age, gender);
	calories = calculate_calorie_intake(bmr, activity);

	output_stream = fopen("output.txt", "w");
	print_double_calorie(output_stream, calories);

	//task 2:
	double bonus = 0.0, number1 = 0.0, number2 = 0.0, number3 = 0.0, number4 = 0.0, number5 = 0.0, max_value = 0.0;
	char asg = '\0', rmvp = '\0', wsmvp = '\0', gga = '\0', ssa = '\0', hrc = '\0', bac = '\0';

	printf("Did the player make an All-Star Game appearance? (Enter y for yes, and n for NO) ");
	scanf(" %c", &asg);

	printf("Was the player the regualar season MVP? \n");
	scanf(" %c", &rmvp);

	printf("Was the player the World Series MVP? \n");
	scanf(" %c", &wsmvp);

	printf("Did the player earn the Gold Glove award? \n");
	scanf(" %c", &gga);

	printf("Did the player earn the Silver Slugger award? \n");
	scanf(" %c", &ssa);

	printf("Was the player the Home Run Champ? \n");
	scanf(" %c", &hrc);

	printf("Was the player the batting average champ? \n");
	scanf(" %c", &bac);

	bonus = calculate_bonus(asg, rmvp, wsmvp, gga, ssa, hrc, bac);

	print_double_bonus(output_stream, bonus);
	
	number1 = read_double(input_stream);
	number2 = read_double(input_stream);
	number3 = read_double(input_stream);
	number4 = read_double(input_stream);
	number5 = read_double(input_stream);

	max_value = find_max(number1, number2, number3, number4, number5);

	fclose(input_stream);

	print_double_max(output_stream, max_value);

	fclose(output_stream);
	return 0;
}