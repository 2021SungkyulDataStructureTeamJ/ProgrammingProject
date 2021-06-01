#include <stdio.h>

#include "list.h"

Node *Next(Node *node)
{
	// 노드 포인터가 NULL이거나, 노드의 다음 노드가 NULL이라면, NULL을 반환합니다.
	if (!node || !node->next)
	{
		return NULL;
	}
	// 노드의 다음 노드를 반환합니다.
	return node->next;
}

Node *Prev(Node *node)
{
	// 노드 포인터가 NULL이거나, 노드의 이전 노드가 NULL이라면, NULL을 반환합니다.
	if (!node || !node->prev)
	{
		return NULL;
	}
	// 노드의 이전 노드를 반환합니다.
	return node->prev;
}

LinkedList *ListNew()
{
	// 새로운 리스트를 할당합니다.
	LinkedList *list = calloc(1, sizeof(LinkedList));
	
	// 노드의 head와 tail에 내용이 없는 더미노드를 할당합니다.
	list->head = calloc(1, sizeof(Node));
	list->tail = calloc(1, sizeof(Node));
	// 사이즈를 0으로 설정합니다.
	// 더미노드는 사이즈에 포함되지 않습니다.
	list->size = 0;
	
	// head 노드를 초기화합니다.
	list->head->data = NULL;
	list->head->next = list->tail;
	list->head->prev = NULL;
	
	// tail 노드를 초기화합니다.
	list->tail->data = NULL;
	list->tail->next = NULL;
	list->tail->prev = list->head;
	
	// 리스트를 반환합니다.
	return list;
}

void ListClear(LinkedList *list)
{
	// 리스트의 사이즈가 0이 될때까지 맨 앞의 노드를 삭제합니다.
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
	// pos가 0보다 작거나, size보다 크다면, 잘못된 위치를 받은 것이므로
	// 프로그램을 종료합니다.
	if (pos < 0 || list->size < pos)
	{
		perror("잘못된 위치");
		exit(1);
	}
	
	// 리스트를 순회하기 위한 방향을 설정합니다.
	int direction = 1;
	// 위치를 알려주는 변수입니다.
	int i = -1;
	Node *cur = list->head;
	Node *(*iter)(Node*) = Next;
	
	if (list->size / 2 <= pos)
	{
		direction = -1;
		i = list->size;
		cur = list->tail;
		iter = Prev;
	}
	
	for (; i != pos; i += direction)
	{
		cur = iter(cur);
	}
}

int ListGetSize(LinkedList *list)
{
	return 0;
}
