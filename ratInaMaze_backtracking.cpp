/*
	If destination is reached
		print the solution matrix
	Else
		Mark current cell in solution matrix as 1
		Move forward in horizontal direction and recursively check if this move leads to a solution.
		If the move chosen in the above step doesn't lead to a solution then move down and check if this move lead to a solution.
		If none of the above solutions work then unmark this cell as 0 (BACKTRACK) and return false

*/
#include <iostream>
using namespace std;
#define N 4
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);
void printSolution(int sol[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
/* A utility function to check if x, y is valid index for N * N maze */
bool isSafe(int maze[N][N], int x, int y){
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}
bool solveMaze(int maze[N][N]){ // 이거랑 솔브메이지유틸이랑 합치면 백트레킹 안되나?
    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if(solveMazeUtil(maze, 0, 0, sol) == false){
        cout << "Solution doesn't exist";
        return false;
    }
    printSolution(sol);
    return true;
}
/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]){
    // if (x, y is goal) return true
    if(x == N - 1 && y == N - 1){
        sol[x][y] = 1;
        return true;
    }
    // Check if maze[x][y] is valid, 길인데
    if(isSafe(maze, x, y) == true){
        // mark x, y as part of solution path
        sol[x][y] = 1;
        // Move forward in x dirction
        if(solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
        /* If moving in x direction doesn't give solution then
        Move down in y direction, 여기까지 왔다는 건 위에서 실패해서 리턴 안했다는 말 그니까 기회가 아래 방향으로 왔다.*/
        if(solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;
    
        sol[x][y] = 0; // 내가 옆으로나 아래로 갈 수 없을 때 그건 길이 아니니까 다시 0으로 백트레킹 한다.
        // 다 아닐 경우에만 다시 0으로 돌린다.
        return false;
    }
    // 가려고 하는 곳이 길이 아닌 경우(1이 아닌 경우)
    return false; 
} 
int main(){
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solveMaze(maze);
    return 0;
}
