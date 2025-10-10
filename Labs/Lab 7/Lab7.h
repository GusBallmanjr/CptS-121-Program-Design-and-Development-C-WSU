/*

*/

#ifndef LAB7_H
#define LAB7_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

typedef struct coordinate
{
	int row;
	int column;
} Coordinate;

typedef struct cell
{
	int occupied;
	char symbol;
	Coordinate location;
} Cell;

typedef struct game_info
{
	int wins;
	int losses;
	int total_games_played;
} Game_info;

void sentence_creator(char article[][10], char noun[][10], char verb[][10], char preposition[][10], char sentence[]);
void print_board(Cell board[100][100], int n);


#endif