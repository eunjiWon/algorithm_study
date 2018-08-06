//긱스코드는 어려워서 더 직관적인 코드로 백트레킹을 보겠다.
//그냥 dfs 완전탐색과 어떤 점이 다른지 보자
#include <iostream>
using namespace std;
int list[] = {10, 7, 5, 18, 12, 20, 15};
int sum = 0;
int cnt = 0;
void dfs(int idx){
    if(idx == 7){ // 0~6까지니까 인덱스가 7포함하면 안된다.
        return;
    }
    else{
        if(sum + list[idx] != 35){
            dfs(idx + 1);
            sum += list[idx]; // 그 숫자 선택해서 합으로 더해주고 
            dfs(idx + 1);
            sum -= list[idx]; // 다시 빼주는 의미는 선택을 안했다는 것이다.
        }
        else{
            cnt++;
            return;
        }
        
    }
}
    
int main(){
    dfs(0);
    cout << cnt << endl;
    return 0;
}