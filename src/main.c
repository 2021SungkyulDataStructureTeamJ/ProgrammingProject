#include "maze.h"

int main()
{
	Maze maze;
	InitMaze(&maze, 20, 10);
	LoadMaze(&maze, "maze.txt");
	PrintMaze(&maze);
	SearchExit(&maze);
	PrintMaze(&maze);
	ResetMaze(&maze);
	return 0;
}