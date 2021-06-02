#include "maze.h"

int main()
{
	Maze maze;
	LoadMaze(&maze, "maze.txt");
	PrintMaze(&maze);
	SearchExit(&maze);
	PrintMaze(&maze);
	return 0;
}