#include "stack.h"

void StackInit(Stack *stack)
{
	ListInit(stack);
}

void StackPush(Stack *stack, void *data, int size)
{
	ListAddNode(stack, 0, data, size);
}

void StackPop(Stack *stack)
{
	ListDeleteNode(stack, 0);
}

void *StackPeek(Stack *stack)
{
	return ListGetNode(stack, 0);
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