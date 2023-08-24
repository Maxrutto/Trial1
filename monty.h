#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

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
 * struct variables - Global structure that'll be used in the functions
 * @arg: The second parameter in the current line when running./monty
 * @cont: current line
 * @h: The doubly linked list nodes
 * @fp: File pointer
 * @lifo: Condition for either stack or queue
 * @buf: Input buffer
 *
 * Description: Doubly linked list structure for monty bytecodes,
 * stack, queues, LIFO and FIFO
 */
typedef struct variables
{
	char *arg;
	unsigned int cont;
	stack_t *h;
	FILE *fp;
	int lifo;
	char *buf;
} global_t;

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

extern global_t var;

void free_doubly(stack_t *h);
void free_var(void);
void init_var(FILE *fd);
FILE *f_read(int argc, char **argv);
stack_t *add_node_start(stack_t **h, const int n);
stack_t *add_node_end(stack_t **h, const int n);
void push_op(stack_t **stack, unsigned int line_no);
void pall_op(stack_t **stack, unsigned int line_no);
int is_int(const char *str);
int str_cmp(char *str1, char *str2);
void (*use_opcodes(char *op))(stack_t **stack, unsigned int line_no);
void *_calloc(unsigned int nmem, unsigned int size);
void store_line(char **lineptr, char *buf, size_t *size, size_t buf_size);
ssize_t _getline(char **lineptr, size_t *size, FILE *fp);

#endif
