// 오늘부터 N+1 일 째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
// 각각의 상담은 상담을 완료하는데 걸리는 기간 T와 상담을 했을 때 받을 수 있는 금액 P로 아루어져있다. 하루에 한사람씩 상담
// 첫째 줄에 N이 주어진다.
// 둘째 줄 부터 N개의 줄에 T와 P가 주어진다. 1일부터 N일까지 순서대로 주어진다.
// 얻을 수 있는 최대 이익을 출력한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair<int, int> > v;
int N, MAX = 0;
int t, p;
int temp = 0; 

void dfs(int nextDay, int sum){
    if(nextDay == N + 1){
         MAX = max(MAX, sum);
          //cout << MAX << endl;
         return;
    }

    if(nextDay + v[nextDay].first <= N + 1){
        dfs(nextDay + v[nextDay].first, sum + v[nextDay].second);
        // 상담을 한 경우, 그 날의 돈을 추가시킨다. 아하 그렇구나..
    }
    if(nextDay + 1 <= N + 1){
        dfs(nextDay + 1, sum); // 상담 안 한 경우, p값을 따로 추가하지 않는다. 상담을 안했으니까.
    }
}
int main(){
    cin >> N;
    v.push_back(make_pair(0, 0));
    for(int i = 0; i < N; i++){
        cin >> t >> p;
        v.push_back(make_pair(t, p));
    }
/*
    for(int i = 1; i <= N; i++){
        dfs(i, 0);
    } 이렇게 안해도 된다.
*/
    dfs(1, 0);
    cout << MAX << endl;
    return 0;
}
/*
이 문제의 포인트는 상담을 하거나, 안하거나 둘 중 하나를 고르는 것이다.
배운 점
1) 모든 경우의 수를 체크했다. 

*/