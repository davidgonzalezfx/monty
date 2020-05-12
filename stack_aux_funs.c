#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning
 * @head: doubly linkedlist
 * @n: value of node
 * Return: all the linkedlist
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node || !head)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}
/**
 * add_dnodeint_end - adds a new node at the end
 * @head: doubly linkedlist
 * @n: value of node
 * Return: all the linkedlist
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *actual;

	if (!new_node || !head)
		return (NULL);

	new_node->n = n;

	if (!(*head))
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		actual = *head;

		while (actual->next)
			actual = actual->next;

		new_node->next = NULL;
		new_node->prev = actual;
		actual->next = new_node;
	}

	return (new_node);
}
/**
 * free_dlistint - free a stack_t list
 * @head: doubly linkedlist
 * Return: nothing, just free everything
 */
void free_dlistint(stack_t *head)
{
	stack_t *actual = head;

	while (head)
	{
		actual = head;
		head = actual->next;
		free(actual);
	}
}
/**
 * delete_dnodeint_at_index - deletes the node at index index
 * @head: doubly linkedlist
 * @index: index to remove node
 * Return: 1 if removed, -1 if fails
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *actual = *head;
	unsigned int cnt;

	if (!head || !actual)
		return (-1);

	if (index == 0)
	{
		actual = actual->next;
		free(*head);
		*head = actual;
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}
	for (cnt = 0; actual; cnt++)
	{
		if (cnt == index)
		{
			if (actual->next)
			{
				(actual->prev)->next = actual->next;
				(actual->next)->prev = actual->prev;
				free(actual);
				return (1);
			}
			else
			{
				(actual->prev)->next = NULL;
				free(actual);
				return (1);
			}
		}
		actual = actual->next;
	}

	return (-1);
}
/**
 * print_dlistint - prints all the elements of a stack_t list
 * @h: doubly linkedlist
 * Return: number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		printf("%i\n", h->n);
		num_nodes++;
		h = h->next;
	}

	return (num_nodes);
}
