/* 외판원 문제는 np 문제로 유명한 문제이다.
여러 도시들이 주어져 있고, 모든 도시들에 대한 가중치가 주어졌을 때, 
단일 시작점부터 시작해서 모든 도시를 단 한 번씩만 방문하여 다시 
시작점으로 돌아오는데 드는 최단 거리를 구하는 문제이다.
단순히, 완전 탐색으로 진행을 하면 무려 O(N!) 시간복잡도가 나온다.
첫째 줄에 도시의 수 N이 주어진다. (2<=N<=10) 다음 N개의 줄에는 비용 행렬이 주어진다. 
각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다. 
W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.
항상 순회할 수 있는 경우만 입력으로 주어진다
*/ 
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n; 
int dist[15][15]; // 가중치를 저장하기 위한 배열
int TSP(vector<int> path, vector<bool> visited, int len){
    // 모든 도시를 다 방문 했을 경우
    if(path.size() == n)
        return len + dist[path.back()][0];
    int ret = 987654321;

    for(int next = 0; next < n; next++){
        // 방문 했다면 패스
        if(visited[next] == true)
            continue;
        int cur = path.back();
        path.push_back(next);
        visited[next] = true;
        ret = min(ret, TSP(path, visited, len + dist[cur][next]));
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }
    vector<int> path(1, 0); //경로를 저장할 벡터, 시작 도시 0번 도시 선택
    vector<bool> visited(n, false);
    visited[0] = true;
    double ret = TSP(path, visited, 0);
    cout << ret << endl; 
}
// 이 해결 방법은 완전 탐색이다. 하지만 완전히 코드를 이해하지
// 못했다.