#include "monty.h"

int validate_opcode(global *initial, char *s)
{
	int iter = 0;
	instruction_t pcodes[9] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", NULL},
		{"push", push}, {"queue", NULL}, {"stack", NULL}};

	if (strcmp(s, opcodes[6][0]) == 0)
	{
		initial->op_code = s;
		return (0);
	}
	if (strcmp(s, opcodes[7][0]) == 0)
	{
		initial->mode = 1;
		return (1);
	}
	if (strcmp(s, opcodes[8][0]) == 0)
	{
		initial->mode = 0;
		return (1);
	}

	while (iter <= 6)
	{
		if (strcmp(s, opcodes[iter][0]) == 0)
		{
			initial->op_code = s;
			return (1);
		}
		iter++;
	}
	initial->op_code = s;
	print_error_num(initial);
	return (-1);
}

void print_error_num(global *initial)
{
	if (strcmp(initial->op_code, "push") == 0)
		dprintf(2, "L%d: usage: push integer\n", initial->line_cnt);
	else
		dprintf(2, "L%d: unknown instruction: %s\n", initial->line_cnt, initial->op_code);
	exit(EXIT_FAILURE);
}

void temp(char *toks, int tok_cnt, global *initial)
{
	while (toks && tok_cnt < 2)
	{
		if (tok_cnt == 0)
		{
			/* validar por stack - queue or op_code */
			int is_valid = validate_opcode(initial ,toks);
			if(is_valid == 0)
				tok_cnt++;
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
	}
}

int main (int ac, char **av)
{
	/* stack_t *stack = NULL; */
	FILE *monty_file;
	char *readed = NULL, *toks = NULL;
	int tok_cnt = 0;
	size_t len = 0;

	global initial;
	initial.mode = 0;
	initial.op_code = NULL;
	initial.number = 0;
	initial.line_cnt = 0;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(av[1], "r");
	if (!monty_file)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&readed, &len, monty_file) != -1)
	{
		toks = strtok(readed, " \t\n");
		temp(toks, tok_cnt, &init);
		initial.line_cnt++;
		printf ("%d\n", initial.line_cnt);
		tok_cnt = 0;
	}

	return (0);
}
