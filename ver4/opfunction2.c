#include "monty.h"

/**
 *o_add - adds the top two elements of the stack
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_add(stack_t **head, unsigned int line_number)
{
	int i;
	stack_t *tmp;

	tmp = *head;
	for (i = 0; tmp; i++)
		tmp = tmp->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n += (*head)->n;
	o_pop(head, line_number);
}
