#include <errno.h>
#include <stdio.h>

#include "list.h"

LinkedList *ListNew()
{
	LinkedList *list = calloc(1, sizeof(LinkedList));
	list->head = calloc(1, sizeof(Node));
	list->tail = calloc(1, sizeof(Node));
	list->size = 0;
	
	list->head->data = NULL;
	list->head->next = list->tail;
	list->head->prev = NULL;
	
	list->tail->data = NULL;
	list->tail->next = NULL;
	list->tail->prev = list->head;
	
	return list;
}

void ListClear(LinkedList *list)
{
	while (list->size)
	{
		ListDeleteNode(list, 0);
	}
}

void ListAddNode(LinkedList *list, int pos, void *data)
{

}

void ListDeleteNode(LinkedList *list, int pos)
{

}

Node *ListGetNode(LinkedList *list, int pos)
{
	if (pos < 0 || list->size < pos)
	{
		perror("잘못된 위치");
		exit(1);
	}
	return NULL;
}

int ListGetSize(LinkedList *list)
{
	return 0;
}
