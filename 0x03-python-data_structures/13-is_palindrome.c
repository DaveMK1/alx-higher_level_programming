#include "lists.h"

/**
 * reverse_listint - flips the order of a linked list
 * @h: pointer to the initial node in the sequence
 * Return: pointer to the initial node in the reversed list
 */
void reverse_listint(listint_t **h)
{
	listint_t *prev = NULL;
	listint_t *current = *h;
	listint_t *next = NULL;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*h = prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @h: head of the singly linked list
 *
 * Return: 1 if it is, 0 if not
 */
int is_palindrome(listint_t **h)
{
	listint_t *slow = *h, *fast = *h, *temp = *h, *dup = NULL;

	if (*h == NULL || (*h)->next == NULL)
		return (1);

	while (1)
	{
		fast = fast->next->next;
		if (!fast)
		{
			dup = slow->next;
			break;
		}
		if (!fast->next)
		{
			dup = slow->next->next;
			break;
		}
		slow = slow->next;
	}

	reverse_listint(&dup);

	while (dup && temp)
	{
		if (temp->n == dup->n)
		{
			dup = dup->next;
			temp = temp->next;
		}
		else
			return (0);
	}

	if (!dup)
		return (1);

	return (0);
}
