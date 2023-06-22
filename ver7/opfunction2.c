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

/**
 *o_nop - does nothing
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 *o_sub - subs top element from the second and pops the first
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */

void o_sub(stack_t **head, unsigned int line_number)
{
	int i;
	stack_t *tmp;

	tmp = *head;
	for (i = 0; tmp; i++)
		tmp = tmp->next;
	if (i < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	o_pop(head, line_number);
}

/**
 *o_div - divides the second top element of the stack by the top element
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_div(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int i;

	tmp = *head;
	for (i = 0; tmp; i++)
		tmp = tmp->next;
	if (i < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	(*head)->next->n /= (*head)->n;
	o_pop(head, line_number);
}
