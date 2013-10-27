#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case_0();

int main(){
  test_case_0();
}

int solve(int m, int n, int *a, int M){
  int dp[n+1][m+1];
  memset( dp, 0, sizeof(dp));
  for(int i = 0; i <= n; i++){
    dp[i][0] = 1;
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 1; j <= m; j++){
      if( j - 1 - a[i] >= 0 ){
        dp[i+1][j] = (dp[i][j] + dp[i+1][j-1] - dp[i][j-1-a[i]] + M) % M;
      }else{
        dp[i+1][j] = (dp[i][j] + dp[i+1][j-1]) % M;
      }
    }
  }

  return dp[n][m];
}

void test_case_0(){
  int n = 3;
  int m = 3;
  int a[3] = { 1, 2, 3 };
  int M = 10000;
  int expected = 6;

  int recieved = solve( m, n, a, M );
  if( recieved == expected ){
    printf("Test Case #0...PASSED\n");
  }else{
    printf("Test Case #0...FAILED\n");
    printf("\tExpected: %d\n", expected);
    printf("\tRecieved: %d\n", recieved);
  }
}
