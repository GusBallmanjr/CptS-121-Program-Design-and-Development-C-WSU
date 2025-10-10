/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
*/

#ifndef LAB4_H
#define LAB4_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double convert_ft_in(double height_ft);
double read_double(FILE* infile);
int read_integer(FILE* infile);
char read_character(FILE* infile);
double calculate_bmr(double weight, double height, int age, char gender);
double calculate_calorie_intake(double bmr, char activity_level);
void print_double_calorie(FILE* outfile, double number);
double calculate_bonus(char all_star, char reg_mvp, char world_series_mvp, char gold_glove, char silver_slugger, char home_run_champ, char batting_average_champ);
void print_double_bonus(FILE* outfile, double number);
double find_max(double number1, double number2, double number3, double number4, double number5);
void print_double_max(FILE* outfile, double number);

#endif