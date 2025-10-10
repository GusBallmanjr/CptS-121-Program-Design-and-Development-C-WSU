/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab section: 07
	Description: This program is a text based version of 5 card poker. The Player will be delt five cards from a shuffled deck and will have two chances to replace up to three cards. They will have a chance to bet and will be playing against the dealer.
*/

#include "PA7.h"

/* shuffle cards in deck */

/*
	Function Name: display_menu()
	Date Created: 4/13/2025
	Description: This function displays the main menu for the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
int display_menu(void)
{
	printf("Welcome to POKER!!\n\n 1) Game Rules\n 2) Play Game\n 3) Exit\n");
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
	Date Created: 4/13/2025
	Description: This function displays the rules of the game.
	Inputs: There are no inputs.
	Output: There are no outputs
*/
void display_rules(void)
{
	printf("RULES OF POKER:\n\n\t1. The player (You) and the dealer will be delt five cards of a shuffled deck (You cannot see the dealers cards)\n\t2. During each turn you will have two chances to replace up to three cards from your hand.\n\t\tYou will be delt however many new cards that you chose to have replaced.\n\t3. The dealer will also have this option behind the scenes.\n\t4. The goal is to get a better hand than the dealer.\n\n\t\tHands (in order top to bottom in value):\n\t\t(a) A Pair (Two-of-a-kind)\n\t\t(b) Two Pairs (Two sets of Two-of-a-kinds)\n\t\t(c) Three-of-a-kind\n\t\t(d) Straight (A Sequence of numbers [i.e. 1, 2, 3, 4, 5])\n\t\t(e) Flush (All Cards in hand are of same suit)\n\t\t(f) Full House (A Pair plus Three-of-a-kind)\n\t\t(g) Four-of-a-kind\n\t\t(h) Straight Flush (A Sequence of numbers that are all of the same suit)\n\t\t(i) Royal Flush (an Ace, 10, Jack, Queen, and King all in the same suit)\n\n\t5. After each turn you will have a chance to bet based off of your hand.\n");
}

// Starter Code Function:
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

// Starter code function that I adjusted to ass number_of_cards to draw (because each turn is different), the starting point (to determine which cards are replaced), and the number of cards already drawn (so no repeats come about after shuffle).
/* deal cards in deck */
void deal(const int wDeck[][13], Hand *hand, int number_of_cards_to_draw, int *number_of_cards_already_drawn, int card_starting_point)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int num_of_cards = *number_of_cards_already_drawn, i = card_starting_point;

	/* deal each of the 5 cards */
	for (card = (num_of_cards + 1); card <= (number_of_cards_to_draw + num_of_cards); card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					hand->cards[i].face_index = column;
					hand->cards[i].suit_index = row;
					i++;
				}
			}
		}
	}
	*number_of_cards_already_drawn += i;
}

/*
	Function Name: which_hand()
	Date Created: 4/14/2025
	Description: This function validates a scoring option and if the scoring option is available gives points.
	Inputs: The input is the Hand struct that represents the player's 5 card hand.
	Output: The output is an integer value for the which type of scoring combinations a player has within their hand.
*/
int which_hand(Hand hand)
{
	int frequency_face[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, exists = 0, frequency_suit[4] = { 0, 0, 0, 0 }, output = 0;

	for (int f = 0; f < 5; f++) // Frequency table for face
	{
		for (int i = 0; i < 13; i++)
		{
			if (hand.cards[f].face_index == i)
			{
				frequency_face[i]++;
			}
		}
	}

	for (int f = 0; f < 5; f++) // Frequency table for suit
	{
		for (int i = 0; i < 4; i++)
		{
			if (hand.cards[f].suit_index == i)
			{
				frequency_suit[i]++;
			}
		}
	}

	//Straight or Straight Flush:
	if (output == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if (frequency_face[i] == 1 && frequency_face[i + 1] == 1 && frequency_face[i + 2] == 1 && frequency_face[i + 3] == 1 && frequency_face[i + 4] == 1)
			{
				output = 4;
				for (int i = 0; i < 5; i++)
				{
					if (frequency_suit[i] == 5)
					{
						output = 8;
					}
				}
			}
			else // Royal Straight with an Ace
			{
				if (hand.cards[i].face_index == 0) // Contains Ace
				{
					exists++;
				}
				if (hand.cards[i].face_index == 9) // Contains Ten
				{
					exists++;
				}
				if (hand.cards[i].face_index == 10) // Contains Jack
				{
					exists++;
				}
				if (hand.cards[i].face_index == 11) // Contains Queen
				{
					exists++;
				}
				if (hand.cards[i].face_index == 12) // Contains King
				{
					exists++;
				}
				if (exists == 5)
				{
					output = 4;
				}
			}
		}
		exists = 0;
	}

	// Flush or Royal Flush:
	if (output == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (frequency_suit[i] == 5)
			{
				output = 5;

				for (int j = 0; j < 5; j++)
				{
					// Does hand contain Royal Flush?
					if (hand.cards[j].face_index == 0) // Contains Ace
					{
						exists++;
					}
					if (hand.cards[j].face_index == 9) // Contains Ten
					{
						exists++;
					}
					if (hand.cards[j].face_index == 10) // Contains Jack
					{
						exists++;
					}
					if (hand.cards[j].face_index == 11) // Contains Queen
					{
						exists++;
					}
					if (hand.cards[j].face_index == 12) // Contains King
					{
						exists++;
					}
				}
				if (exists == 5) // Royal Flush
				{
					output = 9;
				}
			}
		}
	}
	exists = 0;

	// Full House:
	if (output == 0)
	{
		for (int i = 0; i < 13; i++)
		{
			if (frequency_face[i] == 3)
			{
				exists++;
				for (int j = 0; j < 13; j++)
				{
					if (frequency_face[j] == 2)
					{
						exists++;
					}
				}
			}
		}
		if (exists == 2)
		{
			output = 6;
		}
		else
		{
			exists = 0;
		}
	}

	// Four-of-a-kind:
	if (output == 0)
	{
		for (int i = 0; i < 13; i++)
		{
			if (frequency_face[i] == 4)
			{
				output = 7;
			}
		}
	}

	// Three-of-a-kind:
	if (output == 0)
	{
		for (int i = 0; i < 13; i++)
		{
			if (frequency_face[i] == 3)
			{
				output = 3;
			}
		}
	}

	// pair or two pair:
	if (output == 0)
	{
		for (int i = 0; i < 13; i++)
		{
			if (frequency_face[i] == 2)
			{
				exists = 1;

				for (int j = 0; j < 13; j++)
				{
					if (frequency_face[j] == 2 && j != i)
					{
						exists = 2;
					}
				}

			}
		}
		if (exists == 1)
		{
			output = 1;
		}
		else if (exists == 2)
		{
			output = 2;
		}
	}
	return output;
}

