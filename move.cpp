#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int arr[1000][1000] = {0};
    int value[1000][1000] = {0};
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    value[0][0] = arr[0][0];
    for(int i = 1; i < N; i++){
        value[i][0] = value[i - 1][0] + arr[i][0];
    }
    for(int i = 1; i < M; i++){
        value[0][i] = value[0][i - 1] + arr[0][i];
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j < M; j++){
            value[i][j] = max(value[i - 1][j - 1], max(value[i - 1][j], value[i][j - 1])) + arr[i][j];
        }   
    }
    cout << value[N - 1][M - 1] << endl;
   
}