#include "monty.h"


/**
 *push_start - adds a new node at the beginning of a list
 *@head: linked list
 *@data: node data
 *Return: void
 */

void push_start(stack_t **head, int data)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		ffree();
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
}

/**
 *push_end - adds a new node at the end of a list
 *@head: linked list
 *@data: node data
 *Return: void
 */
void push_end(stack_t **head, int data)
{
	stack_t *new = NULL, *tmp = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		ffree();
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}


/**
 *ffree - frees allocated mem spaces
 *Return: void
 */
void ffree(void)
{
	if (global.buffer)
	{
		free(global.buffer);
		global.buffer = NULL;
	}
	if (global.stack_list)
	{
		stack_t *tmp;

		while (global.stack_list != NULL)
		{
			tmp = global.stack_list;
			global.stack_list = tmp->next;
			free(tmp);
		}
		global.stack_list = NULL;
	}
	fclose(global.fp);
}



























