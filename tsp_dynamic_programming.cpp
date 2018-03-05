#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX_VALUE 987654321.0

using namespace std;

int n;
int cache[17][65536], dist[17][17];
int TSP(int cur, int visited){
    if(visited == (1 << n) - 1)  // 다 방문했으면 리턴한다. 
        return dist[cur][0];
    int &ret = cache[cur][visited];
    if(ret != 0) return ret;
    ret = MAX_VALUE;
    for(int next = 0; next <= n; next++){
        if(visited & (1 << next)) continue; // visited 에 표시 돼 있으면 방문한거니까 통과
        if(dist[cur][next] == 0) continue; // 자기 자신에서 자기 자신으로 가는거면 통과
        ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);    
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
    cout << TSP(0, 1);
}