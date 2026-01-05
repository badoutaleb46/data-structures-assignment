#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;


int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}


void push(char c) {
    stack[++top] = c;
}


char pop() {
    return stack[top--];
}

int main() {
    char infix[50], postfix[50];
    int i, k = 0;

    
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {

        
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();  
        }

        
        else {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    
    printf("%s", postfix);

    return 0;
}
