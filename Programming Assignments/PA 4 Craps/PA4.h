/*
	Progrmmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 2/26/2025
	Description: This program runs a program that represents the game "Craps." The player will bet, and roll two dice.
	The sum of the two dice determines if the game will continue or not. The player can quit in between eeach turn and
	will be asked to bet after each term if they opt to continue playing.
*/

#ifndef PA4_H
#define PA4_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> //rand(), srand()
#include <time.h> //time()

void display_menu(void);
int get_choice(void);
int roll_die(void);
void display_rules(void);
char back_to_menu(void);
int calculate_sum(int die_number1, int die_number2);
int get_bet(int balance, int bet);


#endif
