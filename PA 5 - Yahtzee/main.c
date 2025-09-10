/*
	Programmer: Gus Ballman
	Class: Cpts 121; Lab 07
	Date: 3/20/2025
	Description: This program is a two player digital version of the dice game Yahtzee.
*/

#include "PA5.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	int choice = -1, game_mode = 0, back_to_menu = 0, dice[5] = { 0 }, kept_dice[5] = { 0 }, size = 0, index = 0, roll_count = 0, number_of_dice = 0, which_dice = -1, win_lose = -1, score1[13] = { 0 }, score2[13] = { 0 }, player = 2, scoring_option = 0, points1 = 0, points2 = 0;
	char back = '\0', yes_or_no = '\0';

	display_menu();
	while (game_mode == 0)
	{
		choice = get_choice();

		if (choice == 1) //Rules Menu
		{
			game_mode = 1;
			display_rules();
			back_to_menu = 0;
			while (back_to_menu != 1) //To get back to main menu
			{
				scanf(" %c", &back);
				if (back == 'B')
				{
					display_menu();
					game_mode = 0;
					back_to_menu = 1;
				}
				else //input validation
				{
					printf("Invalid Input. Try Again.\n");
				}
			}
		}
		else if (choice == 2) //Play Game
		{
			game_mode = 2;
		}
		else if (choice == 3) //Exit Game
		{
			game_mode = 3;
			return 0;
		}
		else if (choice != 1 || choice != 2 || choice != 3 || choice != -1) //input validation
		{
			printf("Invalid Input. Try Again.\n");
			choice = get_choice();
			getchar();
		}
	}
	
	
	while (game_mode == 2) //Play Game
	{
		if (player == 1) //determines which player's turn it is
		{
			player = 2;
		}
		else if (player == 2)
		{
			player = 1;
		}

		printf("    It is Player %d's turn.\n\n", player);

		size = 5;
		for (index = 0; index < size; index++) //Initial roll
		{
			dice[index] = random_num();
			printf("\tDice %d: %d\n", index + 1, dice[index]);
		}

		roll_count = 1;

		while (roll_count < 3 && roll_count >= 1) //roll counter to ensure three rolls per turn.
		{
			printf("\nHow many dice do you want to reroll\?\n");
			scanf("%d", &number_of_dice);

			while (number_of_dice != 1 && number_of_dice != 2 && number_of_dice != 3 && number_of_dice != 4 && number_of_dice != 5 && number_of_dice != 0) //input validation
			{
				printf("Invalid Input. Try Again.\n");
				scanf("%d", &number_of_dice);
			}

			if (number_of_dice != 0)
			{

				printf("Which dice would you like to reroll\? Please type enter after every dice\?\n"); //allows rerolls

				for (int i = 0; i < number_of_dice; i++)
				{
					scanf("%d", &which_dice);
					while (which_dice < 0 || which_dice > 5) //input validation
					{
						printf("Invalid Input. Try Again.\n");
						scanf("%d", &which_dice);
					}
					dice[which_dice - 1] = random_num(); //roll
				}

				for (int j = 1; j < 6; j++)
				{
					printf("\tDice %d: %d\n", j, dice[j - 1]);
				}
			}
			else
			{
				roll_count = 3;
			}
			roll_count++;
		} // while roll_count < 4 loop
		win_lose = score_available(score1, score2, player);

		if (win_lose == 0) //no more scoring options are available so end of game proceeds
		{
			printf("Player 1's score is %d\n", points1);
			printf("Player 2's score is %d\n", points2);

			if (points1 > points2) //Player 1 wins
			{
				printf("Player 1 Wins!\n");
				return 0;
			}
			else if (points2 > points1) //Player 2 wins
			{
				printf("Player 2 Wins!\n");
				return 0;
			}
			else if (points1 == points2) //Draw
			{
				printf("There was a Draw!\n");
				return 0;
			}
		}
		else
		{
			printf("Would you like to use this set of dice for a scoring option? (Y/N)\n"); //chose to use scoring option or not
			scanf(" %c", &yes_or_no);

			while (yes_or_no != '\0' && yes_or_no != 'Y' && yes_or_no != 'N') //input validation
			{
				printf("Invalid Input. Try Again.\n");
				scanf(" %c", &yes_or_no);
			}
			if (yes_or_no == 'Y')
			{
				printf("Please enter which scoring option you will choose:\t(a.k.a. the number associated with the scoring option)\n"); //chose scoring option
				scanf("%d", &scoring_option);
				
				while (scoring_option != 0 && scoring_option != 1 && scoring_option != 2 && scoring_option != 3 && scoring_option != 4 && scoring_option != 5 && scoring_option != 6 && scoring_option != 7 && scoring_option != 8 && scoring_option != 9 && scoring_option != 10 && scoring_option != 11 && scoring_option != 12 && scoring_option != 13) //input validation
				{
					printf("Invalid Input. Try Again.\n");
					scanf("%d", &scoring_option);
				}

				if (player == 1) //player points and score validation
				{
					points1 = points1 + what_score(dice, score1, score2, 1, scoring_option);
					score1[scoring_option - 1] = 1;
				}
				if (player == 2) //player points and score validation
				{
					points2 = points2 + what_score(dice, score1, score2, 2, scoring_option);
					score2[scoring_option - 1] = 1;
				}
			}

			printf("\n\tPlayer 1's Points: %d\tPlayer 2's Points: %d\n", points1, points2);
			yes_or_no = '\0';

			printf("Would you like to continue\? (Y/N)\n");
			scanf(" %c", &yes_or_no);

			if (yes_or_no == 'N') //End game - do not wish to continue
			{
				return 0;
			}
			while (yes_or_no != '\0' && yes_or_no != 'Y' && yes_or_no != 'N') //input validation
			{
				printf("Invalid Input. Try Again.\n");
				scanf(" %c", &yes_or_no);
			}
			yes_or_no = '\0';
		}
	}

	return 0;
}