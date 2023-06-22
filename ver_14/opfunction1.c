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
		if ((global.arg[i] < '0' || global.arg[i] > '9') && global.arg[i] != '-')
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

/**
 *o_pint - prints the value at the top of the list
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 *o_pop - removes the top element of the stack
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
}

/**
 *o_swap - swaps the top two elements
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void o_swap(stack_t **head, unsigned int line_number)
{
	int data, i = 0;
	stack_t *tmp;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		ffree();
		exit(EXIT_FAILURE);
	}
	data = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = data;
}
