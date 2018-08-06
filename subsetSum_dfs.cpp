#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int list[] = {10, 7, 5, 18, 12, 20, 15};
int temp[7];
int sum = 0;
int flag[7];

void dfs(int idx, int total_sum){
    if(idx > 7){ // 0~6까지니까 인덱스가 7포함하면 안된다.
        return;
    }
    else{
        if(total_sum != 35){
            flag[idx] = 1;
            dfs(idx + 1, total_sum + list[idx]);
            flag[idx] = 0;
            dfs(idx + 1, total_sum);
        }
        else{
            sum++;
            for(int i = 0; i < 7; i++){
                if(flag[i] == 1)
                    cout << list[i] << " "; 
            }
            cout << endl;
            return;
        }
        
    }
}
    
int main(){
    dfs(0, 0);
    cout << sum << endl;
    
    return 0;
}