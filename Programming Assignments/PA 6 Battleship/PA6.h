/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 4/7/2025
	Description: This program is a text based version of the game "Battleship." It is a two player game in which one of the players is the computer. The user - player one - will set their ships (or have them randomly placed) and try and guess the location of player two's ships (which were randomly placed). If player one gets a hit, they guess again; if they miss, the computer attacks. If all five ships are sunk by either player, than that player wins and the game can restart if the user so chooses.
*/

#ifndef PA6_H
#define PA6_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct coordinate
{
	int row;
	int column;
} Coordinate;

typedef struct cell
{
	int occupied;
	char symbol;
} Cell;

typedef struct stats
{
	int	num_hits,
		num_misses,
		total_shots;
} Stats;

typedef struct game_info
{
	int wins,
		losses,
		total_games_played;
} Game_info;


int display_menu(void);
int get_choice(void);
void display_rules(void);
void initialize_board(Cell board[][11]);
void print_board(Cell board[11][11]);
void player_placement(Cell myboard[11][11], int cells[], char ship_char[], Coordinate placement, int turn, char ship[][20]);
void random_player_placement(Cell myboard[11][11], int ship_row, int cells[], char ship_char[], Coordinate placement);
void computer_placement(Cell compboard[11][11], int ship_row, int cells[], char ship_char[], Coordinate placement_comp);
void which_ship_was_hit(int number_of_hits[5], Cell board[11][11], Coordinate coord);
int did_sink(int number_of_hits[5], int player);


#endif