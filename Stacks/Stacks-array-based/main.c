#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void Display(StackEntry e){
    printf("e is: %d\n", e);
}

void main(){

    StackEntry e = 10;
    Stack s;
    int x;

    CreateStack(&s);
    
    if (!StackFull(&s))
        Push(e, &s);

    x = StackSize(&s);
    printf("%d\n", x);
    TraverseStack(&s, &Display);
    
    if (!StackEmpty(&s))
        Pop(&e, &s);
    
    if (!StackEmpty(&s))
        StackTop(&e, &s);
    
    x = StackSize(&s); /* could be s->top but it violets the concept of Encapsulation
                        since you as a user don't know details of the stack just you have the mechanisms*/
    printf("%d\n", x);

    ClearStack(&s);

    TraverseStack(&s, &Display);

    return;
}

/*  StackTop() in User level using other mechanisms
                if it isn't defined in implementation level 
*/

// void StackTop(StackEntry *pe, Stack *ps){
//     Pop(pe, ps);
//     Push(*pe, ps);
// }
