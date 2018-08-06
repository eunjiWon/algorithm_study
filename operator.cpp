#include <iostream>
using namespace std;
int n;
int num[12];
int op[5]; 
int mini = 1000000000; int maxi = -1000000000;

void dfs(int c, int v){
    if (c == n-1) {
		maxi = maxi < v ? v : maxi;
		mini = mini > v ? v : mini;
		return;
	}
    if (op[0]) --op[0], dfs(c + 1, v + num[c+1]), ++op[0];
	if (op[1]) --op[1], dfs(c + 1, v - num[c+1]), ++op[1];
	if (op[2]) --op[2], dfs(c + 1, v * num[c+1]), ++op[2];
	if (op[3]) --op[3], dfs(c + 1, v / num[c+1]), ++op[3];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    dfs(0, num[0]);
    cout << maxi << endl <<  mini << endl;
    return 0;
}
