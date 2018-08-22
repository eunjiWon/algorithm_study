#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n;
int DP[10001][2];
vector<int> adj[10001];// 이차원이군
vector<int> ans;
int w[10001];
int flag = 0;

void dp(int cur, int parent){
	DP[cur][1] = w[cur];
	for(int i = 0; i < adj[cur].size(); i++){
		int child = adj[cur][i];
		if(child == parent) continue;
		dp(child, cur);
		DP[cur][1] += DP[child][0];
		DP[cur][0] += max(DP[child][1], DP[child][0]);
	}
}
void trace(int cur, int parent, int f){
	if(f == 1){
		ans.push_back(cur);
	}
	for(int i = 0; i < adj[cur].size(); i++){
		int child = adj[cur][i];
		if(child == parent) continue;
		if(f == 1){
			trace(child, cur, 0);
		}
		else{
			if(DP[child][0] < DP[child][1])
				trace(child, cur, 1);
			else trace(child, cur, 0);
		}
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	dp(0, -1);
	if(DP[0][0] <= DP[0][1]){
		flag = 1;
		cout << DP[0][1] << endl;
	}
	else{
		flag = 0;
		cout << DP[0][0] << endl;
	}
	trace(0, -1, flag);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] + 1 << " ";
	}
	return 0;
}