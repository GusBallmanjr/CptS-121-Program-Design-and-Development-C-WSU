/*
	Programmer: Gus Ballman
	Class: CptS 121; Lab section: 07
	Description: This program is a text based version of 5 card poker. The Player will be delt five cards from a shuffled deck and will have two chances to replace up to three cards. They will have a chance to bet and will be playing against the dealer.
*/

#include "PA7.h"

int main(void)
{
	srand((unsigned int)time(NULL)); /* seed random-number generator */

	int money = 500, game_mode = 0;

	while (game_mode != 3)
	{
		int choice = -1, back_to_menu = 0, deck[4][13] = { 0 }, combo = 0, combo_computer = 0, draw_number = 0, card_starting_point = 0, number_of_cards_already_drawn = 0, frequency_comp[13] = { 0 }, repeated_face = 0, save_cards[5] = { 0,0,0,0,0 }, bet = 0, player_card_score = 0, computer_card_score = 0;
		/* initialize suit array */
		const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

		/* initialize face array */
		const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
			"Nine", "Ten", "Jack", "Queen", "King" };

		Hand hand = { {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}} }, hand_computer = { {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}} };

		shuffle(deck);
		display_menu();
		while (game_mode == 0)
		{
			choice = get_choice();

			if (choice == 1) //Rules Menu
			{
				system("cls");
				display_rules();
				back_to_menu = 0;
				system("pause");
				system("cls");
				display_menu();
			}
			else if (choice == 2) //Play Game
			{
				game_mode = 2;
				system("cls");
			}
			else if (choice == 3) //Exit Game
			{
				game_mode = 3;
				system("cls");
				return 0;
			}
			else if (choice != 1 || choice != 2 || choice != 3 || choice != -1) //input validation
			{
				printf("Invalid Input. Try Again.\n");
				choice = get_choice();
			}
		}

		if (game_mode == 2) // Play Game
		{
			deal(deck, &hand, 5, &number_of_cards_already_drawn, 0); // Deal Player 5 cards

			system("cls");
			printf("You have $%d to bet.\n", money); // amount allowed to bet
			printf("Your cards are:\n\n");
			print_hand(hand, face, suit); // Prints players hand
			combo = which_hand(hand); // Determines combo player has
			combination(combo, 1); // Prints combo that player has

			printf("How many cards would you like to be redrawn? (Up to three cards)\n");
			scanf("%d", &draw_number);

			while (draw_number >= 4 || draw_number <= -1) // Input validation for number of cards to be redrawn
			{
				printf("Invalid Input. Try Again\n");
				scanf("%d", &draw_number);
			}

			if (draw_number != 0)
			{
				printf("Which cards would you like to have redrawn?\n"); // Redraw #1
				for (int i = 0; i < draw_number; i++)
				{
					scanf("%d", &card_starting_point);

					while (card_starting_point >= 6 || card_starting_point <= -1)
					{
						printf("Invalid Input. Try Again\n");
						scanf("%d", &card_starting_point);
					}
					deal(deck, &hand, 1, &number_of_cards_already_drawn, card_starting_point - 1);
				}
				system("cls");
				printf("Your cards are:\n\n");
				print_hand(hand, face, suit);
				combo = which_hand(hand);
				combination(combo, 1);

				printf("How many cards would you like to be redrawn? (Up to three cards)\n");
				scanf("%d", &draw_number);

				while (draw_number >= 4 || draw_number <= -1) // Input validation for number of cards to be redrawn
				{
					printf("Invalid Input. Try Again\n");
					scanf("%d", &draw_number);
				}

				if (draw_number != 0)
				{
					printf("Which cards would you like to have redrawn?\n"); // Redraw #2
					for (int i = 0; i < draw_number; i++)
					{
						scanf("%d", &card_starting_point);

						while (card_starting_point >= 6 || card_starting_point <= -1)
						{
							printf("Invalid Input. Try Again\n");
							scanf("%d", &card_starting_point);
						}
						deal(deck, &hand, 1, &number_of_cards_already_drawn, card_starting_point - 1);
					}
				}

				system("cls");
				printf("Your cards are:\n\n");
				print_hand(hand, face, suit);
				combo = which_hand(hand);
				combination(combo, 1);
			}

			// Computers hand:
			deal(deck, &hand_computer, 5, &number_of_cards_already_drawn, 0); // Draw Computer's hand
			combo_computer = which_hand(hand_computer);
			if (combo_computer == 1) // Pair
			{
				draw_number = 3;
			}
			else if (combo_computer == 2) // Two Pairs
			{
				draw_number = 1;
			}
			else if (combo_computer == 3) // Three-of-a-kind
			{
				draw_number = 2;
			}
			else if (combo_computer == 4) // Four-of-a-kind
			{
				draw_number = 1;
			}
			else if (combo_computer == 5) // Full House
			{
				draw_number = 0;
			}
			else if (combo_computer == 6) // Flush
			{
				draw_number = 0;
			}
			else if (combo_computer == 7) // Straight
			{
				draw_number = 0;
			}
			else if (combo_computer == 0) // No combo
			{
				draw_number = 3;
			}

			if (draw_number != 0)
			{
				for (int f = 0; f < 5; f++) // Frequency table for face
				{
					for (int i = 1; i < 14; i++)
					{
						if (hand_computer.cards[f].face_index == i)
						{
							frequency_comp[i - 1]++;
						}
					}
				}

				for (int i = 0; i < 13; i++)
				{
					if (frequency_comp[i] >= 2) // Frequency table for computer's hand
					{
						repeated_face = i + 1; // represents any repeated numbers that will be kept
						for (int index = 0; index < 5; index++)
						{
							if (hand_computer.cards[index].face_index == repeated_face)
							{
								save_cards[index] = 1; // which cards should not be redrawn
							}
						}
					}
				}

				for (int j = 0; j < draw_number; j++)
				{
					if (save_cards[j] == 0)
					{
						deal(deck, &hand_computer, 1, &number_of_cards_already_drawn, j);
					}
				}
			}

			combo_computer = which_hand(hand_computer);
			if (combo_computer == 1) // Pair
			{
				draw_number = 3;
			}
			else if (combo_computer == 2) // Two Pairs
			{
				draw_number = 1;
			}
			else if (combo_computer == 3) // Three-of-a-kind
			{
				draw_number = 2;
			}
			else if (combo_computer == 4) // Four-of-a-kind
			{
				draw_number = 1;
			}
			else if (combo_computer == 5) // Full House
			{
				draw_number = 0;
			}
			else if (combo_computer == 6) // Flush
			{
				draw_number = 0;
			}
			else if (combo_computer == 7) // Straight
			{
				draw_number = 0;
			}
			else if (combo_computer == 0) // No combo
			{
				draw_number = 3;
			}

			if (draw_number != 0) // redraw #2
			{
				for (int f = 0; f < 5; f++) // Frequency table for face
				{
					for (int i = 1; i < 14; i++)
					{
						if (hand_computer.cards[f].face_index == i)
						{
							frequency_comp[i - 1]++;
						}
					}
				}

				for (int i = 0; i < 13; i++)
				{
					if (frequency_comp[i] >= 2) // Frequency table for computer's hand
					{
						repeated_face = i + 1; // represents any repeated numbers that will be kept
						for (int index = 0; index < 5; index++)
						{
							if (hand_computer.cards[index].face_index == repeated_face)
							{
								save_cards[index] = 1; // which cards should not be redrawn
							}
							else
							{
								save_cards[index] = 0;
							}
						}
					}
				}

				for (int j = 0; j < draw_number; j++)
				{
					if (save_cards[j] == 0)
					{
						deal(deck, &hand_computer, 1, &number_of_cards_already_drawn, j);
					}
				}
			}

			// Betting:
			printf("\nYou have $%d to bet.\n", money);
			printf("Place your bets: (Zero represents a fold)\n");
			scanf("%d", &bet);

			while (bet < 0 || bet > money)
			{
				printf("Invalid Input. Try Again\n");
				scanf("%d", &bet);
			}

			system("cls");
			printf("Your cards are:\n");
			print_hand(hand, face, suit);
			combo = which_hand(hand);
			combination(combo, 1);

			printf("\nThe Dealer's cards are:\n");
			print_hand(hand_computer, face, suit);
			combo_computer = which_hand(hand_computer);
			combination(combo_computer, 2);

			if (combo < combo_computer) // Dealer has better hand
			{
				printf("\nThe dealer wins!\n");
				money -= bet;
			}
			else if (combo > combo_computer) // Player has better hand
			{
				printf("\nYou win!\n");
				money += bet;
			}
			else if (combo == combo_computer) // Draw in type of hand
			{
				for (int i = 0; i < 5; i++) // Adds up value of every card in player and computers hands (individually)
				{
					player_card_score += hand.cards[i].face_index;
					computer_card_score += hand_computer.cards[i].face_index;
				}
				// Comparing scores:
				if (player_card_score > computer_card_score)
				{
					printf("\nYou win! (Your card values are worth more than the dealers!)\n");
					money += bet;
				}
				else if (player_card_score < computer_card_score)
				{
					printf("\nThe dealer wins! (The dealer's card values are worth more than yours!)\n");
					money -= bet;
				}
				else if (player_card_score == computer_card_score)
				{
					printf("\nDraw! Your cards are equal in value to the dealers! No money lost!\n");
				}
			}

			printf("\nYou now have $%d to bet.\n", money);

			if (money == 0)
			{
				printf("You ran out of money to bet! You Lose!\n");
				game_mode = 3;
				return 0;
			}
			else
			{
				system("pause");
				system("cls");
				game_mode = 0;
				choice = -1;
			}
		}
	}
	return 0;
}