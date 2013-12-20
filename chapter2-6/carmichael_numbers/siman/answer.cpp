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

ll calc( ll n, ll x ){
  ll val = 1;
  int mod = n;

  while( n > 0 ){
    if( n & 1 ){
      val = ( val * x ) % mod;
    }
    x = ( x * x ) % mod;
    n >>= 1;
  }

  return val;
}

int main(){
  int n;
  cin >> n;

  bool flag = true;
  for(int x = 2; x < n; x++){
    ll val = calc( n, x );
    if( val % n != x ) flag = false;
  }
  if( flag ){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
