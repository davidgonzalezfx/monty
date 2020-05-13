#include "monty.h"

/**
 * sub - sub last to elements in one
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = dlistint_len(*stack);
	int tmp;
	(void) line_number;

	if (len < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}

	while (aux->next)
		aux = aux->next;
	tmp = aux->prev->n - aux->n;
	aux->prev->n = tmp;
	delete_dnodeint_at_end(stack);
}

/**
 * _div - div last to elements in one
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = dlistint_len(*stack);
	int tmp;
	(void) line_number;

	if (len < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}

	while (aux->next)
		aux = aux->next;
	if (aux->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}
	tmp = aux->prev->n / aux->n;
	aux->prev->n = tmp;
	delete_dnodeint_at_end(stack);
}

/**
 * mul - mul last to elements in one
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = dlistint_len(*stack);
	int tmp;
	(void) line_number;

	if (len < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}

	while (aux->next)
		aux = aux->next;
	tmp = aux->prev->n * aux->n;
	aux->prev->n = tmp;
	delete_dnodeint_at_end(stack);
}

/**
 * mod - mod last to elements in one
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = dlistint_len(*stack);
	int tmp;
	(void) line_number;

	if (len < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}

	while (aux->next)
		aux = aux->next;
	if (aux->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}
	tmp = aux->prev->n % aux->n;
	aux->prev->n = tmp;
	delete_dnodeint_at_end(stack);
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int len = dlistint_len(*stack);
	(void)line_number;

	if (len <= 0)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}
	while (aux->next)
		aux = aux->next;
	if (isascii(aux->n) == 0)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", initial.line_cnt);
		free_dlistint(initial.head);
		free(initial.readed);
		fclose(initial.monty_file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", aux->n);
}
