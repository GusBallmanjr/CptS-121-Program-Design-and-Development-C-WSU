/*


*/

#include "lab6.h"

int read_integer(FILE* infile)
{
	int a = 0;
	fscanf(infile, "%d", &a);
	return a;
}

int sum_digits(int n)
{
	int sum = 0, digit = 0;

	digit = n % 10;
	sum = sum + digit;

	while (n > digit)
	{
		n = n / 10;
		digit = n % 10;
		sum = sum + digit;
	}
	return sum;
}

void if_prime(int sum)
{
	if (sum % 2 == 0 || sum % 3 == 0 || sum % 5 == 0 || sum % 7 == 0)
	{
		printf("The sum of the integers, %d, is not prime.\n", sum);
	}
	else
	{
		printf("The sum of the integers, %d, is prime.\n", sum);
	}
}