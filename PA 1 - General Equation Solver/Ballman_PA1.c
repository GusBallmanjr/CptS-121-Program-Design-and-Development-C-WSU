/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab 
	Date: 1/24/2025
	Description: The program prompts the user for imputs for newtons second law (i.e. acceleration and mass) and uses the equation to output the force. 
	After this, the program promts the user for the radius and the height of a cylinder and outputs the volume of the cylinder. Thirdly, the program will 
	prompt the user for a plaintext character and output a character that uses the plaintext character and the equation to derive a new charcter. Fourthly,
	the program will calculate the atomic mass of phosphate. Fifthly, the program will prompt the user for time, initial velocity, and initial height of a 
	projectile and the program will output the height the projectile reaches in meters. Sixthly, the program will prompt the user for power and reistance
	values in order to output the current of the circut in ampheres. Finally, the program will calculate the answer of the general equation (listed below).

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197 //Defines the constant Pi used in tasks 2 and task 7.
#define hydrogen_mass 1.008 //This line and the next two define the constants for teh hydrogen, oxygen, and phosphorous atoms used in task 4.
#define oxygen_mass 16
#define phosphorous_mass 30.97

int main(void)
{
	
	//Sixth Task:
	double current = 0.0, power = 0.0, res = 0.0, pow_res = 0.0;
	printf("Enter the power of the circut: \n"); //Allows the user to imput the value of power for the circut equation and then the scanf function adds the value to the data type for power.
	scanf("%lf", &power);

	printf("Enter the resistance of the circut: \n"); //Allows the user to imput the value of resistance for the circut equation and the scanf function adds the value to the data type for resistance.
	scanf("%lf", &res);

	pow_res = power / res; //Calculates the value for power divided by resistance for the circut equation
	current = sqrt(pow_res);
	printf("The current of the circut in Amperes is %.2lf \n", current); //Prints the value of the current of the circut on screen for the user to see.

	//Seventh Task:
	/* printf("The equation is y = (3/4) * x - z / (a mod 2) + pi \n"); //Prints the equation for the user to see so they know what they need to imput values for.
	printf("Enter the value of x: \n");  //Allows the user to imput the value of x for the equation and the scanf function adds the value to the data type for x.
	scanf("%lf", &x);

	printf("Enter the value of z: \n"); //Allows the user to imput the value of z for the equation and the scanf function adds the value to the data type for z.
	scanf("%lf", &z);

	printf("Enter the integer value of a: \n"); //Allows the user to imput the value of a for the equation and the scanf function adds the value to the data type for a.
	scanf("%d", &a);

	y = (((double) 3 / 4) * x) - (z / (a % 2)) + PI; //calculates the value of the equation using the imputs from the user.
	printf("The value of y after the imputs have been put into the equation is %.2lf \n"); //Prints the value of the calculated value of the equation on screen for the user to see. */


	return 0; //Returns zero so that we know the program ran successfully.
}