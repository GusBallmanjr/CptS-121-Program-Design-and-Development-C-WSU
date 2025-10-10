/*
	Programmer: Gus Ballman
	Class: CptS 121, Lab Section 07
	Date: 1/31/25
	Description: Prompt the user for a series of inputs that are used for a series of equations and the calculated results of
	those equations is printed on the screen for the user to see. The same equations as PA 1 but modularized with user defined functions.
*/
#include "PA2.h"

/*  Frunction Name: calculate_newtons_second_law
	Date Created: 1/29/2025
	Description: This function calculates the force applied to an object using Newton's second law and the mass and acceleration of the object.
	Inputs: The inputs are the mass of the object and the acceleration of the object, both come from prompting the user (see main).
	Output: The output is the force applied to the object in Newtons.
*/
double calculate_newtons_second_law(double mass, double acc)
{
	return (mass * acc);
}

/*  Frunction Name: calculate_volume_cylinder
	Date Created: 1/29/2025
	Description: This function calculates the volume of a cylinder.
	Inputs: The inputs are the radius of the cylinders circular face and the height of the cylinder, both come from prompting the user (see main).
	Output: The output is the volume of the cylinder in cm^3.
*/
double calculate_volume_cylinder(double radius, double height)
{
	return (PI * (height * pow(radius, 2)));
}

/*  Frunction Name: encode_character
	Date Created: 1/29/2025
	Description: This function does mathmatical operations on an ascii character using ascii characters.
	Inputs: The input of the function is a plaintext ascii character that is obtained from the user. 
	Output: The output is the correlating ascii character to the nukmber that is obtained after the mathmatical operations are preformed.
*/
char encode_character(char plaintext)
{
	return (plaintext - '7') + 'A';
}

/*  Frunction Name: calc_phos_atom_mass
	Date Created: 1/29/2025
	Description: This function calculates the atomic mass of a Phosphate molecule.
	Inputs: There are no inputs to this function, it uses constants defined in the header file (PA2.h).
	Output: The output is the atomic mass of a Phosphate molecule in amu.
*/
double calc_phos_atom_mass(void)
{
	return (3 * hydrogen_mass) + (4 * oxygen_mass) + phosphorous_mass;
}

/*  Frunction Name: total_height_proj
	Date Created: 1/29/2025
	Description: This function calculates the total height in ft that the projectile will reach.
	Inputs: The inputs of this function are the time the projectile is in motion, the inital velocity of the projectile, and the inital height of the projectile.
	Output: The output is the total height the projectile reaches.
*/
double total_height_proj(double time_proj, double int_vel, double height_proj)
{
	return (-16 * pow(time_proj, 2)) + (int_vel * time_proj) + height_proj;
}

/*  Frunction Name: calc_current
	Date Created: 1/29/2025
	Description: This function calculates the current of a circut.
	Inputs: The inputs of this function are the power value of the circut and the resistance value of the circut.
	Output: The output is the current in amps of the circut.
*/
double calc_current(double power, double res)
{
	return (sqrt((power / res)));
}

/*  Frunction Name: calc_y
	Date Created: 1/29/2025
	Description: This function calculates the value of y using the polynomial equation.
	Inputs: The inputs of this function are the value for x, the value for y, and an integer value for a.
	Output: The output is the value of y after the mathmatical operations of the equation have been done.
*/
double calc_y(double x, double z, int a)
{
	return ((((double)3 / 4) * x) - ((double)z / (a % 2)) + PI);
}