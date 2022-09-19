#include "main.h"
#include <stdio.h>

/**
 * swap_int - function that swaps the values of two integers
 *@a: pointer
 *@b: pointers
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int n;

	n = *b;
	*b = *a;
	*a = n;
	return (0);
}
