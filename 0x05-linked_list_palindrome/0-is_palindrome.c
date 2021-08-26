#include "lists.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
  * is_palindrome - Function that checks if a singly l. list is a palindrome.
  * @head: The pointer to the head of the list.
  *
  * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
  */
int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	int length = 0, i = 0, *array = NULL;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return (1);

	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	array = malloc(sizeof(int) * length);
	tmp = *head;
	while (tmp)
	{
		array[i++] = tmp->n;
		tmp = tmp->next;
	}
	for (i = 0; i < length / 2; i++)
	{
		if (array[i] != array[length - 1 - i])
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
}
