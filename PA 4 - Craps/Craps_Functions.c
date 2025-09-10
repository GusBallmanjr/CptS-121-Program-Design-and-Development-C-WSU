/*
	Progrmmer: Gus Ballman
	Class: CptS 121; Lab Section 07
	Date: 2/26/2025
	Description: This program runs a program that represents the game "Craps." The player will bet, and roll two dice.
	The sum of the two dice determines if the game will continue or not. The player can quit in between eeach turn and
	will be asked to bet after each term if they opt to continue playing.
*/

#include "PA4.h"

/*
	Frunction Name: display_menu()
	Date Created: 2/12/2025
	Description: This function displays the main menu for the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
void display_menu(void)
{
	printf("Welcome to Craps!!\nDo you DARE to play\?\n\n 1) Game Rules\n 2) Play Game\n 3) Quit Game\n");
}

/*
	Frunction Name: get_choice()
	Date Created: 2/13/2025
	Description: This function scans for an integer that represents the players choice of where to go after they see the main menu.
	Inputs: There are no inputs.
	Output: The output is an integer that represents the choice of the user after seeing the main menu.
*/
int get_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

/*
	Frunction Name: roll_die()
	Date Created: 2/12/2025
	Description: This function rolls a die and produces a psuedo-random number (1 through 6) that represents the value of the die.
	Inputs: There are no inputs.
	Output: The output is an integer that represents tthe value of the rolled die.
*/
int roll_die(void)
{
	int value = 0;
		value = (rand() % 6) + 1; //Mod 6 allows for the numbers to be 0 through 5 and the plus one represenst 1 through 6 or a six sided die
	return value;
}

/*
	Frunction Name: display_rules()
	Date Created: 2/13/2025
	Description: This function displays the game rules menu.
	Inputs: There are no inputs.
	Output: There are no outputs.
*/
void display_rules(void)
{
	printf("\n\n1) Every turn you will be asked to bet.\n2) After you bet, two dice will be rolled and their values will be summed.\n3) If on the first turn, the sum of your two rolls is 7 or 11, you win!\n4) If on the first turn the sum of your rolls is 2,3, or 12, you lose!\n5) On all the other turns if the you roll sum of 7, you lose!\n6) To win the game, you must roll a sum of your point (which is the sum of the dice of your last turn).\n\n Please type 'B' to enter main menu.\n");
}

/*
	Frunction Name: back_to_menu()
	Date Created: 2/13/2025
	Description: This function scans for a character that allows for the player to go back from the rules menu to the main menu.
	Inputs: There are no inputs.
	Output: The output is a character that represents a escape to the main menu.
*/
char back_to_menu(void)
{
	char back = '\0';
	scanf(" %c", &back);
	return back;
}

/*
	Frunction Name: roll_die()
	Date Created: 2/13/2025
	Description: This function calculates the sum of the two dice rolls.
	Inputs: The inputs are the values of the two die rolls.
	Output: The output is an integer that represents the sum of the two dice roll values.
*/
int calculate_sum(int die_number1, int die_number2)
{
	return (die_number1 + die_number2);
}

/*
	Frunction Name: get_bet()
	Date Created: 2/14/2025
	Description: This function asks for a user inputted bet that is based on the users current balance.
	Inputs: The inputs are the values of the players current balance and teh players current value of bets.
	Output: The output is an integer that represents the value of the total amount of betting money the player has put foward throughout the entire game.
*/
int get_bet(int balance, int bet)
{
	int bet1 = 0, bet2 = 0;
	printf("\nHow much would you like to bet\?\nCurrent Balance: $%d\nCurrent Bet: $%d\n", balance, bet);
	scanf("%d", &bet2);
	while (bet1 != 1)
	{
		if (bet2 > balance - bet) //makes sure bet is not more than the money avaliable to bet.
		{
			printf("Insufficent funds, please try again.\n");
			scanf("%d", &bet2);
		}
		else
		{
			bet2 = bet + bet2;
			bet1 = 1;
		}
	}
	return bet2;
}

