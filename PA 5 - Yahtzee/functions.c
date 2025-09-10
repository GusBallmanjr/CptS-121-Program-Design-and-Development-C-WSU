/*
	Programmer: Gus Ballman
	Class: Cpts 121; Lab 07
	Date: 3/20/2025
	Description: This program is a two player digital version of the dice game Yahtzee.
*/

#include "PA5.h"

//Did not use this function (keep for future use):
//void frequency_table(int array[], int size, int freq[])
//{
//	int count = 0, set_num = 0;
//	for (set_num = 1; set_num != 100; set_num++)
//	{
//		count = 0;
//		for (int k = 0; k < size; k++)
//		{
//			if (array[k] == set_num)
//			{
//				count++;
//			}
//		}
//		freq[set_num] = count;
//	}
//}

/*
	Function Name: random_num()
	Date Created: 3/17/2025
	Description: This function produces a random integer that has a value between 1 and 6.
	Inputs: There are no inputs.
	Output: The output is a random integer with a value between 1 and 6.
*/
int random_num(void)
{
	return (rand() % 6) + 1;
}

/*
	Function Name: display_menu()
	Date Created: 3/17/2025
	Description: This function displays the main menu for the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
int display_menu(void)
{
	printf("\nWelcome to Yahtzee!!\n\n 1) Game Rules\n 2) Play Game\n 3) Exit\n");
	return 1;
}

/*
	Function Name: get_choice()
	Date Created: 3/17/2025
	Description: This function scans for an integer value that is then used in the sequence for the main menu.
	Inputs: There are no inputs.
	Output: The output is the integer value that the user typed in.
*/
int get_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

/*
	Function Name: display_rules()
	Date Created: 3/17/2025
	Description: This function displays the rules of the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
void display_rules(void)
{
	printf("\n\nRULES OF YAHTZEE:\n1) Every turn you will roll dice up to three times.\n2) After each roll, you will have the chance to select which dice you want to keep and then you will roll\nthe rest of the price.\n\n\nWAYS TO SCORE:\n\nUpper Section Combinations:\n\tOnes: Get as many ones as possible.\n\tTwos: Get as many twos as possible.\n\tThrees: Get as many threes as possible.\n\t Fours: Get as many fours as possible.\n\t Fives: Get as many fives as possible.\n\t Sixes: Get as many sixes as possible.\n\nLOWER SECTION COMBINATIONS:\n\tThree of a kind: Get three dice with the same number. Points are the sum all dice.\n\tFour of a kind: Get four dice with the same number. Points are the sum all dice.\n\tFull house: Get three of a kind and a pair. Scores 25 points.\n\tSmall straight: Get four sequential dice. Scores 30 points.\n\tLarge straight: Get five sequential dice. Scores 40 points.\n\t\YAHTZEE: Five of a kind. Scores 50 points.\n\tChance: Sum of all face values on the 5 dice. May be used for any sequence of dice.\n\n Type 'B' to exit back to main menu\n");
}

/*
	Function Name: score_available()
	Date Created: 3/19/2025
	Description: This function calculates if a player has already used a scoring option.
	Inputs: The inputs are an integer representing 1 or 2 that signifies which players turn it is, an integer array that represents which scoring options player one has already used, and an integer array that represents which scoring options player two has already used.
	Output: The output is an integer (1 or 0) that represents if there is an available scoring option or not.
*/
int score_available(int score1[], int score2[], int player_number)
{
	int allow = 0;
	if (player_number == 1)
	{
		for (int i = 0; i < 13; i++)
		{
			if (score1[i] == 0)
			{
				allow = 1;
			}
		}
		if (allow == 1)
		{
			printf("\n\nPlayer %d's scoring options are: \n\n", player_number);
			if (score1[0] == 0)
			{
				printf("\t1. Sums of 1's\n");
			}
			if (score1[1] == 0)
			{
				printf("\t2. Sums of 2's\n");
			}
			if (score1[2] == 0) //Sums of 3's
			{
				printf("\t3. Sums of 3's\n");
			}
			if (score1[3] == 0) //Sums of 4's
			{
				printf("\t4. Sums of 4's\n");
			}
			if (score1[4] == 0) //Sums of 5's
			{
				printf("\t5. Sums of 5's\n");
			}
			if (score1[5] == 0) //Sums of 6's
			{
				printf("\t6. Sums of 6's\n");
			}
			if (score1[6] == 0) //Three-of-a-kind
			{
				printf("\t7. Three-Of-A-Kind\n");
			}
			if (score1[7] == 0) //Four-of-a-kind
			{
				printf("\t8. Four-Of-A-Kind\n");
			}
			if (score1[8] == 0) //Full House
			{
				printf("\t9. Full House\n");
			}
			if (score1[9] == 0) //Small Straight
			{
				printf("\t10. Small Straight\n");
			}
			if (score1[10] == 0) //Large Straight
			{
				printf("\t11. Large Straight\n");
			}
			if (score1[11] == 0) //Yahtzee
			{
				printf("\t12. Yahtzee (Five-Of-A-Kind)\n");
			}
			if (score1[12] == 0) //Chance
			{
				printf("\t13. Chance\n");
			}
			return 1;
		}
		else
		{
			printf("No More Options\n");
			return 0;
		}
	}
	else if (player_number == 2)
	{
		for (int i = 0; i < 13; i++)
		{
			if (score2[i] == 0)
			{
				allow = 1;
			}
		}
		if (allow == 1)
		{
			printf("\n\nPlayer %d's scoring options are: \n\n", player_number);
			if (score2[0] == 0)
			{
				printf("\t1. Sums of 1's\n");
			}
			if (score2[1] == 0)
			{
				printf("\t2. Sums of 2's\n");
			}
			if (score2[2] == 0) //Sums of 3's
			{
				printf("\t3. Sums of 3's\n");
			}
			if (score2[3] == 0) //Sums of 4's
			{
				printf("\t4. Sums of 4's\n");
			}
			if (score2[4] == 0) //Sums of 5's
			{
				printf("\t5. Sums of 5's\n");
			}
			if (score2[5] == 0) //Sums of 6's
			{
				printf("\t6. Sums of 6's\n");
			}
			if (score2[6] == 0) //Three-of-a-kind
			{
				printf("\t7. Three-Of-A-Kind\n");
			}
			if (score2[7] == 0) //Four-of-a-kind
			{
				printf("\t8. Four-Of-A-Kind\n");
			}
			if (score2[8] == 0) //Full House
			{
				printf("\t9. Full House\n");
			}
			if (score2[9] == 0) //Small Straight
			{
				printf("\t10. Small Straight\n");
			}
			if (score2[10] == 0) //Large Straight
			{
				printf("\t11. Large Straight\n");
			}
			if (score2[11] == 0) //Yahtzee
			{
				printf("\t12. Yahtzee (Five-Of-A-Kind)\n");
			}
			if (score2[12] == 0) //Chance
			{
				printf("\t13. Chance\n");
			}
			return 1;
		}
		else
		{
			printf("No More Options\n");
			return 0;
		}
	}
}

