#include "stack.h"

void StackInit(Stack *stack)
{
	ListInit(stack);
}

void StackPush(Stack *stack, void *data, int size)
{
	ListAddNode(stack, ListSize(stack), data, size);
}

void StackPop(Stack *stack)
{
	ListDeleteNode(stack, stack->size - 1);
}

void *StackPeek(Stack *stack)
{
	return ListGetNode(stack, ListSize(stack) - 1);
}

int StackSize(Stack *stack)
{
	return ListSize(stack);
}

bool StackIsEmpty(Stack *stack)
{
	return ListIsEmpty(stack);
}

void StackClear(Stack *stack)
{
	ListClear(stack);
}