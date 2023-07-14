#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**note that we don't want to violate the consistency for the user's happiness***/

/* Initializing the stack setting top to 0 */
void CreateStack(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
}

/*  Pre: The stack is initialized and not full
    Post: The element e has been stored at the top
            and e doens't change 
*/
void Push(StackEntry e, Stack *ps){
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++ ;
}

/*
it has no meaning since lists won't ever get full,
compatiability and ADT issues
*/

int StackFull(Stack *ps){
    return 0;
}

/*  Pre: The stack is intiazlied and not empty
    Post: The last element entered is returned
            the stack is decreased
*/
void Pop(StackEntry *pe, Stack *ps){
    *pe = ps->top->entry;
    StackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}

/*  Pre: The stack is initialized
    Post: return 1 if it is empty, 0 otherwise
*/
int StackEmpty(Stack *ps){
    if (ps->top == NULL)
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
    *pe = ps->top->entry;
}

/*  Pre: The stack is initialzed
    Post: return number of elements exist
*/
int StackSize(Stack *ps){
    // every time the user calls it, it will traverse all the content again
    // int x = 0;
    // StackNode *pn = ps->top;

    // for (x = 0; pn; pn=pn->next)
    //     x++;

    // return x;

    // another method is to define a 'size' as a field in the struct stack size 
    // so simply you can return this value
    return ps->size;
} 

/*  Pre: The stack is initialized  
    Post: destroys all elements; stack looks initialized
    Notice: the same as CreateStack() but it differs conceptually
*/
void ClearStack(Stack *ps){
    StackNode *pn = ps->top; 

    while(pn){
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}

/*  Pre: the satck is initialized  */
void TraverseStack(Stack *ps, void(*pf)(StackEntry)){
    
    StackNode *pn = ps->top;
    while(pn){
        (*pf)(pn->entry);
        pn = pn->next;
    }
 
    // for(StackNode *pn=ps->top; pn; pn=pn->next)
    //     (*pf)(pn->entry);
}
