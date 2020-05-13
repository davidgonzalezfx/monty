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
	stack_t *newnode, *aux = *head;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!*head)
	{
		*head = newnode;
		return (newnode);
	}
	while (aux->next)
		aux = aux->next;
	aux->next = newnode;
	newnode->prev = aux;
	return (newnode);
}

/**
 * free_dlistint - free a stack_t list
 * @head: doubly linkedlist
 * Return: nothing, just free everything
 */
void free_dlistint(stack_t *head)
{
	stack_t *aux = head;

	if (!head)
		return;
	while (aux->next)
	{
		aux = aux->next;
		free(head);
		head = aux;
	}
	free(aux);
}
/**
 * delete_dnodeint_at_end - deletes the node at end
 * @head: doubly linkedlist
 * Return: 1 if removed, -1 if fails
 */
int delete_dnodeint_at_end(stack_t **head)
{
	stack_t *aux = *head, *aux2 = aux;
	int index = dlistint_len(*head) - 1;
	int iter = 0;

	if (!*head)
		return (-1);
	if (index == 0)
	{
		*head = aux->next;
		if (aux->next != NULL)
			aux->next->prev = NULL;
		free(aux);
		return (1);
	}
	while (aux)
	{
		if (!aux->next && iter == index)
		{
			aux2 = aux->prev;
			aux2->next = NULL;
			return (free(aux), 1);
		}
		if (iter == index)
		{
			aux2 = aux->prev;
			aux2->next = aux->next;
			aux->next->prev = aux2;
			free(aux);
			return (1);
		}
		aux = aux->next;
		iter++;
	}
	return (-1);
}

/**
 * print_dlistint - prints all the elements of a stack_t list
 * @h: doubly linkedlist
 * Return: number of nodes
 */
size_t print_dlistint(stack_t *h)
{
	size_t num_nodes = 0;
	stack_t *aux = h;

	if (!h)
		return (0);

	if (!h->next)
	{
		return (printf("%d\n", h->n), 0);
	}

	while (aux->next)
		aux = aux->next;

	while (aux)
	{
		printf("%i\n", aux->n);
		num_nodes++;
		aux = aux->prev;
	}

	return (num_nodes);
}
