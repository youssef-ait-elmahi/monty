#include "monty.h"

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the file.
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{

	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
