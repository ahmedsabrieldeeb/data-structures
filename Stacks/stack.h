#ifndef STACK_H
#define STACK_H

typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];

}Stack;

void CreateStack(Stack *ps);
void Push(StackEntry e, Stack *ps);
int StackFull(Stack *ps);
void Pop(StackEntry *pe, Stack *ps);
int StackEmpty(Stack *ps);
void StackTop(StackEntry *pe, Stack *ps);
int StackSize(Stack *ps);

#endif /* STACK_H */
