/*
	Progrmmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 2/26/2025
	Description: This program runs a program that represents the game "Craps." The player will bet, and roll two dice.
	The sum of the two dice determines if the game will continue or not. The player can quit in between eeach turn and
	will be asked to bet after each term if they opt to continue playing.
*/

#include "PA4.h"

int main(void)
{
	int choice = 0, point = 0, die1 = 0, die2 = 0, retrn = 0, game = 0, balance = 500, sum = 0, bet = 0, roll_number = 0;
	char back = '\0', quit = '\0';

	srand((unsigned int)time(NULL)); //For random die values for each roll

	display_menu(); //Display Main Menu

	while (game != 1) //The game variable represents whether the game is in playing mode (game = 1) or not, and will allow this loop to run while the main menu is displayed.
	{
		choice = get_choice(); //Collects choice from player that corresponds with the main menu.
		retrn = 0; //retrn is true of false and determines if the player opts to go back to main menu or not. Allows this loop to continue while the rules menu is displayed.

		if (choice == 1) //Rules Menu
		{
			printf("Display the Rules...\n");
			display_rules(); //Rules menu
			while (retrn != 1)
			{
				back = back_to_menu();
				if (back == 'B') //If player types 'B', they will return to main menu.
				{
					printf("\n\n\n\n"); //Spacing
					display_menu(); //Main Menu
					retrn = 1;
				}
				else
				{
					printf("Invalid input, please try again.\n");
				}
			}
		}
		else if (choice == 2) //Play Game
		{
			printf("Playing the Game...\n\n");
			game = 1; //Playing Mode
		}
		else if (choice == 3) //quit Game
		{
			printf("Exiting...\n");
			return 0; //End program
		}
		else //Input is <1 or >3
		{
			printf("Invalid input, please try again.\n\n");
			getchar();
		}
	}


	while (game == 1) //While in playing mode
	{
		bet = get_bet(balance, bet);
		die1 = roll_die();
		die2 = roll_die();

		roll_number++; //Determines whether or not this roll is the first roll in the game or not.
		sum = calculate_sum(die1, die2);

		printf("\n\nDie #1: %d\tDie #2: %d\tSum: %d\n", die1, die2, sum);

		if (roll_number == 1) //First Turn
		{
			if (sum == 11 || sum == 7) //Player Win
			{
				printf("\n\nYou WIN!!");
				balance = balance + bet;
				printf("\tYour balance is $%d\n", balance);
				game = 0; //Changes game mode out of playing mode
				return 0; //End program
			}
			else if (sum == 2 || sum == 3 || sum == 12) //Player loss
			{
				printf("\n\nWOMP!\nWOMP!\nYou LOSE!! The House wins!\n");
				balance = balance - bet;
				printf("\tYour balance is $%d\n", balance);
				game = 0; //Changes game mode out of playing mode
				return 0; //End program
			}
		}
		else //Not first turn
		{
			if (sum == 7) //Player loss
			{
				printf("\n\nWOMP!\nWOMP!\nYou LOSE!! The House wins!\n");
				balance = balance - bet; //Loses bet
				printf("\tYour balance is $%d\n", balance);
				game = 0; //Changes game mode out of playing mode
				return 0; //End program
			}
			else if (sum == point) //Player win
			{
				printf("\n\nYou WIN!!");
				balance = balance + bet; //Wins bet
				printf("\tYour balance is $%d\n", balance);
				game = 0; //Changes game mode out of playing mode
				return 0; //End program
		}
			else
			{
				point = sum;
				printf("Point: %d\n", point);
				printf("\tYour balance is $%d\tYour bet is $%d\n", balance, bet);
				printf("\n\n To exit game please type 'Q'. To continue please type 'C'\n");
				scanf(" %c", &quit);
				retrn = 0; //prereq to allow loop to run. In this case, retrn represents whether or not the player enters a valid input
				while (retrn == 0)
				{
					if (quit == 'Q')
					{
						game = 0; //Changes game mode out of playing mode
						retrn = 1; //Valid input
						balance = balance - bet; //Loses bet
						printf("\tYou lost your bets!\tYour balance is $%d\n", balance);
						printf("Exiting...\n");
						return 0; //End program
					}
					else if (quit == 'C')
					{
						retrn = 1; //Valid input
						printf("You are brave, but that doesn\'t mean you can beat the HOUSE!!\n");
					}
					else
					{
						printf("Invalid input, please try again.\n");
						scanf(" %c", &quit);
					}
				}
			}
		}
	}

	return 0; //End program
}