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
double cables[10010];
int n, k;

ll check_cnt(double length){
  ll cnt = 0;
  for(int i = 0; i < n; i++){
    cnt += (int)(cables[i]/length);
  }
  return cnt;
}

int main(){
  scanf("%d %d", &n, &k);
  double a = 0.0, b = 10000000000.0, c;
  for(int i = 0; i < n; i++){
    scanf("%lf", &cables[i]);
  }

  for(int i = 0; i < 200; i++){
    c = ( a + b ) / 2.0;
    ll cnt = check_cnt(c);
    if( k <= cnt ){
      a = c;
    }else{
      b = c;
    }
  }
  printf("%0.2f\n", floor(b*100.0)/100.0 );
  return 0;
}
