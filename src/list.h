#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

// boolean 타입을 정의합니다.
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif
#ifndef bool
#define bool int
#endif

// linked list node
typedef struct node
{
	void *data;
	struct node *prev;
	struct node *next;
} Node;

// 현재 노드의 다음 노드를 반환합니다.
Node *Next(Node *node);

// 현재 노드의 이전 노드를 반환합니다.
Node *Prev(Node *node);

// linked list
typedef struct
{
	Node *head;
	Node *tail;
	int size;
} LinkedList;

// 초기화된 새로운 리스트를 반환합니다.
LinkedList *ListNew();

// 리스트의 모든 원소를 제거합니다.
void ListClear(LinkedList *list, bool freeData);

// 해당 위치에 새로운 노드를 추가합니다.
void ListAddNode(LinkedList *list, int pos, void *data);

// 해당 위치의 노드를 제거합니다.
void ListDeleteNode(LinkedList *list, int pos);

// 해당 위치의 노드를 반환합니다.
Node *ListGetNode(LinkedList *list, int pos);

// 리스트의 길이를 반환합니다.
int ListGetSize(LinkedList *list);

// 리스트가 비어있는지를 반환합니다.
bool ListIsEmpty(LinkedList *list);

// 해당 위치가 유효한 위치인지를 체크합니다.
// includeEnd 가 true 일시, tail 더미노드의 인덱스를 유효한 것으로 취급합니다.
bool ListIndexCheck(LinkedList *list, int pos, bool includeEnd);

#endif
