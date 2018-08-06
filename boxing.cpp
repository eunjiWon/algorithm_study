#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[1000];
    int lis[1000];
    
    int n = 0;
    int max = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        lis[i] = 1;
    }
 
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && (lis[i] < lis[j] + 1)){
                lis[i] = lis[j] + 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(max < lis[i])
            max = lis[i];
    }
    cout << max << endl;
}