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
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = dlistint_len(*stack);
	(void)line_number;

	if (len <= 0)
	{
		printf("\n");
		return;
	}
	while (aux->next)
		aux = aux->next;
	while (aux->prev)
	{
		if (isascii(aux->n) == 0 || aux->n == 0)
			break;
		printf("%c", aux->n);
		aux = aux->prev;
	}
	printf("\n");
}
