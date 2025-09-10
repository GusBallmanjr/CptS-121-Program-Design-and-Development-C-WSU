/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 4/7/2025
	Description: This program is a text based version of the game "Battleship." It is a two player game in which one of the players is the computer. The user - player one - will set their ships (or have them randomly placed) and try and guess the location of player two's ships (which were randomly placed). If player one gets a hit, they guess again; if they miss, the computer attacks. If all five ships are sunk by either player, than that player wins and the game can restart if the user so chooses.
*/

#include "PA6.h"

/*
	Function Name: display_menu()
	Date Created: 3/25/2025
	Description: This function displays the main menu for the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
int display_menu(void)
{
	printf("\nWelcome to Battleship!!\n\n 1) Game Rules\n 2) Play Game\n 3) Exit\n");
	return 1;
}

/*
Function Name : get_choice()
Date Created : 3 / 17 / 2025
Description : This function scans for an integer value that is then used in the sequence for the main menu.
Inputs : There are no inputs.
Output : The output is the integer value that the user typed in.
*/
int get_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

/*
	Function Name: display_rules()
	Date Created: 3/25/2025
	Description: This function displays the rules of the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
void display_rules(void)
{
	printf("\n\nRULES OF Battleship:\n\n\t1. Battleship is a two player game.\n\t2. Player 1 is you and Player 2 is the computer.\n\t3. Battleship is a two player Navy game.\n\t4. The objective of the game is to sink all ships in your enemy's fleet.\n\t5. The player to sink their enemy's fleet first wins.\n\t6. Both players' fleets consist of 5 ships that are hidden from the enemy.\n\t7. Each ship may be differentiated by its size.\n\t8. The Carrier has 5 spaces, the Battleship has 4 spaces, the Cruiser has 3 spaces,\n\t\tthe Submarine has 3 spaces, and the Destroyer has 2 spaces.\n\t9. Each turn you will choose a space and you will have a result of a hit or a miss.\n\t10. If you get a hit, you may go again.\n\t11. If you miss, it is teh computers turn.\n\t12. You may place your boats manually or have them randomly placed.\n\t13. Ships may not be placed diagonal, only vertical or horizontal.\n");
}

/*
	Function Name: initialize_board()
	Date Created: 3/26/2025
	Description: This function initializes a board of a Cell struct to its standard model before any additives with column and row numbers and the wave symbol (~) in all the other cells.
	Inputs: The input is the 2d board array of the Cell struct type that the program would like to initialize.
	Output: There are no outputs
*/
void initialize_board(Cell board[][11])
{
	char j = '0';
	board[0][0].symbol = ' '; // Sets top left corner
	board[0][0].occupied = 2; // Prevents attacks to this cell

	for (int w = 1; w < 11; w++)
	{
		board[0][w].occupied = 2; // Prevents attacks to this cell
		board[0][w].symbol = j; // Sets numbering of columns
		j++;
	}

	j = '0';
	for (int w = 1; w < 11; w++)
	{
		board[w][0].occupied = 2; // Prevents attacks to this cell
		board[w][0].symbol = j; // Sets numbering of rows
		j++;
	}

	for (int index = 1; index < 11; index++)
	{
		for (int i = 1; i < 11; i++)
		{
			board[index][i].occupied = 0; // allows attacks to this cell
			board[index][i].symbol = '~'; // Sets wave symbol
		}
	}
}

/*
	Function Name: print_board()
	Date Created: 3/26/2025
	Description: This function prints a Cell struct boars array for the user to see.
	Inputs: The input is the 2d board array of the Cell struct type that the program would like to print to the console.
	Output: There are no outputs
*/
void print_board(Cell board[11][11])
{
	for (int index = 0; index < 11; index++)
	{
		for (int i = 0; i < 11; i++)
		{
			printf("%c", board[index][i].symbol); // Prints Symbol at location within board
		}
		printf("\n");
	}
}

