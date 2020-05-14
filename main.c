#include "monty.h"

global initial;

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
	char *toks = NULL;
	int tok_cnt = 0;
	size_t len = 0;
	instruction_t opcodes[18] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"nop", empty}, {"sub", sub}, {"div", _div},
		{"mul", mul}, {"mod", mod}, {"#", empty}, {"pchar", pchar},
		{"pstr", pstr}, {"rotr", rotr}, {"rotl", rotl}, {"push", push},
		{"queue", empty}, {"stack", empty}};

	initial.mode = 0;
	initial.op_code = NULL;
	initial.number = 0;
	initial.line_cnt = 1;
	initial.readed = NULL;
	initial.head = NULL;
	initial.monty_file = NULL;
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	initial.monty_file = fopen(av[1], "r");
	if (!initial.monty_file)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&(initial.readed), &len, initial.monty_file) != -1)
	{
		toks = strtok(initial.readed, " \t\n");
		monty_logic(toks, tok_cnt, &(initial.head), opcodes);
		initial.line_cnt++;
		tok_cnt = 0;
	}
	free_dlistint(initial.head);
	free(initial.readed);
	fclose(initial.monty_file);
	return (0);
}
