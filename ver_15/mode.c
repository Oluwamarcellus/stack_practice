#include "monty.h"

/**
 *queue - sets the format of the data to a queue (FIFO)
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	global.mode = 2;
}

/**
 *stack - sets the format of the data to a stack (LIFO)
 *@head: linked list
 *@line_number: exec line number
 *Return: void
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	global.mode = 1;
}
