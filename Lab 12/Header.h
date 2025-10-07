/*
  Programmer: Gus Ballman
  Class: CptS 121; Lab Section: 07
  Date: 4/9/2025
*/

#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void reverse_string(char string[], int start, int end);
int sum_digits(int num, int sum);
void find_path(char maze[8][8], int start_row, int start_col);


#endif
