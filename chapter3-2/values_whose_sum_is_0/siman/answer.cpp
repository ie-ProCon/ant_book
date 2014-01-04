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
ll values[4][4000];
ll valueE[16000000];

int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 4; j++){
      scanf("%lld", &values[j][i]);
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      valueE[i*N+j] = values[0][i] + values[1][j];
    }
  }
  sort( valueE, valueE + N*N );

  ll CD;
  ll answer = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      CD = -(values[2][i] + values[3][j]);
      answer += upper_bound( valueE, valueE + N*N, CD ) - lower_bound( valueE, valueE + N*N, CD );
    }
  }
  printf("%lld\n", answer );
  return 0;
}
