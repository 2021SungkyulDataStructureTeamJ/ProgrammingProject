// 미로찾기를 위한 좌표 구조체입니다.
typedef struct
{
	int x;
	int y;
} Location2D;

// 미로찾기를 위한 맵 구조체입니다.
typedef struct
{
	int width;
	int height;
	int **map;
	Location2D enter;
	Location2D exit;
} Maze;

// 미로 초기화(동적할당 포함)
void InitMaze(Maze *m, int w, int h);

// 미로의 동적 해제
void ResetMaze(Maze *m);

// 미로파일 읽기
void LoadMaze(Maze *m, char *fname);

// 미로 맵 화면출력
void PrintMaze(Maze *m);

// 미로 탐색(깊이우선탐색)
void SearchExit(Maze *m);

// 화면을 지우는 함수입니다.
void ClearScreen();