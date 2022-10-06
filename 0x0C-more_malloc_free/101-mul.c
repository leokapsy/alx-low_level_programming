#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* _isNum - check if is a number
*@num: string to check
*Return: 1 is numm, 0 not num
*/
int _isNum(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
	}
	return (1);
}

/**
* *_memset - copies a character to the firstn characters of the string pointed
*@s: original string
*@b: value to remplace
*@n: number of bytes
*Return: s (string modify)
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
* _strlen - returns the lenght of a string
*@s: poiter of character
*Return: the length of a string
*/
int _strlen(char *s)
{
	int len;

	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

/**
* main - multiple 2 positive numbers
*@argc: argument counter
*@argv: number to multiply
*Return: 0 (success)
*/
void _print(char *str, int l)
	{
		int i, j;

		i = j = 0;
		while (i < l)
		{
			if (str[i] != '0')
				j = 1;
			if (j || i == l - 1)
				_putchar(str[i]);
			i++;
		}

		_putchar('\n');
		free(str);
	}

	/**
	 * mul - multiplies a char with a string and places the answer into dest
	 * @n: char to multiply
	 * @num: string to multiply
	 * @num_index: last non NULL index of num
	 * @dest: destination of multiplication
	 * @dest_index: highest index to start addition
	 *
	 * Return: pointer to dest, or NULL on failure
	 */
	char *mul(char n, char *num, int num_index, char *dest, int dest_index)
	{
		int j, k, mul, mulrem, add, addrem;

		mulrem = addrem = 0;
		for (j = num_index, k = dest_index; j >= 0; j--, k--)
		{
			mul = (n - '0') * (num[j] - '0') + mulrem;
			mulrem = mul / 10;
			add = (dest[k] - '0') + (mul % 10) + addrem;
			addrem = add / 10;
			dest[k] = add % 10 + '0';
		}
		for (addrem += mulrem; k >= 0 && addrem; k--)
		{
			add = (dest[k] - '0') + addrem;
			addrem = add / 10;
			dest[k] = add % 10 + '0';
		}
		if (addrem)
		{
			return (NULL);
		}
		return (dest);
	}
	/**
	 * check_for_digits - checks the arguments to ensure they are digits
	 * @av: pointer to arguments
	 *
	 * Return: 0 if digits, 1 if not
	 */
	int check_for_digits(char **av)
	{
		int i, j;

		for (i = 1; i < 3; i++)
		{
			for (j = 0; av[i][j]; j++)
			{
				if (av[i][j] < '0' || av[i][j] > '9')
					return (1);
			}
		}
		return (0);
	}

	/**
	 * init - initializes a string
	 * @str: sting to initialize
	 * @l: length of strinf
	 *
	 * Return: void
	 */
	void init(char *str, int l)
	{
		int i;

		for (i = 0; i < l; i++)
			str[i] = '0';
		str[i] = '\0';
	}

	/**
	 * main - multiply two numbers
	 * @argc: number of arguments
	 * @argv: argument vector
	 *
	 * Return: zero, or exit status of 98 if failure
	 */
	int main(int argc, char *argv[])
	{
		int l1, l2, ln, ti, i;
		char *a;
		char *t;
		char e[] = "Error\n";

		if (argc != 3 || check_for_digits(argv))
		{
			for (ti = 0; e[ti]; ti++)
				_putchar(e[ti]);
			exit(98);
		}
		for (l1 = 0; argv[1][l1]; l1++)
			;
		for (l2 = 0; argv[2][l2]; l2++)
			;
		ln = l1 + l2 + 1;
		a = malloc(ln * sizeof(char));
		if (a == NULL)
		{
			for (ti = 0; e[ti]; ti++)
				_putchar(e[ti]);
			exit(98);
		}
		init(a, ln - 1);
		for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)