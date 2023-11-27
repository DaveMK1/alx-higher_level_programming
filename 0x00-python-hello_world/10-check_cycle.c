#include "lists.h"

/**
 * check_cycle - check for loop in LL
 * @list: head of linked list
 *
 * Description - check for loops in LL
 * Return: 1 if cycled, 0 if not
 */

int check_cycle(listint_t *list)
{
	listint_t *sl, *f;

	if (!list)
	{
		return (0);
	}
	sl = list;
	f = list->next;
	while (f && sl && f->next)
	{
		if (sl == f)
		{
			return (1);
		}
		sl = sl->next;
		f = f->next->next;
	}
	return (0);
}
