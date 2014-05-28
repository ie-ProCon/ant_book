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

int cow_direct[5010];
int rot[5010];

int main(){
  int N;
  char d;
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    cin >> d;
    if( d == 'F' ){
      cow_direct[i] = 0;
    }else{
      cow_direct[i] = 1;
    }
  }

  int MIN_M = INT_MAX;
  int MIN_K, M, num;
  bool success;
  for(int K = 1; K <= N; K++){
    M = 0;
    memset( rot, 0, sizeof(rot) );
    success = true;
    num = 0;
    for(int i = 0; i < N-K+1; i++){
      if(( cow_direct[i] + num ) % 2 != 0 ){
        rot[i] = 1;
        M++;
        num++;
      }
      if( i - K + 1 >= 0 ){
        num -= rot[i-K+1];
      }
    }
    for(int j = N-K+1; j < N; j++){
      if(( cow_direct[j] + num ) % 2 != 0 ) success = false;
      if( j - K + 1 >= 0 ){
        num -= rot[j-K+1];
      }
    }
    if( success && MIN_M > M ){
      MIN_K = K;
      MIN_M = M;
    }
  }
  printf("%d %d\n", MIN_K, MIN_M );
  return 0;
}
