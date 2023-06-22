#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/**LIBRARIES*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/**STRUCTS*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Global - Global vaariable
 * @line_number: line_number
 * @arg: opcode argument
 * @buffer: buffer written from file
 * @stack_list: linked list
 * @fp: file pointer
 * Description: Consist of the global variables in the program
 */
struct Global
{
	int line_number;
	char *arg;
	char *buffer;
	stack_t *stack_list;
	FILE *fp;
} global;


/**FUNCTIONS DECLARATIONS*/
FILE *check_args(int argc, char *argv[]);
void (*get_opcode(char *tokenized))(stack_t **stack, unsigned int line_number);
void o_push(stack_t **stack, unsigned int line_number);
void push_start(stack_t **head, int data);
void push_end(stack_t **head, int data);
void ffree(void);
void o_pall(stack_t **head, unsigned int line_number);
void o_pint(stack_t **head, unsigned int line_number);
void o_pop(stack_t **head, unsigned int line_number);
void o_swap(stack_t **head, unsigned int line_number);
void o_add(stack_t **head, unsigned int line_number);
void o_nop(stack_t **head, unsigned int line_number);
void o_sub(stack_t **head, unsigned int line_number);
void o_div(stack_t **head, unsigned int line_number);
void o_mul(stack_t **head, unsigned int line_number);

#endif
