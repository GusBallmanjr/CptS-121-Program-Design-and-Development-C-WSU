/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 4/7/2025
	Description: This program is a text based version of the game "Battleship." It is a two player game in which one of the players is the computer. The user - player one - will set their ships (or have them randomly placed) and try and guess the location of player two's ships (which were randomly placed). If player one gets a hit, they guess again; if they miss, the computer attacks. If all five ships are sunk by either player, than that player wins and the game can restart if the user so chooses.
*/

#include "PA6.h"

int main(void)
{
	int choice = -1, game_mode = 0, back_to_menu = 0, ship_row = 0, cells[5] = { 5, 4, 3, 3, 2 }, cells_index = 0, turn = 1, valid_turn = 0, comp_valid_shot = 0, valid_shot = 0, hit = 1, turn_comp = 1, available_spots = 0, vert_or_hor = 0, number_of_hits[5] = { 0 }, number_of_hits_comp[5] = { 0 }, number_of_ships_sunk = 0, number_of_ships_sunk_comp = 0;
	char back = '\0', ship_char[5] = { 'c', 'b', 's', 'r', 'd' }, random_placement = '\0';
	Cell board[11][11], myboard[11][11], compboard[11][11];
	Coordinate coord = { 0, 0 }, placement = { 0, 0 }, placement_comp = { 0,0 };
	Stats p1 = { 0, 0 , 0 }, p2 = { 0, 0, 0 };
	Game_info game = { 0, 0, 0 };
	char ship[5][20] = { "Carrier", "Battleship", "Submarine", "Cruiser", "Destroyer" };

	FILE* outfile = fopen("Battleship.log", "w");

	srand((unsigned int)time(NULL));

	while (game_mode != 3)
	{
		initialize_board(board);
		initialize_board(myboard);
		initialize_board(compboard);

		display_menu();
		fprintf(outfile, "Total Games Played: %d\nTotal Wins: %d\nTotal Losses: %d", game.total_games_played, game.wins, game.losses);
		while (game_mode == 0)
		{
			choice = get_choice();

			if (choice == 1) //Rules Menu
			{
				display_rules();
				back_to_menu = 0;
				system("pause");
				system("cls");
				display_menu();
			}
			else if (choice == 2) //Play Game
			{
				game_mode = 2;
				game.total_games_played++;
				fprintf(outfile, "\nGame #%d:\n", game.total_games_played);
				system("cls");
			}
			else if (choice == 3) //Exit Game
			{
				game_mode = 3;
				fclose(outfile);
				system("cls");
				return 0;
			}
			else if (choice != 1 || choice != 2 || choice != 3 || choice != -1) //input validation
			{
				printf("Invalid Input. Try Again.\n");
				choice = get_choice();
				getchar();
			}
		}

		while (game_mode == 2)
		{
			if (turn == 1)
			{
				printf("Would you like your ships to be randomly placed\? (Y/N)\n");
				scanf(" %c", &random_placement);

				while (random_placement != 'Y' && random_placement != 'N')
				{
					printf("Invalid Option. Try Again.\n");
					scanf(" %c", &random_placement);
				}

				if (random_placement == 'N') //Player wants to place their own ships.
				{
					player_placement(myboard, cells, ship_char, placement, turn, ship);
					turn++;
				}

				else if (random_placement == 'Y') //Player wants ships randomly placed
				{	
					random_player_placement(myboard, ship_row, cells, ship_char, placement);
					turn++;
				}
			}

			if (turn_comp == 1) //Computer Placement
			{
				computer_placement(compboard, ship_row, cells, ship_char, placement_comp);
				turn_comp++;
			}

			system("pause");
			system("cls");
			printf("Your Board:\n");
			print_board(myboard);

			//Attacking Phase:
			printf("\n\n Attacking board:\n");
			print_board(board);
			hit = 1;
			valid_shot = 0;

			while (hit == 1)
			{
				printf("Enter the coordinate to place your guess (row then column): "); // Player Attacks
				scanf("%1d%1d", &coord.row, &coord.column);

				coord.row++;
				coord.column++;
				valid_shot = 0;

				while (valid_shot != 1)
				{
					p1.total_shots++;
					if (coord.row < 11 && coord.column < 11)
					{
						if (compboard[coord.row][coord.column].occupied == 0) // Player misses
						{
							board[coord.row][coord.column].symbol = 'M';
							compboard[coord.row][coord.column].occupied = 2;
							fprintf(outfile, "Player One targeted Row: %d\tColumn: %d\tResult:  Miss\n", coord.row - 1, coord.column - 1);
							p1.num_misses++;
							hit = 0;
							valid_shot = 1;
							print_board(board);
						}
						else if (compboard[coord.row][coord.column].occupied == 1) // Player gets a hit
						{
							which_ship_was_hit(number_of_hits, compboard, coord);
							number_of_ships_sunk = did_sink(number_of_hits, 1);
							if (number_of_ships_sunk == 1)
							{
								game_mode = 0;
								hit = 0;
								valid_shot = 1;
								fprintf(outfile, "Player One wins game %d\n", game.total_games_played);
								game.wins++;
							}
							else
							{
								board[coord.row][coord.column].symbol = 'H';
								compboard[coord.row][coord.column].occupied = 2;
								fprintf(outfile, "Player One targeted Row: %d\tColumn: %d\tResult:  Hit\n", coord.row - 1, coord.column - 1);
								p1.num_hits++;
								valid_shot = 1;
								print_board(board);
							}
						}
						else if (compboard[coord.row][coord.column].occupied == 2) // Already tried or unavailable
						{
							fprintf(outfile, "Player One targeted Row: %d\tColumn: %d\tResult:  Invalid\n", coord.row - 1, coord.column - 1);
							printf("Invalid/Already Used. Try Again.\n");
							scanf("%1d%1d", &coord.row, &coord.column);
							coord.row++;
							coord.column++;
						}
					}
					else
					{
						fprintf(outfile, "Player One targeted Row: %d\tColumn: %d\tResult:  Invalid\n", coord.row - 1, coord.column - 1);
						printf("Invalid/Already Used. Try Again.\n");
						scanf("%1d%1d", &coord.row, &coord.column);
						coord.row++;
						coord.column++;
					}
				}
			}
			
			if (game_mode != 0)
			{
				system("pause");
				system("cls");

				printf("\nComputers turn.\n"); // Computer Attacks

				coord.row = rand() % 11; // Initial row choice
				coord.column = rand() % 11; // Initial column choice
				coord.row++;
				coord.column++;
				p2.total_shots++;
				comp_valid_shot = 0;

				while (comp_valid_shot != 1)
				{
					if (myboard[coord.row][coord.column].occupied != 1 && myboard[coord.row][coord.column].occupied != 0) // Already tried or unavailable
					{
						fprintf(outfile, "Player two targeted Row: %d\tColumn: %d\tResult:  Invalid\n", coord.row - 1, coord.column - 1);
						coord.row = rand() % 11; // row choice
						coord.column = rand() % 11; //  column choice
						coord.row++;
						coord.column++;
					}
					else if (myboard[coord.row][coord.column].occupied == 1) // Computer gets a hit
					{
						which_ship_was_hit(number_of_hits_comp, myboard, coord);
						number_of_ships_sunk_comp = did_sink(number_of_hits_comp, 2);
						if (number_of_ships_sunk_comp == 2)
						{
							game_mode = 0;
							comp_valid_shot = 1;
							fprintf(outfile, "Player Two wins game %d\n", game.total_games_played);
							game.losses++;
						}
						else
						{
							myboard[coord.row][coord.column].occupied = 2;
							myboard[coord.row][coord.column].symbol = 'H';
							comp_valid_shot = 1;
							fprintf(outfile, "Player two targeted Row: %d\tColumn: %d\tResult:  Hit\n", coord.row - 1, coord.column - 1);
							p2.num_hits++;
							printf("\n\n Your Board:\n");
							print_board(myboard);
						}
					}
					else if (myboard[coord.row][coord.column].occupied == 0) // Computer misses
					{
						myboard[coord.row][coord.column].occupied = 2;
						myboard[coord.row][coord.column].symbol = 'M';
						comp_valid_shot = 1;
						fprintf(outfile, "Player two targeted Row: %d\tColumn: %d\tResult:  Miss\n", coord.row - 1, coord.column - 1);
						p2.num_hits++;
						printf("\n\n Your Board:\n");
						print_board(myboard);
					}
				}
			}
		}
	}
	fclose(outfile);
	return 0;
}