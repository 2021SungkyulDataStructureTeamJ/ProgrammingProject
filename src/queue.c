#include "queue.h"

void *QueueInit(Queue *queue)
{
	ListInit(queue);
}

void QueuePush(Queue *queue, void *data, int size)
{
	ListAddNode(queue, ListSize(queue), data, size);
}

void QueuePop(Queue *queue)
{
	ListDeleteNode(queue, 0);
}

void *QueuePeek(Queue *queue)
{
	return ListGetNode(queue, 0);
}

int QueueSize(Queue *queue)
{
	return ListSize(queue);
}

bool QueueIsEmpty(Queue *queue)
{
	return ListIsEmpty(queue);
}

void QueueClear(Queue *queue)
{
	ListClear(queue);
}