/*
	Function Name: combination()
	Date Created: 4/15/2025
	Description: This function prints a message for the user to see what combo a hand has.
	Inputs: The inputs are an integer that represent which combo a hand has and an integer that represents whether that hand is the players.
	Output: There are no outputs.
*/
void combination(int combo, int player)
{
	if (player == 1) // User is Player 1
	{
		if (combo == 0) // No combo
		{
			printf("\nYou have no viable combo!\n");
		}
		else if (combo == 1) // Pair
		{
			printf("\nYou have a Pair!\n");
		}
		else if (combo == 2) // Two Pairs
		{
			printf("\nYou have Two Pairs!\n");
		}
		else if (combo == 3) // Three-of-a-kind
		{
			printf("\nYou have Three-of-a-kind!\n");
		}
		else if (combo == 4) // Straight
		{
			printf("\nYou have a Straight!\n");
		}
		else if (combo == 5) // Flush
		{
			printf("\nYou have a Flush!\n");
		}
		else if (combo == 6) // Full House
		{
			printf("\nYou have a Full House!\n");
		}
		else if (combo == 7) // Four-of-a-kind
		{
			printf("\nYou have a Four-of-a-kind!\n");
		}
		else if (combo == 8) // Straight Flush
		{
			printf("\nYou have a Straight Flush!\n");
		}
		else if (combo == 9) // Royal FLush
		{
			printf("\nYou have a Royal Flush!\n");
		}
	}
	else if (player == 2) // Computer is Player 2
	{
		if (combo == 0) // No combo
		{
			printf("\nThe Dealer has no viable combo!\n");
		}
		else if (combo == 1) // Pair
		{
			printf("\nThe Dealer has a Pair!\n");
		}
		else if (combo == 2) // Two Pairs
		{
			printf("\nThe Dealer has Two Pairs!\n");
		}
		else if (combo == 3) // Three-of-a-kind
		{
			printf("\nThe Dealer has Three-of-a-kind!\n");
		}
		else if (combo == 4) // Straight
		{
			printf("\nThe Dealer has a Straight!\n");
		}
		else if (combo == 5) // Flush
		{
			printf("\nThe Dealer has a Flush!\n");
		}
		else if (combo == 6) // Full House
		{
			printf("\nThe Dealer has a Full House!\n");
		}
		else if (combo == 7) // Four-of-a-kind
		{
			printf("\nThe Dealer has a Four-of-a-kind!\n");
		}
		else if (combo == 8) // Straight Flush
		{
			printf("\nThe Dealer has a Straight Flush!\n");
		}
		else if (combo == 9) // Royal FLush
		{
			printf("\nThe Dealer has a Royal Flush!\n");
		}
	}
}

/*
	Function Name: print_hand()
	Date Created: 4/15/2025
	Description: This function prints all five cards in a hand for the user to see.
	Inputs: The inputs a Hand struct with all five cards in a hand, an array of strings with each card face in it and an array of strings with each card suit in it.
	Output: There are no outputs.
*/
void print_hand(Hand hand, const char* face[13], const char* suit[4])
{
	for (int i = 0; i < 5; i++)
	{
		printf("\tCard #%d: %5s of %-8s\n", i + 1, face[hand.cards[i].face_index], suit[hand.cards[i].suit_index]);
	}
}
