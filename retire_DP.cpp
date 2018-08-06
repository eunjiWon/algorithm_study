#include <iostream>
#include <algorithm>
using namespace std;
int D[16] = {-100}; // 첫째 줄에 N (1 ≤ N ≤ 15)이 주어진다.
int T[16];
int P[16];
int n;

//dp의 경우
int dp(int day){
    if(day == n+1) return 0;
    //날짜가 n+1보다 크다면 -값을 크게 준다.
    if(day > n+1) return -987654321;
    //메모이제이션
    if(D[day] > 0) return D[day];
    //점화식 상담을 안한다 혹은 상담을 한다. 둘 중 하나를 고른다.
    return D[day] = max(dp(day+1), dp(day+T[day])+P[day]);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){   
        cin >> T[i] >> P[i];
    }   
    cout << dp(1) << endl;
    return 0;
}

/*
배운 점
1) 인덱스가 day 인 경우 1일부터가 편하니까 for문도 1부터 돌린다.
2) 리컬시브 펑션에는 항상 베이스 케이스가 있다. 
보통 DP도 재귀를 많이 이용하니까 이 코드에도 베이스 케이스가 당연히 있어야 한다.
3) DP는 단순 재귀가 아니라, 메모리제이션이 항상 있다. if문으로... 
4) 이 문제는 상담을 하거나 안하거나 둘 중 하나를 고르는 것이 핵심이다.
5) 점화식: D[i] : i 번째 날의 최대 p의 값?
상담 안했을때의 값과 했을 때의 값을 비교해서 선택하는 것이다?
max(dp(day + 1), dp[]) 
*/

/*
1) DP
2) https://www.acmicpc.net/problem/14501
3) dfs로 먼저 상담을 한 경우와 안 한 경우 모두를 체크해서 제일 큰 값을 골랐는데
dp로 풀이한 걸 봤는데... 훨씬 간단한데 점화식 세우기가 어려운거 같다...
*/