/*
Function Name : player__placement()
Date Created : 4 / 6 / 2025
Description : This function allows the user to place their ships.
Inputs : The inputs are the user's board struct, a ship row index that represents each individual ship, a cells array that represents how many cells each sell takes up, a ship character array that represents what symbol each ship uses, a placement struct for the player that determines where the ships will be placed, an integer that represents which turn the player is on, and a character array of the names of each ship.
Output : There is no output(s).
*/
void player_placement(Cell myboard[11][11], int cells[], char ship_char[], Coordinate placement, int turn, char ship[][20])
{
	int valid_turn = 0;
	printf("Your Board:\n");
	print_board(myboard);

	for (int ship_row = 0; ship_row < 5; ship_row++) // Repeats 5 times representing the 5 different ships
	{
		if (turn > 1)
		{
			system("pause");
			system("cls");
			print_board(myboard);
		}

		for (int cells_index = 0; cells_index < cells[ship_row]; cells_index++) // Repeats for the length of each ship
		{
			printf("Where would you like to place your %s? Please type the location of the first cell. (Row then column)\n", ship[ship_row]);
			scanf("%d", &placement.row);
			scanf("%d", &placement.column);

			placement.row++;
			placement.column++;
			valid_turn = 0;

			while (valid_turn != 1)
			{
				if (myboard[placement.row][placement.column].occupied != 0) //Already Taken
				{
					printf("Invalid Input. Please Try Again.\n");
					scanf("%d", &placement.row);
					scanf("%d", &placement.column);
					placement.row++;
					placement.column++;
				}
				else if (myboard[placement.row - 1][placement.column].occupied != 1 && myboard[placement.row + 1][placement.column].occupied != 1 && myboard[placement.row][placement.column - 1].occupied != 1 && myboard[placement.row][placement.column + 1].occupied != 1 && cells_index != 0) //Not vertical or Horizontal to another ship cell
				{
					printf("Invalid Input. Please Try Again.\n");
					scanf("%d", &placement.row);
					scanf("%d", &placement.column);
					placement.row++;
					placement.column++;
				}
				else
				{
					if (turn > 1) // After first turn
					{
						if (myboard[placement.row - 1][placement.column - 1].occupied == 1 || myboard[placement.row + 1][placement.column - 1].occupied == 1 || myboard[placement.row - 1][placement.column + 1].occupied == 1 || myboard[placement.row + 1][placement.column + 1].occupied == 1 && cells_index != 0) //Not vertical or Horizontal
						{

							printf("Invalid Input. Please Try Again.\n");
							scanf("%d", &placement.row);
							scanf("%d", &placement.column);
							placement.row++;
							placement.column++;
						}
						else // Places ship into cell
						{
							myboard[placement.row][placement.column].occupied = 1;
							myboard[placement.row][placement.column].symbol = ship_char[ship_row];
							print_board(myboard);
							valid_turn = 1;
						}
					}
					else // Places ship into cell - first turn
					{
						myboard[placement.row][placement.column].occupied = 1;
						myboard[placement.row][placement.column].symbol = ship_char[ship_row];
						print_board(myboard);
						valid_turn = 1;
						turn++;
					}
				}
			}
		}
	}
}

