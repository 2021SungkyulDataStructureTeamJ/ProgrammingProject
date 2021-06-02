#include "list.h"

typedef LinkedList Stack;

// 새로운 Stack을 생성합니다.
void StackInit(Stack *stack);

// Stack의 뒤에 데이터를 추가합니다.
void StackPush(Stack *stack, void *data, int size);

// Stack의 맨 앞의 데이터를 삭제합니다.
void StackPop(Stack *stack);

// Stack의 맨 앞 데이터를 반환합니다.
void *StackPeek(Stack *stack);

// Stack의 사이즈를 반환합니다.
int StackSize(Stack *stack);

// Stack이 비어있는지를 반환합니다.
bool StackIsEmpty(Stack *stack);

// Stack의 모든 원소를 제거합니다.
void StackClear(Stack *stack);