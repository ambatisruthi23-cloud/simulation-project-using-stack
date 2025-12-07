#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define URL_LEN 100

typedef struct {
    char items[MAX][URL_LEN];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char *url) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(s->items[++s->top], url);
}

void pop(Stack *s, char *dest) {
    if (isEmpty(s)) {
        dest[0] = '\0';
        return;
    }
    strcpy(dest, s->items[s->top--]);
}

int main() {
    Stack backStack, forwardStack;
    init(&backStack);
    init(&forwardStack);

    char current[URL_LEN] = "home.com";
    char temp[URL_LEN];

    printf("Starting at: %s\n", current);

    // Visit new pages
    printf("\nVisiting pages...\n");
    push(&backStack, current);
    strcpy(current, "news.com");

    push(&backStack, current);
    strcpy(current, "sports.com");

    printf("Current page: %s\n", current);

    // BACK
    printf("\nPress BACK\n");
    push(&forwardStack, current);
    pop(&backStack, current);
    printf("Current page: %s\n", current);

    // BACK again
    printf("\nPress BACK\n");
    push(&forwardStack, current);
    pop(&backStack, current);
    printf("Current page: %s\n", current);

    // FORWARD
    printf("\nPress FORWARD\n");
    push(&backStack, current);
    pop(&forwardStack, current);
    printf("Current page: %s\n", current);

    return 0;
}
