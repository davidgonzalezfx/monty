#include "monty.h"
/**
 * pall - print all function
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	print_dlistint(*stack);
}
/**
 * pint - print int
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void) line_number;

	if (!(*stack))
	{
		printf("L%d: can't pint, stack empty\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		printf("%d\n", (*stack)->n);
		return;
	}

	while (aux->next)
		aux = aux->next;
	printf("%d\n", aux->n);
}
/**
 * pop - remove element from stack/queue
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (!(*stack))
	{
		printf("L%d: can't pop an empty stack\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}
	else
		delete_dnodeint_at_end(stack);
}
/**
 * swap - swap last two elements
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("swap called\n");
}
/**
 * add - add last to elements in one
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("add called\n");
}
