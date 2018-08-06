#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std;

string solution(string S, vector<vector<int> > interval)
{
	string answer = "";
    for(int i = 0; i < interval.size(); i++){
        int t1, t2;
        t1 = interval[i][0];
        t2 = interval[i][1];
        reverse(&S[t1-1], &S[t2]);
    }
    // 벡터는 size()이다. 그리고 
    // S.begin()+1 이런식으로 했어도 됐겠다.
    
    return S;
}