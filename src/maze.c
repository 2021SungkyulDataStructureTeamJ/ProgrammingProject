#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "maze.h"

void InitMaze(Maze *m, int w, int h)
{
	// maze의 높이, 너비를 설정합니다.
	m->width = w;
	m->height = h;
	
	// maze의 맵을 동적할당 합니다.
	m->map = calloc(h, sizeof(int *));
	
	for (int i = 0; i < h; i++)
	{
		m->map[i] = calloc(w, sizeof(int));
	}
}

void ResetMaze(Maze *m)
{
	// 2차원 동적배열을 해제합니다.
	for (int i = 0; i < m->height; i++)
	{
		free(m->map[i]);
	}
	free(m->map);
	
	// maze의 원소를 초기화합니다.
	m->map = NULL;
	m->width = 0;
	m->height = 0;
}

void LoadMaze(Maze *m, char *fname)
{
	// fname으로 넘어온 텍스트파일을 엽니다.
	FILE *file = fopen(fname, "rt");
	
	// 파일이 열리지 않는다면 프로그램을 종료합니다.
	if (file == NULL)
	{
		perror("파일 에러");
		exit(1);
	}
	
	// 첫 줄의 길이와 너비 정보를 읽습니다.
	if (fscanf(file, "%d %d", &m->width, &m->height) <= 0)
	{
		perror("파일 읽기 에러");
		exit(1);
	}
	
	// 다음 데이터를 읽으면서, maze의 map에 저장합니다.
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			int cur = 0;
			
			if (fscanf(file, "%d", &cur) <= 0)
			{
				perror("파일 읽기 에러");
				exit(1);
			}
			
			// 현 좌표가 시작 좌표라면, enter 변수에 좌표를 설정합니다.
			if (cur == 5)
			{
				m->enter.x = x;
				m->enter.y = y;
			}
			// 현 좌표가 끝 좌표라면, exit 변수에 좌표를 설정합니다.
			if (cur == 9)
			{
				m->exit.x = x;
				m->exit.y = y;
			}
			
			m->map[y][x] = cur;
		}
	}
}

void PrintMaze(Maze *m)
{
	ClearScreen();
	printf("전체 미로의 크기 = %d X %d\n", m->width, m->height);
	
	for (int y = 0; y < m->height; y++)
	{
		for (int x = 0; x < m->width; x++)
		{
			// map에 저장된 숫자에 따라 기호를 출력합니다.
			switch (m->map[y][x])
			{
				case 0:
					printf("■");
					break;
				case 1:
					// 가변폭 기준으로, 각각의 기호들은 2칸의 공간을 차지합니다.
					// 따라서 스페이스를 두 칸으로 설정합니다.
					printf("  ");
					break;
				case 2:
					// 탐색된 구역을 의미합니다.
					printf("□");
					break;
				case 5:
					printf("○");
					break;
				case 9:
					printf("◎");
				default:
					break;
			}
		}
		printf("\n");
	}
}

void SearchExit(Maze *m)
{
	// DFS를 위한 방향을 가리키는 변수입니다.
	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1, 0, -1};
	
	printf("입구○ → 출구◎ 경로찾기 시작.[엔터]");
	getchar();
	
	// stack을 초기화하고, 시작 좌표를 넣습니다.
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, &(m->enter), sizeof(Location2D));
	
	// DFS 알고리즘을 이용해 출구를 탐색합니다.
	while (StackIsEmpty(&stack) == false)
	{
		Location2D cur;
		NodeGetData(StackPeek(&stack), &cur);
		StackPop(&stack);
		
		if (m->map[cur.y][cur.x] == 0 || m->map[cur.y][cur.x] == 2)
		{
			continue;
		}
		
		if (cur.x == m->exit.x && cur.y == m->exit.y)
		{
			StackClear(&stack);
			return;
		}
		
		m->map[cur.y][cur.x] = 2;
		
		for (int d = 0; d < 4; d++)
		{
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];
			
			if (nx < 0 || m->width <= nx)
			{
				continue;
			}
			if (ny < 0 || m->height <= ny)
			{
				continue;
			}
			
			StackPush(&stack, &((Location2D) {nx, ny}), sizeof(Location2D));
		}
	}
}

void ClearScreen()
{
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	system("clear");
	#endif
	
	#if defined(_WIN32) || defined(_WIN64)
	system("cls");
	#endif
}