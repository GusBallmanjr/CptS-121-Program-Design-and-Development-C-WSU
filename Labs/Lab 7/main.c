/*

*/

#include "Lab7.h"

int main(void)
{
	srand((unsigned int)time(NULL));

	//Task 1:
	char article[5][10] = {"the", "a", "one", "some", "any"};
	char noun[5][10] = { "boy", "girl", "dog", "town", "car" };
	char verb[5][10] = { "drove", "jumped", "ran", "walked", "skipped" };
	char preposition[5][10] = { "to", "from", "over", "under", "on" };
	char sentence[100] = { '\0' };

	sentence_creator(article, noun, verb, preposition, sentence);

	//Task 2:
	printf("\n\n");
	system("pause");
	system("cls");
	Cell board[100][100];
	int n = 0;

	printf("Enter n for an n x n tic tac toe board: ");
	scanf("%d", &n);

	for (int index = 0; index < n; index++)
	{
		for (int i = 0; i < n; i++)
		{
			board[index][i].occupied = 0;
			board[index][i].symbol = '-';
			board[index][i].location.row = index;
			board[index][i].location.column = i;
		}
	}
	
	int goes_first = 0;// rand() % 2;
	int game_mode = 0;
	Coordinate coord = { 0, 0 };

	if (goes_first == 0) //Player goes first
	{
		while (game_mode == 0)
		{
			print_board(board, n);
			printf("Enter the coordinate to place your X (row then column): ");
			scanf("%d", &coord.row);
			scanf("%d", &coord.column);

			while (board[coord.row - 1][coord.column - 1].occupied != 0);
			{
				printf("Invalid Coordinate. Please Try Again.\n");
				scanf("%d", &coord.row);
				scanf("%d", &coord.column);
			}

			if (board[coord.row - 1][coord.column - 1].occupied == 0)
			{
				board[coord.row - 1][coord.column - 1].symbol = 'X';
				board[coord.row - 1][coord.column - 1].occupied = 1;
				board[coord.row - 1][coord.column - 1].location.row = coord.row - 1;
				board[coord.row - 1][coord.column - 1].location.column = coord.column - 1;
			}

			print_board(board, n);

			printf("Computers turn.\n");
			int row = 0, column = 0;

			do
			{
				coord.row = rand() % n;
				coord.column = rand() % n;

			} while (board[coord.row][coord.column].occupied != 0);

			board[coord.row][coord.column].symbol = 'O';
			board[coord.row][coord.column].occupied = 1;
			board[coord.row][coord.column].location.row = coord.row;
			board[coord.row][coord.column].location.column = coord.column;


		}
	}
	else //Computer goes first
	{

	}

	return 0;
}