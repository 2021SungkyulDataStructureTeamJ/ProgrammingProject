#include <stdio.h>

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
	size_t size;
} LinkedList;

typedef struct
{
	int x;
	int y;
} Location2D;

typedef struct
{
	int width;
	int height;
	int **map;
	
} MazeMap;

int main()
{
	
}