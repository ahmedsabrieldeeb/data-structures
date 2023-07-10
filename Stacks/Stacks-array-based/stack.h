#ifndef STACK_H
#define STACK_H

#define MAXSTACK 100

typedef int StackEntry;

typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];

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