/*
Function Name : random_player__placement()
Date Created : 4 / 6 / 2025
Description : This function randomly places the user (player one's) ships.
Inputs : The inputs are the user's board struct, a ship row index that represents each individual ship, a cells array that represents how many cells each sell takes up, a ship character array that represents what symbol each ship uses, and a placement struct for the player that determines where the ships will be placed..
Output : There is no output(s).
*/
void random_player_placement(Cell myboard[11][11], int ship_row, int cells[], char ship_char[], Coordinate placement)
{
	int i = 0, avaliable_spots = 0, vert_or_hor = 0;

	for (ship_row = 0; ship_row < 5; ship_row++)
	{
		placement.row = rand() % (11 - cells[ship_row]);
		placement.column = rand() % (11 - cells[ship_row]);
		placement.row++;
		placement.column++;

		i = 0;
		avaliable_spots = 0;
		vert_or_hor = rand() % 2; // Determines if the ship will be Horizontal or Vertical

		if (vert_or_hor == 0) // Vertical
		{
			while (i != cells[ship_row])
			{
				if (myboard[placement.row + i][placement.column].occupied == 0) // Available Spot
				{
					avaliable_spots++;
					i++;
				}
				else if (myboard[placement.row + i][placement.column].occupied != 0) // Already taken or not available
				{
					i = 0;
					avaliable_spots = 0;
					placement.row = rand() % (11 - cells[ship_row]);
					placement.column = rand() % (11 - cells[ship_row]);
					placement.row++;
					placement.column++;
				}
			}
			for (int j = 0; j != cells[ship_row]; j++) // Placing the ship cells into the available spots
			{
				myboard[placement.row + j][placement.column].occupied = 1;
				myboard[placement.row + j][placement.column].symbol = ship_char[ship_row];
			}
		}
		if (vert_or_hor == 1) // Horizontal
		{

			while (i != cells[ship_row])
			{
				if (myboard[placement.row][placement.column + i].occupied == 0) // Available Spot
				{
					avaliable_spots++;
					i++;
				}
				else if (myboard[placement.row][placement.column + i].occupied != 0) // Already taken or not available
				{
					i = 0;
					avaliable_spots = 0;
					placement.row = rand() % (11 - cells[ship_row]);
					placement.column = rand() % (11 - cells[ship_row]);
					placement.row++;
					placement.column++;
				}
			}
			for (int j = 0; j != cells[ship_row]; j++) // Placing the ship cells into the available spots
			{
				myboard[placement.row][placement.column + j].occupied = 1;
				myboard[placement.row][placement.column + j].symbol = ship_char[ship_row];
			}
		}
	}
}

/*
Function Name : computer_placement()
Date Created : 4 / 6 / 2025
Description : This function randomly places the computer (player two's) ships.
Inputs : The inputs are the computers board struct, a ship row index that represents each individual ship, a cells array that represents how many cells each sell takes up, a ship character array that represents what symbol each ship uses, and a placement struct for the computer that determines where the ships will be placed..
Output : There is no output(s).
*/
void computer_placement(Cell compboard[11][11], int ship_row, int cells[], char ship_char[], Coordinate placement_comp)
{
	int i = 0, valid_turn = 0, avaliable_spots = 0, vert_or_hor = 0;
	for (ship_row = 0; ship_row < 5; ship_row++)
	{
		placement_comp.row = rand() % (11 - cells[ship_row]);
		placement_comp.column = rand() % (11 - cells[ship_row]);
		placement_comp.row++;
		placement_comp.column++;

		i = 0;
		avaliable_spots = 0;
		vert_or_hor = rand() % 2; // Determines if the ship whill be Horizontal or Vertical

		if (vert_or_hor == 0) // Vertical
		{
			while (i != cells[ship_row])
			{
				if (compboard[placement_comp.row + i][placement_comp.column].occupied == 0) // Available Spot
				{
					avaliable_spots++;
					i++;
				}
				else if (compboard[placement_comp.row + i][placement_comp.column].occupied != 0) // Already taken or not available
				{
					i = 0;
					avaliable_spots = 0;
					placement_comp.row = rand() % (11 - cells[ship_row]);
					placement_comp.column = rand() % (11 - cells[ship_row]);
					placement_comp.row++;
					placement_comp.column++;
				}
			}
			for (int j = 0; j != cells[ship_row]; j++) // Placing the ship cells into the available spots
			{
				compboard[placement_comp.row + j][placement_comp.column].occupied = 1;
				compboard[placement_comp.row + j][placement_comp.column].symbol = ship_char[ship_row];
			}
		}
		if (vert_or_hor == 1) // Horizontal
		{

			while (i != cells[ship_row])
			{
				if (compboard[placement_comp.row][placement_comp.column + i].occupied == 0) // Available Spot
				{
					avaliable_spots++;
					i++;
				}
				else if (compboard[placement_comp.row][placement_comp.column + i].occupied != 0) // Already taken or not available
				{
					i = 0;
					avaliable_spots = 0;
					placement_comp.row = rand() % (11 - cells[ship_row]);
					placement_comp.column = rand() % (11 - cells[ship_row]);
					placement_comp.row++;
					placement_comp.column++;
				}
			}
			for (int j = 0; j != cells[ship_row]; j++) // Placing the ship cells into the available spots
			{
				compboard[placement_comp.row][placement_comp.column + j].occupied = 1;
				compboard[placement_comp.row][placement_comp.column + j].symbol = ship_char[ship_row];
			}
		}
	}
}

