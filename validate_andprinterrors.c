#include "monty.h"

void ghost(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * print_error_num - print errors handler
 * @initial: global struct
 * Return: void
 */
void print_error_num(global *initial)
{
	if (strcmp(initial->op_code, "push") == 0)
		dprintf(2, "L%d: usage: push integer\n", initial->line_cnt);
	else
		dprintf(2, "L%d: unknown instruction: %s\n", initial->line_cnt,
				initial->op_code);
	exit(EXIT_FAILURE);
}

/**
 * temp - tmp function
 * @toks: actual token
 * @tok_cnt: tokens counter
 * @initial: global struct
 */
void temp(char *toks, int tok_cnt, global *initial)
{
	int is_valid;
	instruction_t opcodes[9] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", ghost},
		{"push", push}, {"queue", ghost}, {"stack", ghost}};

	while (toks && tok_cnt < 2)
	{
		if (tok_cnt == 0)
		{
			/* validar por stack - queue or op_code */ /* *opcodes[] */
			is_valid = validate_opcode(initial, toks, opcodes);

			if (is_valid == 6)
				tok_cnt = 1;
			else
				tok_cnt = 2;
		}
		if (tok_cnt == 1)
		{
			/* validar que sea número */
			toks = strtok(NULL, " \t\n");
			if (atoi(toks) != 0)
				initial->number = atoi(toks);
			else
				print_error_num(initial);
			tok_cnt++;
		}
		/* ejecutar instrucción */
		stack_t **none = NULL;
		opcodes[is_valid].f(none, initial->line_cnt);
	}
}

/**
 * push - fuction to push command
 * @stack: global structure
 * @line_number: varible to handle number of line
 * Return: none
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("push called\n");
}


/**
 * validate_opcode - function that validates
 * first token against valid option
 * @initial: global structure
 * @s: first token of line
 * Return: 0 if command expect second argument
 * 1 if command don't requires
 * -1 if command isn't valid
 */
int validate_opcode(global *initial, char *s, instruction_t opcodes[])
{
	int iter = 0;

	if (strcmp(s, opcodes[6].opcode) == 0)
	{
		initial->op_code = s;
		return (6);
	}
	if (strcmp(s, opcodes[7].opcode) == 0)
	{
		initial->mode = 1;
		return (7);
	}
	if (strcmp(s, opcodes[8].opcode) == 0)
	{
		initial->mode = 0;
		return (8);
	}

	while (iter <= 6)
	{
		if (strcmp(s, opcodes[iter].opcode) == 0)
		{
			initial->op_code = s;
			return (iter);
		}
		iter++;
	}
	initial->op_code = s;
	print_error_num(initial);
	return (-1);
}
