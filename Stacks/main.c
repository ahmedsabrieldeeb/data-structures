#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void main(){
    StackEntry e;
    Stack s;
    int x;

    CreateStack(&s);
    
    if (!StackFull(&s))
        Push(e, &s);
    
    if (!StackEmpty(&s))
        Pop(&e, &s);
    
    if (!StackEmpty(&s))
        StackTop(&e, &s);
    
    x = StackSize(&s); /* could be s->top but it violets the concept of Encapsulation
                        since you as a user don't know details of the stack just you have the mechanisms*/

    ClearStack(&s);

    return;
}