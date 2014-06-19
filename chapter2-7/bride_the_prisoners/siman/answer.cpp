#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int dp[10010][10010];
int prisoner[10010];

void init(int p, int q){
  prisoner[0] = 0;
  prisoner[q+1] = p+1;
  for(int i = 1; i <= q; i++){
    cin >> prisoner[i];
  }
  for(int i = 0; i <= q; i++){
    dp[i][i+1] = 0;
  }
}

void solve(int t, int p, int q){
  init( p, q );
  for(int w = 2; w <= q+1; w++){
    for(int i = 0; i + w <= q + 1; i++){
      int j = i + w;
      int t = 10000000;

      for(int k = i+1; k < j; k++){
        t = min( t, dp[i][k] + dp[k][j] );
      }

      dp[i][j] = t + prisoner[j] - prisoner[i] - 2;
    }
  }
  printf("Case #%d: %d\n", t, dp[0][q+1]);
}

int main(){
  int t, q, p;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> p >> q;

    solve( i+1, p, q );
  }
  return 0;
}
