/*
	Programmer: Gus Ballman
	Class: CptS 121, Lab Section 07
	Date: 1/31/25
	Description: Prompt the user for a series of inputs that are used for a series of equations and the calculated results of
	those equations is printed on the screen for the user to see. The same equations as PA 1 but modularized with user defined functions.
*/
#include "PA2.h"

int main(void)
{
	double mass = 0.0, acc = 0.0, force = 0.0, radius = 0.0, height_cy = 0.0, vol_cy = 0.0, atom_mass = 0.0,
		height_proj = 0.0, time_proj = 0.0, int_vel = 0.0, height_proj_tot = 0.0, x = 0.0, y = 0.0, z = 0.0;
	int a = 0;

	//Task 1:
	printf("Enter the mass of the object in kg: ");
	scanf("%lf", &mass);

	printf("Enter the acceleration of the object is m/s^2: \n");
	scanf("%lf", &acc);

	force = calculate_newtons_second_law(mass, acc);
	printf("The force (in Newtons) of the object is %.2lf", force);

	//task 2:
	printf("Enter the radius of the cylinder (in cm)? ");
	scanf("%lf", &radius);

	printf("Enter the height of the cylinder (in cm)? \n");
	scanf("%lf", &height_cy);

	vol_cy = calculate_volume_cylinder(radius, height_cy);
	printf("The volume of the cylinder (in cm cubed) is %.2lf \n", vol_cy);

	//Task 3:
	char plaintext = '\0', encoded_char = '\0';

	printf("Enter a plaintext character: \n");
	scanf(" %c", &plaintext);

	encoded_char = encode_character(plaintext);
	printf("Plaintext: %c\n", encoded_char);

	//Task 4:
	atom_mass = calc_phos_atom_mass();
	printf("The atomic mass of a Phosphate atom is %.2lf \n", atom_mass);

	//Task 5:
	printf("Enter the time the projectile is moving in seconds: \n");
	scanf("%lf", &time_proj);

	printf("Enter the inital velocity of the projectile in m/s: \n");
	scanf("%lf", &int_vel);

	printf("Enter the inital height of the projectile in meters: \n");
	scanf("%lf", &height_proj);

	height_proj_tot = total_height_proj(time_proj, int_vel, height_proj);
	printf("The height of the projectile in meters is %.2lf \n", height_proj_tot);

	//Task 6:
	double current = 0.0, power = 0.0, res = 0.0;

	printf("Enter the power of the circut: \n");
	scanf("%lf", &power);

	printf("Enter the resistance of the circut: \n");
	scanf("%lf", &res);

	current = calc_current(power, res);
	printf("The current of the circut in Amperes is %.2lf \n", current);

	//Task 7:
	printf("The equation is y = (3/4) * x - z / (a mod 2) + pi \n");
	printf("Enter the value of x: \n");
	scanf("%lf", &x);

	printf("Enter the value of z: \n");
	scanf("%lf", &z);

	printf("Enter the integer value of a: \n");
	scanf("%d", &a);

	y = calc_y(x, y, a);
	printf("The value of y after the imputs have been put into the equation is %.2lf \n", y);

	return 0;
}