class knightTour{
	static int N = 8;
	
	static boolean isSafe(int x, int y, int sol[][]){
		return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);//한번도 안가본 곳이면 -1
	}
	static void printSolution(int sol[][]){
		for(int x = 0; x < N; x++){
			for(int y = 0; y < N; y++){
				System.out.print(sol[x][y] + " ");
			}
			System.out.println();
		}
	}
	// I use backtracking to solve knightTour problem
	static boolean solveKT(){
		int sol[][] = new int[8][8];
		for(int x = 0; x < N; x++){
			for(int y = 0; y < N; y++){
				sol[x][y] = -1; //initialize matrix to -1
			}
		}
		int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
		int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

		sol[0][0] = 0; // Since the knight is initially at the first block
		//Start from 0, 0 and explore all tours using solveKTUtil()
		if(!solveKTUtil(0, 0, 1, sol, xMove, yMove)){
			System.out.println("Solution does not exist");
			return false;
		}else{ // why print?
			printSolution(sol);
		}
		return true;
	}
	static boolean solveKTUtil(int x, int y, int movei, int sol[][], int xMove[], int yMove[]){
		int k, next_x, next_y;
		if(movei == N * N)	
			return true; // 다 탐방했으면 트루 리턴
		for(k = 0; k < 8; k++){
			next_x = x + xMove[k];
			next_y = y + yMove[k];
			if(isSafe(next_x, next_y, sol)){
				sol[next_x][next_y] = movei; //	맨처음에는 1을 보냄, 먼저 바꿔주고
				if(solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove)) 
					return true;
				else sol[next_x][next_y] = -1; // backtracking, 보낸거에서 세이프가 아니라 false리턴
				//	하면 다시 -1로 해준다.
			}
		}
		return false; // 저 위에서 트루 리턴할 때 전체 솔루션 프린트 하나? 
	}
	
	public static void main(String args[]){
		solveKT();
	}
}
/*
1) Backtracking
2) https://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
3) 안전한 곳이 아닐 때 false를 보내 다시 -1로 업데이트해서 결과적으로 다시 값을 원래대로 복구시켜준다.
8방향 코딩하는 거 배웠다...
백트레킹 어렵다는 걸 배웠다...ㅋㅋ... 백트레킹 잘하고 싶다...
*/

















