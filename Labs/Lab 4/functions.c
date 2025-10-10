/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
*/

#include "Lab4.h"

double convert_ft_in(double height_ft)
{
	return (height_ft * 12);
}

double read_double(FILE* infile)
{
	double id = 0.0;
	fscanf(infile, "%lf", &id);
	return id;
}

int read_integer(FILE* infile)
{
	int a = 0;
	fscanf(infile, "%d", &a);
	return a;
}

char read_character(FILE* infile)
{
	char b = '\0';
	fscanf(infile, " %c", &b);
	return b;
}

double calculate_bmr(double weight, double height, int age, char gender)
{
	if (gender == 'F')
	{
		return (655 + (4.35 * weight) + (4.7 * height) - (4.7 * age));
	}
	else
	{
		return (66 + (6.23 * weight) + (12.7 * height) - (6.8 * age));
	}
}
double calculate_calorie_intake(double bmr, char activity_level)
{
	if (activity_level == 'S')
	{
		return (bmr * 1.2);
	}
	else if (activity_level == 'L')
	{
		return (bmr * 1.375);
	}
	else if (activity_level == 'M')
	{
		return (bmr * 1.55);
	}
	else if (activity_level == 'H')
	{
		return (bmr * 1.725);
	}
	else if (activity_level == 'E')
	{
		return (bmr * 1.9);
	}
}

void print_double_calorie(FILE* outfile, double number)
{
	fprintf(outfile, "Daily calorie intake is %.2lf calories.\n", number);
}

double calculate_bonus(char all_star, char reg_mvp, char world_series_mvp, char gold_glove, char silver_slugger, char home_run_champ, char batting_average_champ)
{
	double bonus = 0.0;
	if (all_star == 'y')
	{
		bonus = bonus + 25000;
	}
	if (reg_mvp == 'y')
	{
		bonus = bonus + 75000;
	}
	if (world_series_mvp == 'y')
	{
		bonus = bonus + 100000;
	}
	if (gold_glove == 'y')
	{
		bonus = bonus + 50000;
	}
	if (silver_slugger == 'y')
	{
		bonus = bonus + 35000;
	}
	if (home_run_champ == 'y')
	{
		bonus = bonus + 25000;
	}
	if (batting_average_champ == 'y')
	{
		bonus = bonus + 25000;
	}
	return bonus;
}

void print_double_bonus(FILE* outfile, double number)
{
	fprintf(outfile, "The player's bonus is $%.2lf.\n", number);
}

double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max_score = number1;
	if (number2 > max_score)
	{
		max_score = number2;
	}
	if (number3 > max_score)
	{
		max_score = number3;
	}
	if (number4 > max_score)
	{
		max_score = number4;
	}
	if (number5 > max_score)
	{
		max_score = number5;
	}
	return max_score;
}

void print_double_max(FILE* outfile, double number)
{
	fprintf(outfile, "The maximum value is %.2lf.\n", number);
}