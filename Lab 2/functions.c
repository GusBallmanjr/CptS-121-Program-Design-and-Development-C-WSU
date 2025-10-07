#include "Lab2.h"

//Task 1 Functions:
double get_weight(void)
{
	double weight = 0.0;
	printf("Enter your weight in pounds: ");
	scanf("%lf", &weight);

	return weight;
}

double get_height(void)
{
	double height_ft = 0.0;
	printf("Enter your height in feet: ");
	scanf("%lf", &height_ft);

	return height_ft;
}

double convert_ft_in(double height_ft)
{
	double height_in = 0.0;
	height_in = (height_ft * 12);

	return height_in;
}

double calc_bmi(double weight, double height_in)
{
	double bmi = 0.0;
	bmi = (weight / pow(height_in, 2)) * 703;

	return bmi;
}

void display_bmi(double bmi)
{
	printf("Your BMI is: %.1lf\n", bmi);

	return 0;
}

//Task 2 Functions:
double enter_theta(void)
{
	double theta = 0.0;
	printf("Enter the value of angle theta in radians: ");
	scanf("%lf", &theta);

	return theta;
}

double enter_distance(void)
{
	double distance = 0.0;
	printf("Enter the distance from the target in feet: ");
	scanf("%lf", &distance);

	return distance;
}

double enter_velocity(void)
{
	double velocity = 0.0;
	printf("Enter the inital velocity of the target in ft/sec: ");
	scanf("%lf", &velocity);

	return velocity;
}

double calc_time(double theta, double distance, double velocity)
{
	return (distance) / (velocity * cos(theta));
}

double calc_height(double theta, double distance, double velocity, double time)
{
	return (velocity * sin(theta) * time) - ((G * pow(time, 2)) / 2);
}

//Task 3 Functions:
double get_score(int score_num)
{
	double score = 0.0;
	printf("Enter score number %d: ", score_num);
	scanf("%lf", &score);

	return score;
}

double calc_average(int score_type, double score_1, double score_2) //A score type of 1 designates an exam, a score type of 2 designates a lab, and a score type of 3 designates a project.
{
	if (score_type == 1)
	{
		return ((score_1 * .3) + (score_2 * .3));
	}
	else if (score_type == 2)
	{
		return ((score_1 * .05) + (score_2 * .05));
	}
	else //Score type of 3
	{
		return ((score_1 * .15) + (score_2 * .15));
	}
}

double calc_grade(double per1, double per2, double per3)
{
	return (per1 + per2 + per3);
}