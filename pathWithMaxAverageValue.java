class pathWithMaxAverageValue{
    public static double maxAverageOfPath(int cost[][], int N){
        int dp[][] = new int[N+1][N+1];
        dp[0][0] = cost[0][0];
        for(int i = 1; i < N; i++){
            dp[i][0] = dp[i-1][0] + cost[i][0];
        }
        for(int j = 1; j < N; j++){
            dp[0][j] = dp[0][j-1] + cost[0][j];
        }
        for(int i = 1; i < N; i++){
            for(int j = 1; j < N; j++){
                dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]) + cost[i][j];
            }
        }
        return (double)dp[N-1][N-1] / (2 * N - 1); // 분모는 무조건 정해져있다.
        // 나는 처음에 2N-1이 아니라 카운트 하려고 했는데 그럼 디피 만들기 어려워졌을 것
    }
    public static void main(String[] args){
        int cost[][] = {
            {1, 2, 3},
            {6, 5, 4},
            {7, 3, 9}
        };
        System.out.println(maxAverageOfPath(cost, 3));
    }
} 