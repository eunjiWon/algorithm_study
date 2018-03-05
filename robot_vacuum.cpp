#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int map[51][51];
int cnt = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; // 상 좌 하 우 -> 반시계 방향으로 돌아감.
int N, M;
void dfs(int x, int y, int d){
    // 0이라면 방문했다고 표시하자
    if(map[x][y] == 0){
        cnt++;
        map[x][y] = 2;
    }
    for(int i = d + 1; i < d + 5; i++){
        // 1. 주변에 방문할 칸이 있는 경우
        // 방항을 4방향으로 바꾸면서 방문할 수 있는 곳을 찾는다.
        int next_x = x + dx[i % 4];
        int next_y = y + dy[i % 4];
        // 방문할 수 있으면 방문 후 표시
        if(next_x >= 0 && next_y >= 0 && next_x < N && next_y < M){
            if(map[next_x][next_y] == 0){
                dfs(next_x, next_y, i % 4);
            }
        }
    }
    // 2. 방문할 칸이 없는 경우 -> 네 방향에 모두 0이 없는 경우 
    // 후진
    int back_x = x + dx[(d + 2) % 4]; 
    int back_y = y + dy[(d + 2) % 4];
    if(map[back_x][back_y] == 2){
        dfs(back_x, back_y, d % 4);
	}
	else 
		cout << cnt << endl;
		exit(0);
}
int main(){
    // n, m, x, y, d 값 입략
    int d, x, y;
    cin >> N >> M;
    cin >> x >> y >> d;
    // 0, 1, 2, 3, 을 상, 좌, 하, 우 에 매핑해서 입력값 d의 좌, 우를 체인지
    if(d == 3) d = 1;
    else if(d == 1) d = 3;
    // 배열 입력
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    // DFS();
    dfs(x, y, d);
    // print(result);
    cout << cnt << endl;
    return 0;
}

