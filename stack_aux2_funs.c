#include "monty.h"
/**
 * dlistint_len - return length of linkedlist
 * @h: doubly linkedlist
 * Return: number of elements in a linked dlistint_t list
 */
size_t dlistint_len(const stack_t *h)
{
	size_t length = 0;

	while (h)
		h = h->next, length++;

	return (length);
}
/**
 * is_num - check if string is a number
 * @token: token string to check
 * Return: 1 if is number, 0 otherwise
 */
int is_num(char *token)
{
	int chr = 0;

	if (!token)
		return (0);

	while (token[chr])
	{
		if (isdigit(token[chr]) == 0 && token[chr] != '-')
			return (0);
		chr++;
	}

	return (1);
}