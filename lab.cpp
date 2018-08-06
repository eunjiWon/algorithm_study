#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int plusX[4] = {-1, 0, 1, 0};
int plusY[4] = {0, 1, 0, -1}; // 시계방향으로 
int n, m;
int map[8][8];
int copymap[8][8];
vector< pair<int, int> > v;

void DFS(int x, int y){ // 바이러스 전염시키는 DFS
    for(int i = 0; i < 4; i++){
        int newX = plusX[i] + x;
        int newY = plusY[i] + y;
        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
            if(copymap[newX][newY] == 0){
                copymap[newX][newY] = 2;
                DFS(newX, newY);
            }
        }   
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){// 벽이 아니라면 
                v.push_back(make_pair(i, j)); // 벽 세울 곳 뽑기 위해
            }
        }
    }

    int MAX = 0;
    for(int i = 0; i < v.size() - 2; i++){
        for(int j = i + 1; j < v.size() - 1; j++){
            for(int k = j + 1; k < v.size(); k++){
                  // 벽 세울 3개 좌표 선정
                pair<int, int> one = v[i];
                pair<int, int> two = v[j];
                pair<int, int> three = v[k];
            
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        copymap[i][j] = map[i][j]; 
                    }
                }
                //3개 기둥 세우기
                copymap[one.first][one.second] = 1;
                copymap[two.first][two.second] = 1;
                copymap[three.first][three.second] = 1;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(copymap[i][j] == 2)
                            DFS(i, j);
                    }
                }
                int safe_cnt = 0; 
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        if(copymap[i][j] == 0)
                            safe_cnt++;
                    }
                }
                MAX = max(MAX, safe_cnt);// 제일 많은 영역으로 저장해야하니까
            }
        }
    }


    cout << MAX << endl;
    return 0;
}
/*
1) DFS
2) https://www.acmicpc.net/problem/14502
3) C++ STL에서 좌표의 위치를 기록하기 위해서 pair 사용하면 좋다.
그리고 DFS로 완전탐색해서 모든 경우를 체크하는게 그리 무식한 방법은 아닌거 같다.. 
그리고 4방향 모두 탐색하게 코드 짤 때 시계방향으로 탐색하도록 짜는게 안 헷갈린다.(개인 취향...)
그리고 조합으로 n개를 뽑아야 할 때 n개의 for문으로 구현할 수 있다.
*/




















