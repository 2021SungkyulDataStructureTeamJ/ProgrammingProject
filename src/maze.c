#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void InitMaze(Maze *m, int w, int h)
{
	int i = 0;
	m->width = w;
	m->height = h;
	m->map = calloc(h, sizeof(int *));
	
	for (int i = 0; i < h; i++)
	{
		m->map[i] = calloc(w, sizeof(int));
	}
}

void ResetMaze(Maze *m)
{
	for (int i = 0; i < m->height; i++)
	{
		free(m->map[i]);
	}
	free(m->map);
	
	m->map = NULL;
	m->width = 0;
	m->height = 0;
}

void LoadMaze(Maze *m, char *fname)
{
	FILE *file = fopen(fname, "rt");
	if (fscanf(file, "%d %d", &m->width, &m->height) <= 0)
	{
		perror("파일 읽기 에러");
		exit(1);
	}
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
			
			m->map[y][x] = cur;
		}
	}
}

void PrintMaze(Maze *m)
{
	printf("전체 미로의 크기 = %d X %d\n", m->width, m->height);
	
}

void SearchExit(Maze *m)
{

}

void ScreenClear()
{

}
