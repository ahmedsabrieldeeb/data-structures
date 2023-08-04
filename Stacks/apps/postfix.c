#include <stdio.h>
#include <math.h>
#include "stack.h"

void infixToPostfix(char infix[], char postfix[]);
double EvaluatePostfix(char expr[]);
double Oper(char c, double op1, double op2);
int Isdigit(char c);
int Precedent(char op1, char op2);

int main(){
    
    // // Try infix to postfix
    // char infix[] = "1+2+6*5";
    // char postfix[80];
    // printf("infix is:   %s\n", infix);
    // printf("true output is: %d\n", 1+2+6*5);
    // infixToPostfix(infix, postfix);
    // printf("postfix is: %s\n", postfix);


    // Try evaluating postfix
    char postfix[] = "12+65*+";
    double res;
    printf("postfix is: %s\n", postfix);
    res = EvaluatePostfix(postfix);
    printf("result of postfix is: %f\n", res);

    return 0;
}

/*******************from INFIX to POSTFIX*******************/
/*
Pre:
    - Assume the operand is only one digit and to be positive
    - no spaces in the infix
    - no unary operators
    - no invalid expressions
Post:
    - Having a postfix expression
*/
// void infixToPostfix(char infix[], char postfix[]){
//     int i, j;
//     char c;
//     char op;
//     Stack s;
//     CreateStack(&s);
//     for (i=0, j=0; (c=infix[i]) != '\0'; i++){
//         if (Isdigit(c))
//             postfix[j++]=c;
//         else{
//             if (!StackEmpty(&s)){
//                 StackTop(&op, &s);
//                 while (!StackEmpty(&s) && Precedent(op, c)){
//                     Pop(&op, &s);
//                     postfix[j++]=op;
//                     if (!StackEmpty(&s))
//                         StackTop(&op, &s);
//                 }
//             }
//             Push(c, &s);
//             }
//     }
//     while (!StackEmpty(&s)){
//         Pop(&op, &s);
//         postfix[j++]=op;
//     }
//     postfix[j] = '\0';
//     return;
// }


/*
Pre:
    - Assume the operand is only one digit and to be positive
    - no spaces in the infix
    - no unary operators
    - no invalid expressions
Post:
    - Returning the value of expression
*/
double EvaluatePostfix(char expr[]){
    double val, op1, op2;
    char c;
    Stack s;
    CreateStack(&s);

    for (int i=0; (c=expr[i]) != '\0'; i++){
        if (Isdigit(c))
            Push((double)(c-'0'), &s);
        
        else{
            Pop(&op2, &s);
            Pop(&op1, &s);
            val = Oper(c, op1, op2);
            Push(val, &s);
        }
    }

    Pop(&val, &s);
    return val; 
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
    if (op1 == '$') 
        return 1;

    if ((op1 == '*' || (op1 == '/')))
        return (op2 != '$');

    if ((op1 == '+' || op2 == '-'))
        return ((op2 != '$') && (op2 != '*') && (op2 != '/'));
    
    return 0;
}


double Oper(char c, double op1, double op2){
    if      (c == '$') return (pow(op1, op2));
    else if (c == '*') return (op1*op2);
    else if (c == '/') return (op1/op2);
    else if (c == '+') return (op1+op2);
    else if (c == '-') return (op1-op2);

}