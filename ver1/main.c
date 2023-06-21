#include "monty.h"


/**
 *main - entry point
 *@argc: argc
 *@argv: list of args
 *Return: 0
 */
int main(int argc, char *argv[])
{
	void (*func)(stack_t **stack, unsigned int line_number);
	size_t buf_s = 0;
	int get_line;
	char *tokenized;

	global.fp = check_args(argc, argv);
	global.buffer = NULL;
	global.stack_list = NULL;
	global.line_number = 1;
	get_line = getline(&global.buffer, &buf_s, global.fp);

	while (get_line != -1)
	{
		tokenized = strtok(global.buffer, " \n\t");
		if (tokenized && *tokenized != '#')
		{
			func = get_opcode(tokenized);
			if (func == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction <opcode>\n", global.line_number);
				ffree();
				exit(EXIT_FAILURE);
			}
			global.arg = strtok(NULL, " \n\t");
			func(&global.stack_list, global.line_number);
		}
		get_line = getline(&global.buffer, &buf_s, global.fp);
		global.line_number++;
	}
	ffree();
	return (0);
}

/**
 *check_args - checks if the accepted no. of arg is passed
 *@argc: arg count
 *@argv: vector of args
 *Return: file ppointer
 */
FILE *check_args(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
