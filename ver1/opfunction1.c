#include "monty.h"

/**
 *o_push - adds to the top of the stack
 *@stack: the linked list
 *@line_number: exec line number
 *Return: void
 */

void o_push(stack_t **stack, unsigned int line_number)
{
	int i = 0, num;

	if (!global.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	while (global.arg[i] != '\0')
	{
		if (global.arg[i] < '0' || global.arg[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			ffree();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	num = atoi(global.arg);
	push_start(stack, num);
}


/**
 *o_pall - prints list
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *head;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
