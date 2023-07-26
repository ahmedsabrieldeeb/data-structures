#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void Display(StackEntry e){
    printf("e is: %d\n", e);
}

void main(){
    
    int n = 0;
    Stack s;
    StackEntry e;

    CreateStack(&s);

    printf("Stack is initialized Successfully\nhow many numbers you want to store in the stack: ");
    scanf("%d", &n);
    
    printf("Enter the numbers in row:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &e);
        Push(e, &s);
    }

    printf("Size is: %d\n", StackSize(&s));
    // printf("top is: %d\n", s.top);
    printf("Let's Traverse the stack to see the content\n");

    TraverseStack(&s, &Display);

    printf("I will clear the stack, Sorry\n");
    ClearStack(&s);
    printf("Now, Size is: %d\n", StackSize(&s));




}

/*  StackTop() in User level using other mechanisms
                if it isn't defined in implementation level 
*/

// void StackTop(StackEntry *pe, Stack *ps){
//     Pop(pe, ps);
//     Push(*pe, ps);
// }
