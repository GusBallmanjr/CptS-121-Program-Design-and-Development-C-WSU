/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab section: 07
	Description: This program is a text based version of 5 card poker. The Player will be delt five cards from a shuffled deck and will have two chances to replace up to three cards. They will have a chance to bet and will be playing against the dealer.
*/

#ifndef PA7_H
#define PA7_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card
{
	int face_index,
		suit_index;
} Card;

typedef struct hand
{
	Card cards[5];
} Hand;

int display_menu(void);
int get_choice(void);
void display_rules(void);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], Hand* hand, int number_of_cards_to_draw, int* number_of_cards_already_drawn, int card_starting_point);
int which_hand(Hand hand);
void combination(int combo, int player);
void print_hand(Hand hand, const char* face[13], const char* suit[4]);


#endif