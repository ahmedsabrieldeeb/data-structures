#include <stdio.h>
#include "stack.h"

void infixToPostfix(char infix[], char postfix[]);
int Isdigit(char c);
int Precedent(char op1, char op2);

int main(){

    char infix[] = "1+2*3$4/5+6";
    char postfix[80];
    infixToPostfix(infix, postfix);
    printf("infix is: %s\n", infix);
    printf("postfix is: %s\n", postfix);

    return 0;
}

/*******************from INFIX to POSTFIX*******************/
/*
Pre:
    - Assume the operand is only digit
    - no spaces in the infix
Post:
    - Store the output in a double data type.
*/
void infixToPostfix(char infix[], char postfix[]){
    int i, j;
    char op, c;
    Stack s;
    CreateStack(&s);

    for (i=0, j=0; (c=infix[i]) != '\0'; i++){
        if (Isdigit(c))
            postfix[j++]=c;
        else{
            if (!StackEmpty(&s)){
                StackTop(&op, &s);
                while (!StackEmpty(&s) && Precedent(op, c)){
                    Pop(&op, &s);
                    postfix[j++]=op;
                    if (!StackEmpty(&s))
                        StackTop(&op, &s);
                }
            }
            Push(c, &s);
            }
    }
    while (!StackEmpty(&s)){
        Pop(&op, &s);
        postfix[j++]=op;
    }
    postfix[j] = '\0';
    return;
}

/*
Pre:
    - accepts only one character to be tested

Post:
    - 1 if the character is digit, 0 otherwise
*/
int Isdigit(char c){
    return (c >= '0' && c <= '9');
}


/*
Pre:
    - opearators are only +, -, *, /, $ (power)

Post:
    - 1 if first operator is precedent, 0 otherwise  
*/
int Precedent(char op1, char op2){
    if (op1 == '$'); 
        return 1;

    if ((op1 == '*' || (op1 == '/')))
        return (op2 != '$');
        
    if ((op1 == '+' || op2 == '-'))
        return ((op2 != '$') && (op2 != '*') && (op2 != '/'));
    
    return 0;
}