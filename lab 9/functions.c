/*

*/

#include "lab9.h"

void string_reverse_pointer_notation(char *str)
{
	int size = 0;
	char first = '\0', last = '\0', temp = '\0';
	first = *str;
	while (*str != '\0')
	{
		size++;
		*str++;
	}
	last = *str - 1;
	*str = 0;
	for (int i = 0; i < size; i++)
	{
		temp = *str;
		*str = str;

	}

}

void string_reverse_array_notation(char str[], int size)
{
	char first = '\0', last = '\0', current = '\0';
	int i = 0;
	size = size - 1;
	first = str[0];
	last = str[size - 1];
	i = 1;
	while (i != (size / 2) + 1)
	{
		current = str[i];
		str[i] = str[size - i - 1];
		str[size - i -1] = current;
		i++;
	}
	str[size - 1] = first;
	str[0] = last;
}

char* my_strcpy(char destination[], const char source[])
{
	int i = 0;
	while (destination[i - 1] != '\0' || i == 0)
	{
		destination[i] = source[i];
		i++;
	}
}

char* my_strcat(char destination[], const char source[])
{
	int i = 0, size = 0, j = 0;
	while (destination[i] != '\0' || i == 0)
	{
		size++;
		i++;
	}
	size = size - 1;
	//destination[i + 1] = source[j];
	//j++;
	while (source[j] != '\0')
	{
		destination[(size + 1) + j] = source[j];
		j++;
	}
}

int my_strcmp(const char s1[], const char s2[])
{
	int i = 0;
	while (s1[i - 1] != '\0' && s2[i - 1] != '\0' || i == 0)
	{
		if (s1[i] > s2[i])
		{
			return -1;
		}
		else if (s1[i] < s2[i])
		{
			return 1;
		}
	}
	if (s1[i - 1] == s2[i - 1])
	{
		return 0;
	}
}

int my_strlen(const char s[])
{
	int i = 0, size = 0;
	while (s[i - 1] != '\0' || i == 0)
	{
		size++;
		i++;
	}
	return size - 1;
}