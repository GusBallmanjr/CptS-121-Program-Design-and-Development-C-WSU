#include "Lab2.h"

int main(void)
{
	double theta = 0.0, distance = 0.0, velocity = 0.0, time = 0.0, height = 0.0;

	theta = enter_theta();
	distance = enter_distance();
	velocity = enter_velocity();
	time = calc_time(theta, distance, velocity);
	height = calc_height(theta, distance, velocity, time);

	printf("The height of the projectile is: %.2lf", height);

	return 0;
}