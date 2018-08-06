#include <iostream>
using namespace std;
int maze[4][4] = {{1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 0, 0},
                {1, 1, 1, 1}};
int dx[] = {1, 0}; // 오른쪽, 아래쪽
int dy[] = {0, 1};

void dfs(int x, int y){
    if(x >= 0 && x < 4 && y >= 0 && y < 4){
        maze[x][y] = 2;
        for(int i = 0; i < 2; i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(maze[nextX][nextY] == 1)
                dfs(nextX, nextY);
        }
    }
    return;
}
int main(){
    dfs(0, 0);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << maze[i][j] <<  " ";
        }
        cout << endl;
    } 

    return 0;
}