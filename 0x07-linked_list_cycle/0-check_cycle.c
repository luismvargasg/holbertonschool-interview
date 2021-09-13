  
#include "lists.h"

/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: Given list to find if it has a cycle.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *hare = list, *tortoise = list;

	while (hare && tortoise && hare->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (hare == tortoise)
			return (1);
	}
	return (0);
}
