import java.util.Scanner;

// 이제 c++ 할테야..
public class MaximumSizeSquareSubmatrixwithAll1s{
    static int printMaxSubSquare(int M[][]){
        int i, j;
        int R = M.length;
        int C = M[0].length;
        int S[][] = new int[R][C];

        int max_value = 0;

        for(i = 0; i < R; i++)
            S[i][0] = M[i][0];
        for(j = 0; j < C; j++)
            S[0][j] = M[0][j];
        for(i = 1; i < R; i++){
            for(j = 1; j < C; j++){
                if(M[i][j] == 1)
                    S[i][j] = Math.min(S[i - 1][j - 1], (Math.min(S[i - 1][j], S[i][j - 1]))) + 1;
                else   
                    S[i][j] = 0;
            }
        }
        for(i = 0; i < R; i++){
            for(j = 0; j < C; j++){
                if(max_value < S[i][j])
                    max_value = S[i][j];
            }
        }
        return max_value * max_value;
    }
    public static void main(String[] args){
        int r, c;
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        c = sc.nextInt();
        int M[][] = new int[r][c];
        String[] num = new String[r];
        for(int i = 0; i < r; i++){
            num[i] = sc.next();
            for(int j = 0; j < c; j++){
               M[i][j] = num[i].charAt(j) - '0'; // 사실 왜 이러는줄 모름...
               // 자바로 입력을 안받아봐서 좀 어려웠다
            }
        }
        System.out.println(printMaxSubSquare(M));
    }
}
// 제일 큰 수 찾아서 그거 제곱하는게 면적 구하는거다.
// 코딩 다하고 슬랙에 올려야지... 