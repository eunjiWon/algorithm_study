#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int cnt = 0;
    int ans = 0;
    string s;
    cin >> s;
    int len = s.length();
    vector<int> flag(len, 0);
    int i;
    int j = len;
    
    for(i = 0; i < j; i++){
        if(i == 0 || i == j - 1){
            continue; 
        } 
        int front = i - 1;
        int back = i + 1;
        while(front >= 0 && back <= j - 1){
            if(s[front] == s[back]){
                flag[i] += 2; front--; back++;
            }
            else{
                front--; back++;
            }
        }
    }
    for(int i = 0; i < len; i++){
    }
    for(int i = 0; i < len; i++){
        if(ans < flag[i])
            ans = flag[i];
    }
    cout << ans << endl;
    return 0;
}
