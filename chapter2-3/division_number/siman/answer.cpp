#include <iostream>

using namespace std;

void test_case_0();

int main(){
  test_case_0();

  return 0;
}

int solve(int m, int n, int M){
  int dp[m+1][n+1];
  memset( dp, 0, sizeof(dp));

  dp[0][0] = 1;

  for(int i = 1; i <= m; i++){
    for(int j = 0; j <= n; j++){
      if( j < i ){
        dp[i][j] = dp[i-1][j];
      }else{
        dp[i][j] = (dp[i][j-i] + dp[i-1][j]) % M;
      }
    }
  }

  return dp[m][n];
}


void test_case_0(){
  int n = 4;
  int m = 3;
  int M = 10000;
  int expected = 4;
  
  int recieved = solve( m, n, M );
  if( recieved == expected ){
    printf("Test Case #0...PASSED\n");
  }else{
    printf("Test Case #0...FAILED\n");
    printf("\tExpected: %d\n", expected);
    printf("\tRecieved: %d\n", recieved);
  }
}
