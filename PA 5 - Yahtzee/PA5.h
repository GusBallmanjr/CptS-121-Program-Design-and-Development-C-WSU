/*
	Programmer: Gus Ballman
	Class: Cpts 121; Lab 07
	Date: 3/20/2025
	Description: This program is a two player digital version of the dice game Yahtzee.
*/

#ifndef PA5_H
#define PA5_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int random_num(void);
int display_menu(void);
int get_choice(void);
void display_rules(void);
int score_available(int score1[], int score2[], int player_number);
int what_score(int dice[], int score1[], int score2[], int player_number, int scoring_option);



#endif
