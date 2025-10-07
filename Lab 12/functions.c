/*


*/

#include "Header.h"

void reverse_string(char string[], int start, int end)
{
	char temp;
	if (start > end )
	{
		return;
	}
	else
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		reverse_string(string, start + 1, end - 1);
	}
}

int sum_digits(int num, int sum)
{
	int digit = 0;

	digit = num % 10;

	if (num <= digit)
	{
		return;
	}
	else
	{
		sum += sum_digits(num / 10, sum) + digit;
	}
	return sum;
}

void find_path(char maze[8][8], int start_row, int start_col)
{
	int left = 0, right = 0, up = 0, down = 0, direction = 0, valid = 0;

	if (maze[start_row + 1][start_col] != 'X')
	{
		down = 1;
	}
	if (maze[start_row - 1][start_col] != 'X')
	{
		up = 1;
	}
	if (maze[start_row][start_col + 1] != 'X')
	{
		right = 1;
	}
	if (maze[start_row][start_col - 1] != 'X')
	{
		left = 1;
	}

	if (start_row == 7 && start_col == 7)
	{
		return;
	}
	else
	{
		while (valid != 1)
		{
			direction = (rand() % 4) + 1;
			if (right == 1 && direction == 1 && start_col + 1 < 8)
			{
				valid = 1;
				printf("Location: (%d,%d)\n", start_row, start_col + 1);
				find_path(maze, start_row, start_col + 1);
			}
			else if (left == 1 && direction == 2 && start_col - 1 > 0)
			{
				valid = 1;
				printf("Location: (%d,%d)\n", start_row, start_col - 1);
				find_path(maze, start_row, start_col - 1);
			}
			else if (up == 1 && direction == 3 && start_row - 1 > 0)
			{
				valid = 1;
				printf("Location: (%d,%d)\n", start_row - 1, start_col);
				find_path(maze, start_row - 1, start_col);
			}
			else if (down == 1 && direction == 4 && start_row + 1 < 8)
			{
				valid = 1;
				printf("Location: (%d,%d)\n", start_row + 1, start_col);
				find_path(maze, start_row + 1, start_col);
			}
			else if (down == 0 && left == 0 && right == 0 && up == 0)
			{
				printf("No Possible Path\n");
				return;
			}
		}
	}
	
}
