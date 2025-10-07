#include "Lab2.h"

int main(void)
{
	//Task 1:
	double weight = 0.0, height_in = 0.0, bmi = 0.0, height_bmi = 0.0;

	weight = get_weight();
	height_bmi = get_height();

	height_in = convert_ft_in(height_bmi);

	bmi = calc_bmi(weight, height_in);

	display_bmi(bmi);

	//Task 2:
	double theta = 0.0, distance = 0.0, velocity = 0.0, time = 0.0, height = 0.0;

	theta = enter_theta();
	distance = enter_distance();
	velocity = enter_velocity();
	time = calc_time(theta, distance, velocity);
	height = calc_height(theta, distance, velocity, time);

	printf("The height of the projectile is: %.2lf ft\n", height);

	//Task 3:
	double score1 = 0.0, score2 = 0.0, score3 = 0.0, score4 = 0.0, score5 = 0.0, score6 = 0.0, p1 = 0.0, p2 = 0.0, p3 = 0.0, grade = 0.0;

	score1 = get_score(1); //exam 1 score
	score2 = get_score(2); //exam 2 score
	score3 = get_score(3); //lab 1 score
	score4 = get_score(4); //lab 2 score
	score5 = get_score(5); //project 1 score
	score6 = get_score(6); //project 2 score

	p1 = calc_average(1, score1, score2); //exam percentage
	p2 = calc_average(2, score3, score4); //lab percentage
	p3 = calc_average(3, score5, score6); //project percentage

	grade = calc_grade(p1, p2, p3);

	printf("The percentage in the class is %.2lf\n%", grade);
	return 0;
}

