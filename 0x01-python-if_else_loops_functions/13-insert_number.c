#include "lists.h"
#include <stddef.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @h: A pointer to the head of the linked list
 * @num: number to insert in the singly linked list
 * Return: singly linked list with the new number added
 *
 */
listint_t *insert_node(listint_t **h, int num)
{
	listint_t *node = *h, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = num;

	if (node == NULL || node->n >= num)
	{
		new->next = node;
		*h = new;
		return (new);
	}

	while (node && node->next && node->next->n < num)
		node = node->next;

	new->next = node->next;
	node->next = new;

	return (new);
}
