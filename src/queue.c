#include "queue.h"

Queue *QueueNew()
{
	return ListNew();
}

void Enqueue(Queue *queue, void *data)
{
	ListAddNode(queue, ListSize(queue), data);
}

void Dequeue(Queue *queue)
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
