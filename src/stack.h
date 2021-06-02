#include "list.h"

typedef LinkedList Stack;

// 새로운 Queue를 생성합니다.
void StackInit(Stack *stack);

// Queue의 뒤에 데이터를 추가합니다.
void StackPush(Stack *stack, void *data, int size);

// Queue맨 앞의 데이터를 삭제합니다.
void StackPop(Stack *stack);

// Queue의 맨 앞 데이터를 반환합니다.
void *StackPeek(Stack *stack);

// Queue의 사이즈를 반환합니다.
int StackSize(Stack *stack);

// Queue가 비어있는지를 반환합니다.
bool StackIsEmpty(Stack *stack);

// Queue의 모든 원소를 제거합니다.
void StackClear(Stack *stack);