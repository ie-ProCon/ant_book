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

int main(){
  int n = 5;
  int numbers[5] = { 2, 3, 3, 5, 6 };
  int k = 3;
  int a = 0, b = 4, c;

  while( b - a > 1 ){
    c = ( a + b ) / 2;
    if( numbers[c] < k ){
      a = c;
    }else{
      b = c;
    }
  }

  cout << b << endl;
  return 0;
}
