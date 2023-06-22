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
		{"pint", o_pint},
		{"pop", o_pop},
		{"swap", o_swap},
		{"add", o_add},
		{"nop", o_nop},
		{"sub", o_sub},
		{"div", o_div},
		{"mul", o_mul},
		{"mod", o_mod},
		{"pchar", o_pchar},
		{"pstr", o_pstr},
		{"rotl", o_rotl},
		{"rotr", o_rotr},
		{"queue", queue},
		{"stack", stack},
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
