#include "monty.h"


int main (int ac, char **av)
{
	FILE *monty_file;
	char* readed = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(av[1], "r");
	if (!monty_file)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
