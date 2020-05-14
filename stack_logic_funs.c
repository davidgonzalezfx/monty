#include "monty.h"
/**
 * empty - funcion for non executable op_codes
 * @stack: stack/queue structure
 * @line_number: line_cnt
 */
void empty(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * push - fuction to push command
 * @stack: global structure
 * @line_number: varible to handle number of line
 * Return: none
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (initial.mode == 0)
		add_dnodeint_end(stack, initial.number);
	else
		add_dnodeint(stack, initial.number);
}
/**
 * handle_errors - print errors handler
 * Return: void
 */
void handle_errors(void)
{
	if (strcmp(initial.op_code, "push") == 0)
		dprintf(2, "L%d: usage: push integer\n", initial.line_cnt);
	else
		dprintf(2, "L%d: unknown instruction %s\n", initial.line_cnt,
				initial.op_code);
	free_dlistint(initial.head);
	free(initial.readed);
	fclose(initial.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * validate_opcode - function that validates
 * first token against valid option
 * @s: first token of line
 * @opcodes: dictonary with valid opcodes
 * Return: 0 if command expect second argument
 * 1 if command don't requires
 * -1 if command isn't valid
 */
int validate_opcode(char *s, instruction_t opcodes[])
{
	int iter = 0;

	if (strcmp(s, opcodes[15].opcode) == 0)
	{
		initial.op_code = s;
		return (15);
	}
	if (strcmp(s, opcodes[16].opcode) == 0)
	{
		initial.mode = 1;
		return (16);
	}
	if (strcmp(s, opcodes[17].opcode) == 0)
	{
		initial.mode = 0;
		return (17);
	}

	while (iter <= 15)
	{
		if (strcmp(s, opcodes[iter].opcode) == 0)
		{
			initial.op_code = s;
			return (iter);
		}
		iter++;
	}
	initial.op_code = s;
	handle_errors();
	return (-1);
}

/**
 * monty_logic - all logic of monty project
 * @toks: actual token
 * @tok_cnt: tokens counter
 * @head: head of stack/queue
 * @opcodes: valid opcodes dictonary
 */
void monty_logic(char *toks, int tok_cnt, stack_t **head,
				instruction_t opcodes[])
{
	int is_valid;

	while (toks && tok_cnt < 2)
	{
		if (toks[0] == '#')
			return;
		if (tok_cnt == 0)
		{
			/* validar por stack - queue or op_code */ /* *opcodes[] */
			is_valid = validate_opcode(toks, opcodes);

			if (is_valid == 15)
				tok_cnt = 1;
			else
				tok_cnt = 2;
		}
		if (tok_cnt == 1)
		{
			/* validar que sea número */
			toks = strtok(NULL, " \t\n");
			/* printf("line number is: %d\n",initial.line_cnt);*/
			if (is_num(toks) == 1)
				initial.number = atoi(toks);
			else
				handle_errors();
			tok_cnt++;
		}
		/* ejecutar instrucción */
		opcodes[is_valid].f(head, initial.line_cnt);
	}
}