/*
	Function Name: what_score()
	Date Created: 3/19/2025
	Description: This function validates a scoring option and if the scoring option is available gives points.
	Inputs: The inputs are an array (dice) that represents the values of the value of the five dice, two integer arrays (score1 and score2) that represent the scoring option that player one or two have available or have used, and there is an integer value that represents which scoring option was chosen.
	Output: The output is an integer value for the amount of points a player receives.
*/
int what_score(int dice[], int score1[], int score2[], int player_number, int scoring_option)
{
	int frequency[6] = { 0, 0, 0, 0, 0, 0 }, exists = 0, sum = 0;

	if (player_number == 1)
	{
		for (int i = 1; i < 7; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (dice[j] == i)
				{
					frequency[i - 1]++;
				}
			}
		}
		switch (scoring_option)
		{
		case 1: //Sums of 1's
			if (score1[0] == 0)
			{
				return frequency[0];
			}
			else
			{
				return 0;
			}
			break;
		case 2: //Sums of 2's
			if (score1[1] == 0)
			{
				return (2 * frequency[1]);
			}
			else
			{
				return 0;
			}
			break;
		case 3: //Sums of 3's
			if (score1[2] == 0)
			{
				return (3 * frequency[2]);
			}
			else
			{
				return 0;
			}
			break;
		case 4: //Sums of 4's
			if (score1[3] == 0)
			{
				return (4 * frequency[3]);
			}
			else
			{
				return 0;
			}
			break;
		case 5: //Sums of 5's
			if (score1[4] == 0)
			{
				return (5 * frequency[4]);
			}
			else
			{
				return 0;
			}
			break;
		case 6: //Sums of 6's
			if (score1[5] == 0)
			{
				return (6 * frequency[5]);
			}
			else
			{
				return 0;
			}
			break;
		case 7: //Three-of-a-kind
			if (score1[6] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 3)
					{
						exists = 1;
						return (3 * (i + 1));
					}
				}
				if (exists == 0)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 8: //Four-of-a-kind
			if (score1[7] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 4)
					{
						exists = 1;
						return (4 * (i + 1));
					}
				}
				if (exists == 0)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 9: //Full House
			if (score1[8] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 3)
					{
						exists++;
						for (int j = 0; j < 6; j++)
						{
							if (frequency[j] == 2)
							{
								exists++;
							}
						}
					}
				}
				if (exists == 2)
				{
					return 25;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 10: //Small Straight
			if (score1[9] == 0)
			{
				if (frequency[1] == 1 && frequency[2] == 1 && frequency[3] == 1 && frequency[4] == 1)
				{
					return 30;
				}
				else if (frequency[2] == 1 && frequency[3] == 1 && frequency[4] == 1 && frequency[5] == 1)
				{
					return 30;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 11: //Large Straight
			if (score1[10] == 0)
			{
				if (frequency[1] == 1 && frequency[2] == 1 && frequency[3] == 1 && frequency[4] == 1 && frequency[5] == 1)
				{
					return 40;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 12: //Yahtzee
			if (score1[11] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 5)
					{
						exists = 1;
						return (5 * (i + 1));
					}
				}
				if (exists == 0)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 13: //Chance
			if (score1[12] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					sum += dice[i];
				}
				return sum;
			}
			else
			{
				return 0;
			}
			break;
		}
	}
	else if (player_number == 2) //Player 2
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 1; j < 6; j++)
			{
				if (dice[i] == j)
				{
					frequency[j]++;
				}
			}
		}
		switch (scoring_option)
		{
		case 1: //Sums of 1's
			if (score2[0] == 0)
			{
				return frequency[0];
			}
			else
			{
				return 0;
			}
			break;
		case 2: //Sums of 2's
			if (score2[1] == 0)
			{
				return (2 * frequency[1]);
			}
			else
			{
				return 0;
			}
			break;
		case 3: //Sums of 3's
			if (score2[2] == 0)
			{
				return (3 * frequency[2]);
			}
			else
			{
				return 0;
			}
			break;
		case 4: //Sums of 4's
			if (score2[3] == 0)
			{
				return (4 * frequency[3]);
			}
			else
			{
				return 0;
			}
			break;
		case 5: //Sums of 5's
			if (score2[4] == 0)
			{
				return (5 * frequency[4]);
			}
			else
			{
				return 0;
			}
			break;
		case 6: //Sums of 6's
			if (score2[5] == 0)
			{
				return (6 * frequency[5]);
			}
			else
			{
				return 0;
			}
			break;
		case 7: //Three-of-a-kind
			if (score2[6] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 3)
					{
						exists = 1;
						return (3 * (i + 1));
					}
				}
				if (exists == 0)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 8: //Four-of-a-kind
			if (score2[7] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 4)
					{
						exists = 1;
						return (4 * (i + 1));
					}
				}
				if (exists == 0)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 9: //Full House
			if (score2[8] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 3)
					{
						exists++;
						for (int j = 0; j < 6; j++)
						{
							if (frequency[j] == 2)
							{
								exists++;
							}
						}
					}
				}
				if (exists = 2)
				{
					return 25;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 10: //Small Straight
			if (score2[9] == 0)
			{
				if (frequency[1] == 1 && frequency[2] == 1 && frequency[3] == 1 && frequency[4] == 1)
				{
					return 30;
				}
				else if (frequency[2] == 1 && frequency[3] == 1 && frequency[4] == 1 && frequency[5] == 1)
				{
					return 30;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 11: //Large Straight
			if (score2[10] == 0)
			{
				if (frequency[1] == 1 && frequency[2] == 1 && frequency[3] == 1 && frequency[4] == 1 && frequency[5] == 1)
				{
					return 40;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 12: //Yahtzee
			if (score2[11] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					if (frequency[i] == 5)
					{
						exists = 1;
						return (5 * (i + 1));
					}
				}
				if (exists == 0)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
			break;
		case 13: //Chance
			if (score2[12] == 0)
			{
				for (int i = 0; i < 6; i++)
				{
					sum += dice[i];
				}
				return sum;
			}
			else
			{
				return 0;
			}
			break;
		}
	}
}