/*
	Programmer: Gus Ballman
	Class: CptS 121, Lab Section 07
	Date: 1/31/25
	Description: Prompt the user for a series of inputs that are used for a series of equations and the calculated results of 
	those equations is printed on the screen for the user to see. The same equations as PA 1 but modularized with user defined functions.
*/
#ifndef PA_2
#define PA_2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double calculate_newtons_second_law(double, double);
double calculate_volume_cylinder(double, double);
char encode_character(char);
double calc_phos_atom_mass(void);
double total_height_proj(double, double, double);
double calc_current(double, double);
double calc_y(double, double, int);

#define PI 3.141592653589
#define hydrogen_mass 1.008
#define oxygen_mass 16
#define phosphorous_mass 30.97

#endif