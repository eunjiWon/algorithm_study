/*
    트리 만들기를 거치지 않고 바로 포스트오더를 출력할 수도 있다.
    미리 모든 노드의 인오더에서의 위치를 저장해놓으면 
    O(N) 시간 만에 포스트오더를 전부 출력할 수 있다.
*/
#include <iostream>
using namespace std;
// in[]에서 루트의 인덱스를 찾아줌
int search(int arr[], int x, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == x)
            return i;
    }
    return -1;
}
int printPostOrder(int in[], int pre[], int n){
    int root = search(in, pre[0], n);
    // If left subtree is not empty, print left subtree
    if(root != 0)
        printPostOrder(in, pre + 1, root); // pre + 1 하면 맨 앞에꺼가 사라지나...
    // If right subtree is not empty, print right subtree
    if(root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    // Print root
    cout << pre[0] << " ";
}
int main(){
    int in[] = {4,2,5,1,3,6};
    int pre[] = {1,2,4,5,3,6};
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    printPostOrder(in, pre, n);
    return 0;
}