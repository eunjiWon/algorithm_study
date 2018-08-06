import java.util.Scanner;
class LIS{
    static int lis(int arr[], int n){
        int lis[] = new int[n];
        int i, j, max = 0;
        for(i = 0; i < n; i++){
            lis[i] = 1;
        }
        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                }
            }
        }
        for(i = 0; i < n; i++){
            if(max < lis[i])
                max = lis[i];
        }
        return max;
    }
    public static void main(String args[]){
        int arr[] = new int[1000];
        Scanner sc = new Scanner(System.in);
        int n = 0;
        n = sc.nextInt();
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
       System.out.println(lis(arr, n));
    }
}