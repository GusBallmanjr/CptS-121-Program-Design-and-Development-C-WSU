#include "Lab2.h"

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