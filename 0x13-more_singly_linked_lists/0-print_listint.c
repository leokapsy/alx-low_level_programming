#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_listint - prints all elements of listint_list
 * @h: pointer
 *
 * Return: - number of nodes
 */
size_t print_listint(const listint_t *h);
{
	int count;

	count = 0
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count)
}
