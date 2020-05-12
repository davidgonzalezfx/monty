#include "monty.h"

int validate_opcode(char *s)
{
	instruction_t opcodes[] = {
		{"push", add_dnodeint_end},
		{"pint", add_dnodeint_end},
		{"pop", add_dnodeint_end},
		{"swap", add_dnodeint_end},
		{"add", add_dnodeint_end},
		{"nop", add_dnodeint_end} 
	};
}


int main (int ac, char **av)
{
	stack_t *stack = NULL;
	FILE *monty_file;
	char *readed = NULL, *toks = NULL;
	int line_cnt = 0, tok_cnt = 0;
	size_t len = 0;

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
		while (toks && tok_cnt < 2)
		{
			if (tok_cnt == 1)
			{
				toks
			}
			printf ("lei el archivo: %s\n", toks);
			toks = strtok(NULL, " \t\n");
			tok_cnt++;
		}
		line_cnt++;
		tok_cnt = 0;
		printf ("%d\n", line_cnt);
	}

	return (0);
}
