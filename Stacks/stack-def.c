#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* Initializing the stack setting top to 0 */
void CreateStack(Stack *ps){
    ps->top = 0;
}

/*  Pre: The stack is initialized and not full
    Post: The element e has been stored at the top
            and e doens't change 
*/
void Push(StackEntry e, Stack *ps){
    ps->entry[ps->top] = e;
    ps->top++;

    // ps->entry[ps->top++] = e;
}

/*  Pre: the stack is initiazlied properly 
    Post: return 1 if it is full, 0 otherwise
*/
int StackFull(Stack *ps){
    if (ps->top == MAXSTACK)
        return 1;
    else
        return 0;

    // return ps->top >= MAXSTACK;
}

/*  Pre: The stack is intiazlied and not empty
    Post: The last element entered is returned
            the stack is decreased
*/
void Pop(StackEntry *pe, Stack *ps){
    ps->top--;
    *pe = ps->entry[ps->top];

    // *pe = ps->entry[--ps->top];
}

/*  Pre: The stack is initialized
    Post: return 1 if it is empty, 0 otherwise
*/
int StackEmpty(Stack *ps){
    if (ps->top == 0)
        return 1;
    else
        return 0;

    // return !ps->top;
}

/*  Pre: The stack is intiazlied and not empty
    Post: The last element entered is returned
            the stack remains the same
*/
void StackTop(StackEntry *pe, Stack *ps){
    *pe = ps->entry[ps->top-1];
}

/*  Pre: The stack is initialzed
    Post: return number of elements exist
*/
int StackSize(Stack *ps){
    return ps->top;     
}

/*  Pre: The stack is initialized  
    Post: destroys all elements; stack looks initialized
    Notice: the same as CreateStack() but it differs conceptually
*/
void ClearStack(Stack *ps){
    ps->top = 0
}
