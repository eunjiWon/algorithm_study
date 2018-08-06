#include <string>
#include 
using namespace std;
int arr[11][11] = {0};
int ans = 0;
bool check(int x, int y){
    if(x < 0 && x > 10 && y < 0 && y > 10)
        return false;
    else 
        return true;
}
void dfs(int x, int y, string &dirs, int c){
    if(x < 0 && x > 10 && y < 0 && y > 10){
        return;
    }
    if(c == dirs.length() - 1){
        return;
    }
    if(arr[x][y] == 0){
        arr[x][y] = 1;
        ans++;
    }
    if(dirs[c] == 'U'){
        if(check(x - 1, y))
            dfs(x - 1, y, dirs, c + 1);
        else dfs(x , y, dirs, c + 1);
        
    }
    else if(dirs[c] == 'D'){
        if(check(x + 1, y))
            dfs(x + 1, y, dirs, c + 1);
        else dfs(x , y, dirs, c + 1);
    }    
    else if(dirs[c] == 'R'){
        if(check(x, y + 1))
            dfs(x, y + 1, dirs, c + 1);
        else dfs(x , y, dirs, c + 1);
    }
    else if(dirs[c] == 'L'){
        if(check(x, y - 1))
            dfs(x, y - 1, dirs, c + 1);
        else dfs(x , y, dirs, c + 1);
    }
    else;
    
}
int solution(string dirs)
{
	dfs(5,5, dirs, 0);
    return ans;
}