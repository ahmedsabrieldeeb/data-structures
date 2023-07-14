#ifndef STACK_H
#define STACK_H

typedef int StackEntry;

typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;
}StackNode;

/*
this is more consistent and not violeting the other procedues of DS, than to say:
typedef StackNode *Stack;
*/
typedef struct stack{
    StackNode *top;
    int size;
}Stack;

void    CreateStack        (Stack *);
void    Push               (StackEntry, Stack *);
int     StackFull          (Stack *);
void    Pop                (StackEntry *, Stack *);
int     StackEmpty         (Stack *);
void    StackTop           (StackEntry *, Stack *);
int     StackSize          (Stack *);
void    TraverseStack      (Stack *, void(*)(StackEntry));
void    ClearStack         (Stack *ps);
#endif /* STACK_H */
