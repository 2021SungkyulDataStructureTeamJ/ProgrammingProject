#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <malloc.h>

// malloc_usable_size와 _msize는 동적할당된 메모리의 크기를 알아내는 함수입니다.
#ifdef _WIN32
#define MALLOC_SIZE _msize
#elif defined(__linux__)
#define MALLOC_SIZE malloc_usable_size
#endif

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
	int size;
	struct node *prev;
	struct node *next;
} Node;

// 현재 노드의 다음 노드를 반환합니다.
Node *NodeNext(Node *node);

// 현재 노드의 이전 노드를 반환합니다.
Node *NodePrev(Node *node);

// 노드의 데이터를 얻습니다.
void NodeGetData(Node *node, void *data);

// 노드의 데이터를 설정합니다.
void NodeSetData(Node *node, void *data, int size);

// linked list
typedef struct
{
	Node *head;
	Node *tail;
	int size;
} LinkedList;

// 초기화된 새로운 리스트를 반환합니다.
void ListInit(LinkedList *list);

// 리스트의 모든 원소를 제거합니다.
void ListClear(LinkedList *list);

// 해당 위치에 새로운 노드를 추가합니다.
void ListAddNode(LinkedList *list, int pos, void *data, int size);

// 해당 위치의 노드를 제거합니다.
void ListDeleteNode(LinkedList *list, int pos);

// 해당 위치의 노드를 반환합니다.
Node *ListGetNode(LinkedList *list, int pos);

// 리스트의 길이를 반환합니다.
int ListSize(LinkedList *list);

// 리스트가 비어있는지를 반환합니다.
bool ListIsEmpty(LinkedList *list);

// 해당 위치가 유효한 위치인지를 체크합니다.
// includeEnd가 true일시, tail 더미노드의 인덱스를 유효한 것으로 취급합니다.
bool ListIndexCheck(LinkedList *list, int pos, bool includeEnd);

// 데이터와 메모리 사이즈를 넣으면, 리스트에서 해당 데이터가 있는 노드의 위치를 반환합니다.
// 데이터가 없다면 -1을 반환합니다.
int ListFind(LinkedList *list, void *data, int size);

#endif
