#include "list.h"

typedef LinkedList Queue;

// 새로운 Queue를 생성합니다.
void *QueueInit(Queue *queue);

// Queue의 뒤에 데이터를 추가합니다.
void QueuePush(Queue *queue, void *data, int size);

// Queue맨 앞의 데이터를 삭제합니다.
void QueuePop(Queue *queue);

// Queue의 맨 앞 데이터를 반환합니다.
void *QueuePeek(Queue *queue);

// Queue의 사이즈를 반환합니다.
int QueueSize(Queue *queue);

// Queue가 비어있는지를 반환합니다.
bool QueueIsEmpty(Queue *queue);

// Queue의 모든 원소를 제거합니다.
void QueueClear(Queue *queue);