#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

// Enumeration for token types
typedef enum {
    KEYWORD, IDENTIFIER, OPERATOR, SPECIAL_CHARACTER, CONSTANT, LITERAL, ERROR
} TokenType;

// List of keywords
const char *keywords[] = {"int", "return", "for", "if", "while", "else", "printf", "void", "char", "float"};
int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

// Check if a string is a keyword
int isKeyword(char *word) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' ||
           ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == ';';
}

// Main lexical analysis function
void Tokenizer(char *input) {
    int i = 0;
    char current[100];  // Temporary buffer to store lexemes
    int currentIndex = 0;  // Index for the current buffer

    printf("Parsing : test.c : Started\n");

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            // Ignore spaces
            i++;
        } else if (isOperator(input[i])) {
            // Operator or special character
            printf("Operator   : %c\n", input[i]);
            i++;
        } else if (isdigit(input[i])) {
            // Constant (Literal for numbers)
            currentIndex = 0;
            while (isdigit(input[i])) {
                current[currentIndex++] = input[i++];
            }
            current[currentIndex] = '\0';
            printf("Literal    : %s\n", current);
        } else if (isalpha(input[i])) {
            // Keyword or Identifier
            currentIndex = 0;
            while (isalnum(input[i])) {
                current[currentIndex++] = input[i++];
            }
            current[currentIndex] = '\0';

            if (isKeyword(current)) {
                printf("Keyword    : %s\n", current);
            } else {
                printf("Identifier : %s\n", current);
            }
        } else if (input[i] == '"') {
            // String Literal (e.g., "Hello World\n")
            i++;  // Skip the opening double quote
            currentIndex = 0;
            while (input[i] != '"' && input[i] != '\0') {
                current[currentIndex++] = input[i++];
            }
            current[currentIndex] = '\0';
            printf("Literal    : \"%s\"\n", current);
            i++;  // Skip the closing double quote
        } else {
            // Invalid character (Error)
            printf("%c : Error\n", input[i]);
            i++;
        }
    }

    printf("Parsing : test.c : Done\n");
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Open    : test.c  : Success\n");

    // Open the input file for reading
    FILE *file = fopen("test.c", "r");
    if (!file) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    // Read the input from the file into the input string
    fread(input, sizeof(char), MAX_INPUT_SIZE, file);

    // Close the file
    fclose(file);

    // Call the Tokenizer function to analyze the input
    Tokenizer(input);

    return 0;
}

