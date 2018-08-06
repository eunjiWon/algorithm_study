#include <iostream>
#include <algorithm>
using namespace std;
int dp[301] = {0};
int arr[301] = {0};
int n;


int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[2] + arr[0], arr[2] + arr[1]);
    for (int i = 3; i < n; i++) {
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i] + arr[i-1]); 
    }

    cout << dp[n - 1] << endl;
    return 0;
}
// 이거 영민오빠한테 물어봐야겠다...