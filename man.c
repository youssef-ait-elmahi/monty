#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int number) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    } else {
        stack[++top] = number;
    }
}

void pall() {
    if (top == -1) {
        return;
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./monty file.m\n");
        return EXIT_FAILURE;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return EXIT_FAILURE;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, " \t\n");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "push") == 0) {
            token = strtok(NULL, " \t\n");
            if (token == NULL) {
                printf("Error: Missing argument for push\n");
                return EXIT_FAILURE;
            }
            int number = atoi(token);
            push(number);
        } else if (strcmp(token, "pall") == 0) {
            pall();
        }
    }

    fclose(file);
    return 0;
}
