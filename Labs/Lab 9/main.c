/*

*/

#include "lab9.h"

int main(void)
{
	char str[20] = "CptS 121 is cool!", str2[20] = "Bike", str3[20] = "wow", str4[20] = "pig", str5[20] = "CptS 121 is cool!";
	int value = -1, size = 0;
	
	my_strcpy(str2, str3);
	printf("%s\n", str2);

	my_strcat(str3, str4);
	printf("%s\n", str3);

	value = my_strcmp(str4, str2);
	printf("%d\n", value);

	size = my_strlen(str4);
	printf("%d\n", size);

	string_reverse_array_notation(str, 18);
	printf("String: %s\n", str);

	string_reverse_pointer_notation(str5);
	printf("String: %s\n", str);

	return 0;
}