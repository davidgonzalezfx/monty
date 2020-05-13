#include "monty.h"

/**
 * main - main function
 * Description: global struct created
 * open and read line by line .m file
 * @ac: argument count
 * @av: argument array
 * Return: 0
 */
int main(int ac, char **av)
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
		monty_logic(toks, tok_cnt, &initial);
		initial.line_cnt++;
		tok_cnt = 0;
	}

	return (0);
}
