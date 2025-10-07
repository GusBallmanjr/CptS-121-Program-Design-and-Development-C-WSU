/*


*/

#include "lab6.h"

int main(void)
{
	//Task 1:
	FILE* input_stream = NULL;
	input_stream = fopen("inputs.txt", "r");
	int sum1 = 0, sum2 = 0, a = 0, b = 0, i = 0;
	double factorial_total = 0.0, n = 0.0, fib = 0.0, fib1 = 0.0, fib2 = 1.0;

	rewind(input_stream);

	while (!feof(input_stream))
	{
		a = read_integer(input_stream);
		sum1 += a;
	}
	
	fclose(input_stream);

	sum2 = sum_digits(sum1);
	printf("%d\n", sum1);

	if_prime(sum2);

	//Task 2:
	printf("Enter the value of n for a factorial: \n");
	scanf("%lf", &n);

	if (n == 0)
	{
		printf("n! is equal to 1.\n");
	}
	else
	{
		factorial_total = n;
		while (n != 1)
		{
			n = n - 1;
			factorial_total = factorial_total * n;
		}

		printf("n! is equal to %.0lf\n", factorial_total);
	}

	//Task 3:
	printf("Enter the value for n to determine the nth term of the fibonacci sequence: \n");
	scanf("%d", &b);
	i = 1;

	while (i != b)
	{
		fib = fib1 + fib2;
		fib2 = fib1;
		fib1 = fib;
		i++;
	}

	printf("The %d term of the fibonacci sequence is %.0lf.\n", b, fib);

	//Task 4:
	srand((unsigned int)time(NULL));
	int random = 0, sign = 0, choice = 0, num_of_guesses = 0;
	
	sign = rand() % 2;
	random = rand() % 100;

	if (sign == 0)
	{
		random = -1 * random;
	}
	
	printf("Type in an integer from -100 to 100 to guess the random number.\n");

	while (choice != random)
	{
		scanf("%d", &choice);
		num_of_guesses++;

		if (choice > 100 || choice < -100)
		{
			printf("Invalid input, Try again!\n");
		}
		else if (choice > random)
		{
			printf("Guess was heigher than the random number!\n");
		}
		else if (choice < random)
		{
			printf("Guess was lower than the random number!\n");
		}
		else if (choice == random)
		{
			printf("You Guessed it!\n");
		}
	}
	printf("It took you %d guesses to guess the number!\n", num_of_guesses);


	return 0;
}