#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

// linked list node
typedef struct node
{
	void *data;
	struct node *prev;
	struct node *next;
} Node;

// linked list
typedef struct
{
	Node *head;
	Node *tail;
	int size;
} LinkedList;

// 초기화된 새로운 리스트를 반환합니다.
LinkedList *ListNew();

// 리스트를 초기화합니다.
void ListClear(LinkedList *list);

// 해당 위치에 새로운 노드를 추가합니다.
void ListAddNode(LinkedList *list, int pos, void *data);

// 해당 위치의 노드를 제거합니다.
void ListDeleteNode(LinkedList *list, int pos);

// 해당 위치의 노드를 반환합니다.
Node *ListGetNode(LinkedList *list, int pos);

// 리스트의 길이를 반환합니다.
int ListGetSize(LinkedList *list);

#endif
