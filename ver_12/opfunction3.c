#include "monty.h"

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

/**
 *o_pchar - prints the char at the top of the stack, followed by a new line
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 *o_pstr - prints the string starting at the top of the stack
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
