#include "monty.h"
#include <stdlib.h>

/**
 *o_mod - computes the rest of the division of the second top
 *element of the stack by the top element of the stack.
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_mod(stack_t **head, unsigned int line_number)
{
	int i;
	stack_t *tmp;

	tmp = *head;
	for (i = 0; tmp; i++)
		tmp = tmp->next;
	if (i < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	o_pop(head, line_number);
}
