#include <stdio.h>
#include <string.h>

#include "list.h"

Node *Next(Node *node)
{
	// 노드 포인터가 NULL이거나, 노드의 다음 노드가 NULL 이라면, NULL 을 반환합니다.
	if (!node || !node->next)
	{
		return NULL;
	}
	// 노드의 다음 노드를 반환합니다.
	return node->next;
}

Node *Prev(Node *node)
{
	// 노드 포인터가 NULL이거나, 노드의 이전 노드가 NULL 이라면, NULL 을 반환합니다.
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

void ListClear(LinkedList *list, bool freeData)
{
	// 리스트의 사이즈가 0이 될때까지 맨 앞의 노드를 삭제합니다.
	while (list->size)
	{
		// freeData 가 true일 경우, data의 동적 할당을 해제합니다.
		if (freeData)
		{
			free(ListGetNode(list, 0)->data);
		}
		ListDeleteNode(list, 0);
	}
}

void ListAddNode(LinkedList *list, int pos, void *data)
{
	if (!ListIndexCheck(list, pos, true))
	{
		perror("잘못된 위치");
		exit(1);
	}
	
	Node *cur = list->tail;
	if (pos < ListSize(list))
	{
		cur = ListGetNode(list, pos);
	}
	
	// 이전 노드를 참조합니다.
	Node *prev = cur->prev;
	
	// 새로운 노드를 생성하고, 데이터를 넣습니다.
	Node *node = calloc(1, sizeof(Node));
	node->data = data;
	node->prev = prev;
	node->next = cur;
	
	// 이전 노드, 다음 노드와 새로운 노드를 연결합니다.
	prev->next = node;
	cur->prev = node;
}

void ListDeleteNode(LinkedList *list, int pos)
{
	// 리스트가 비어있다면 프로그램을 종료합니다.
	if (ListIsEmpty(list))
	{
		perror("비어있는 리스트");
		exit(1);
	}
	
	// 잘못된 위치가 들어왔다면 프로그램을 종료합니다.
	if (ListIndexCheck(list, pos, false))
	{
		perror("잘못된 위치");
		exit(1);
	}
	
	// 삭제할 노드를 얻습니다.
	Node *cur = ListGetNode(list, pos);
	
	// 삭제할 노드의 연결을 끊습니다.
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;
	
	// 노드의 내용을 지웁니다.
	memset(cur, 0, sizeof(Node));
	// 노드의 메모리 할당을 해제합니다.
	free(cur);
}

Node *ListGetNode(LinkedList *list, int pos)
{
	// 리스트가 비어있다면 프로그램을 종료합니다.
	if (ListIsEmpty(list))
	{
		perror("비어있는 리스트");
		exit(1);
	}
	
	// 잘못된 위치가 들어왔다면 프로그램을 종료합니다.
	if (ListIndexCheck(list, pos, false))
	{
		perror("잘못된 위치");
		exit(1);
	}
	
	// 리스트를 순회하기 위한 방향을 설정합니다.
	int direction = 1;
	// 첫번째 탐색 위치를 head 더미노드로 설정합니다.
	int i = -1;
	// 리스트 순회를 위한 커서를 head 더미노드로 설정합니다.
	Node *cur = list->head;
	// 다음 노드를 반환하는 함수포인터를 Next로 설정합니다.
	Node *(*next)(Node *) = Next;
	
	// 찾아야 하는 위치가 size의 절반보다 뒤에 있다면
	// 탐색 횟수를 줄이기 위하여, 뒤에서부터 탐색합니다.
	if (list->size / 2 <= pos)
	{
		// 방향을 -1로 설정합니다.
		direction = -1;
		// 첫번째 탐색 위치를 tail 더미노드로 설정합니다.
		i = list->size;
		// 커서를 tail 더미노드로 설정합니다.
		cur = list->tail;
		// 다음 노드를 반환하는 함수포인터를 Prev로 설정합니다.
		next = Prev;
	}
	
	// 설정된 값에 따라, 인자로 들어온 위치까지 리스트를 순회합니다.
	for (; i != pos; i += direction)
	{
		cur = next(cur);
	}
	
	// 인자로 들어온 위치의 노드를 반환합니다.
	return cur;
}

int ListSize(LinkedList *list)
{
	// 리스트의 사이즈를 반환합니다.
	return list->size;
}

bool ListIsEmpty(LinkedList *list)
{
	// 리스트가 비어있는지를 반환합니다.
	return list->size == 0;
}

bool ListIndexCheck(LinkedList *list, int pos, bool includeEnd)
{
	// includeEnd 가 true라면, pos == size인 경우가 허용됩니다.
	if (includeEnd == true && pos == list->size)
	{
		return true;
	}
	// pos가 리스트 내부의 인덱스를 가리키는지 체크합니다.
	if (pos < 0 || list->size <= pos)
	{
		return false;
	}
	return true;
}

int ListFind(LinkedList *list, void *data, int size)
{
	// 리스트가 비어있다면, -1을 반환합니다.
	if (list->size == 0)
	{
		return -1;
	}
	
	Node *cur = list->head->next;
	for (int i = 0; i < list->size; i++)
	{
		// 커서의 동적할당 사이즈를 받아옵니다.
		int curSize = MALLOC_SIZE(cur->data);
		
		// 커서의 사이즈가 data의 사이즈보다 작다면
		// 최소한 커서에 data와 같은 정보가 들어있지는 않을 것입니다.
		if (curSize < size)
		{
			continue;
		}
		
		// size만큼의 메모리를 비교하였을 때, 값이 일치한다면, 해당 인덱스를 반환합니다.
		if (memcmp(cur->data, data, size) == 0)
		{
			return i;
		}
	}
	return -1;
}
