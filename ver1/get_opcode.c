#include "monty.h"

/**
 *get_opcode - gets the opcode and returns it
 *@tokenized: tokenized string (oppcode)
 *Return: function pointer
 */

void (*get_opcode(char *tokenized))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", o_push},
		{"pall", o_pall},
		{NULL, NULL}
	};
	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, tokenized) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
