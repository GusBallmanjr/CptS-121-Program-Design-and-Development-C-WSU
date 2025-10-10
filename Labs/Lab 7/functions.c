/*

*/

#include "Lab7.h"

void sentence_creator(char article[][10], char noun[][10], char verb[][10], char preposition[][10], char sentence[])
{
	int value = 0, counter = 0, size = 0;
	char space[] =  " " ;

	for (counter = 0; counter < 20; counter++)
	{
		value = rand() % 5;
		strcat(sentence, article[value]);
		strcat(sentence, space);

		value = rand() % 5;
		strcat(sentence, noun[value]);
		strcat(sentence, space);

		value = rand() % 5;
		strcat(sentence, verb[value]);
		strcat(sentence, space);

		value = rand() % 5;
		strcat(sentence, preposition[value]);
		strcat(sentence, space);

		value = rand() % 5;
		strcat(sentence, article[value]);
		strcat(sentence, space);

		value = rand() % 5;
		strcat(sentence, noun[value]);

		sentence[0] = toupper(sentence[0]);

		printf("%s.\n", sentence);
		strcpy(sentence, "\0");
	}
	
}

void print_board(Cell board[100][100], int n)
{
	for (int index = 0; index < n; index++)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%c", board[index][i].symbol);
		}
		printf("\n");
	}
}

int did_score(Cell board[100][100], int n)
{
	int score = 0;
	for (int index = 0; index < n; index++) //horizontal
	{
		for (int i = 0; i < n; i++)
		{
			if (board[index][i].symbol == 'X');
			{
				score++;
				if (score == n)
				{
					return 1;
				}
			}
		}
		score = 0;
	}
}