/*
Function Name : which_ship_was_hit()
Date Created : 4 / 6 / 2025
Description : This function determines which ship (i.e cruiser or battleship or etc.) in order to determine how many times that ship was sunk.
Inputs : The inputs are an array that contains the number of hits each ship has collected, the user's board array of cell struct type, and a Coordinate struct that represents the coordinate position on the board that was attacked.
Output : There is no output(s).
*/
void which_ship_was_hit(int number_of_hits[5], Cell board[11][11], Coordinate coord)
{
	if (board[coord.row][coord.column].symbol == 'c') // Carrier
	{
		number_of_hits[0]++;
	}
	else if (board[coord.row][coord.column].symbol == 'b') // Battleship
	{
		number_of_hits[1]++;
	}
	else if (board[coord.row][coord.column].symbol == 's') // Submarine
	{
		number_of_hits[2]++;
	}
	else if (board[coord.row][coord.column].symbol == 'r') // Cruiser
	{
		number_of_hits[3]++;
	}
	else if (board[coord.row][coord.column].symbol == 'd') // Destroyer
	{
		number_of_hits[4]++;
	}
}

/*
Function Name : did_sink()
Date Created : 4 / 6 / 2025
Description : This function determines if a ship (i.e cruiser or battleship or etc.) was sunk or not.
Inputs : The inputs are an array that contains the number of hits each ship has collected, and an integer that represents whether it is determining a ship sunk that was attacked by player 1 or 2..
Output : The output is an integer that represents whether all 5 ships where sunk for player one, player two, or not.
*/
int did_sink(int number_of_hits[5], int player)
{
	int number_of_ships_sunk = 0;

	if (player == 1) // User - Player One
	{
		if (number_of_hits[0] == 5) // Carrier
		{
			printf("The Computer's Carrier was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[1] == 4) // Battleship
		{
			printf("The Computer's Battleship was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[2] == 3) // Submarine
		{
			printf("The Computer's Submarine was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[3] == 3) // Cruiser
		{
			printf("The Computer's Cruiser was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[4] == 2) // Destroyer
		{
			printf("The Computer's Destroyer was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_ships_sunk == 5) // Player One sunk all of the ships
		{
			printf("You Sunk all of the Computers Ships! You Win!\n");
			return 1;
		}
		else
		{
			return 0; // All five ships were not sunk
		}
	}
	else // Computer - Player Two
	{
		if (number_of_hits[0] == 5) // Carrier
		{
			printf("Your Carrier was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[1] == 4) // Battleship
		{
			printf("Your Battleship was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[2] == 3) // Submarine
		{
			printf("Your Submarine was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[3] == 3) // Cruiser
		{
			printf("Your Cruiser was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_hits[4] == 2) // Destroyer
		{
			printf("Your Destroyer was Sunk/Sunken!\n");
			number_of_ships_sunk++;
		}
		if (number_of_ships_sunk == 5) // Player two sunk all of the ships
		{
			printf("The Computer Sunk all of you Ships You Lose!\n");
			return 2;
		}
		else
		{
			return 0;  // All five ships were not sunk
		}
	}

}