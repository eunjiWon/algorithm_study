#include <string>
#include <vector>
using namespace std;
int ans = 0;
void dfs(int c, int v, vector<int> &numbers){ // 주소로 받아야 한다.
    if(c == numbers.size() - 1){
        if(v == 0) ans++;
        return;
    }
    dfs(c + 1, v + numbers[c + 1], numbers);
    dfs(c + 1, v - numbers[c + 1], numbers);
};
int solution(vector<int> numbers) {
    dfs(0, numbers[0], numbers);
    dfs(0, -(numbers[0]), numbers);
    return ans % 100000;
}