#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct dat - handle variables to modes
 * @mode: the monty mode
 * @op_code: first token to validar with commands
 * @number: integer to put in the stack or queue
 * @line_cnt: counter for lines in .m file
 * @readed: buffer used in getline
 * @head: stack/queue pointer
 * @monty_file: .m file
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct dat
{
	int mode;
	char *op_code;
	int number;
	int line_cnt;
	char *readed;
	stack_t *head;
	FILE *monty_file;
} global;

extern global initial;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* stack_aux_funs.c */
int delete_dnodeint_at_end(stack_t **head);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_dlistint(stack_t *h);
void free_dlistint(stack_t *head);

/* stack_aux2_funs.c */
size_t dlistint_len(const stack_t *h);
int is_num(char *token);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* stack_core_funs.c */
void swap(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* stack_logic_funs.c */
int validate_opcode(char *s, instruction_t opcodes[]);
void monty_logic(char *toks, int tok_cnt, stack_t **head,
				instruction_t opcodes[]);
void empty(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void handle_errors(void);

/* stack_advanced_funs.c */
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
