#include "monty.h"
#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
    stack_t *current;

    while (stack != NULL)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }
}
/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    instruction_t instruction;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
	printf("%s",line);

        line_number++;
        char *opcode = strtok(line, " \t\n");

        if (opcode == NULL || opcode[0] == '#')
            continue;

        instruction.opcode = opcode;

        if (strcmp(instruction.opcode, "push") == 0)
            instruction.f = push;
        else if (strcmp(instruction.opcode, "pall") == 0)
            instruction.f = pall;
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction.opcode);
            exit(EXIT_FAILURE);
        }

        instruction.f(&stack, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    exit(EXIT_SUCCESS);
}
