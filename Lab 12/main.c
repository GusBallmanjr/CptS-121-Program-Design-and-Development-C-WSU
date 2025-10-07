/*
  Programmer: Gus Ballman
  Class: CptS 121; Lab Section: 07
  Date: 4/9/2025
*/

#include "Header.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	char string[10] = "Cpts 121";

	// Task One:
	reverse_string(string, 0, strlen(string) - 1);
	printf("%s\n", string);

	// Task Two:
	int sum = 0, number = 0;

	printf("Enter Number: ");
	scanf("%d", &number);

	sum = sum_digits(number, sum);
	printf("%d\n", sum);

	// Task Three:
	char maze[8][8] = { "X  X XX",
						"X XX X ",
						"X     X",
						"X XXX  ",
						"    X  ",
						"X X X X",
						"  X   X",
						"XXXXX  " };

	find_path(maze, 0, 1);
	return 0;

}
