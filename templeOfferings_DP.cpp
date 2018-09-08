#include <iostream>
using namespace std;

struct Temple{
    int L, R;
};
int offeringNumber(int n, int templeHeight[]){
    Temple chainSize[n];
    for(int i = 0; i < n; i++){
        chainSize[i].L = -1;
        chainSize[i].R = -1;
    }
    chainSize[0].L = 1;
    chainSize[n-1].R = 1;
    for(int i = 1; i < n; i++){ // 전체 진행방향은 right 으로 가고 원소 입장에선 왼쪽에서 온다
        if(templeHeight[i - 1] < templeHeight[i])
            chainSize[i].L = chainSize[i - 1].L + 1;
        else   
            chainSize[i].L = 1;
    }
    for(int i = n - 2; i >= 0; i--){
        if(templeHeight[i + 1] < templeHeight[i])
            chainSize[i].R = chainSize[i + 1].R + 1;
        else    
            chainSize[i].R = 1;
    }
    int sum;
    for(int i = 0; i < n; i++){
        sum += max(chainSize[i].L, chainSize[i].R);
    }
    return sum;
}
int main(){
    int arr1[3] = {1, 2, 2};
    cout << offeringNumber(3, arr1) << endl;
    return 0;
}
