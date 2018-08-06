#include <iostream>
using namespace std;
int n, m;
int r, c, d;
int cnt = 0;
int map[51][51] = {0};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; // 반시계 방향
void dfs(int r, int c, int d){
    if(r <= n && r >= 0 && c <= m && c >= 0){
        if(map[r][c] == 0){
            map[r][c] = 2; // 현재 위치를 청소한다.
            cnt++;
            //cout << cnt << endl;
        }  
        for(int i = d + 1; i < d + 1 + 4; i++){
            if(map[r + dx[i % 4]][c + dy[i % 4]] == 0)
                dfs(r + dx[i % 4], c + dy[i % 4], i % 4);
        }
        if(map[r + dx[(d + 2) % 4]][c + dy[(d + 2) % 4]] == 2)
            dfs(r + dx[(d + 2) % 4], c + dy[(d + 2) % 4] , d % 4);
        else{
            cout << cnt << endl; 
            exit(0);
        } 
    }//else exit(0);
}

int main(){
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    if(d == 1) d = 3;
    else if(d == 3) d = 1;
    else ; 
    dfs(r, c, d);
    cout << cnt << endl;
    return 0;
}