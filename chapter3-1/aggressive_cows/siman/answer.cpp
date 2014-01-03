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
int n, m;
vector<int> distances;

typedef long long ll;

bool judge(int dist){
  int before = distances[0];
  int index = 1;
  for(int i = 1; i < m; i++){
    while( index < n && distances[index] - before < dist ){
      index++;
    }
    if( index == n ) return false;
    before = distances[index];
  }
  return true;
}

int main(){
  int dist;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &dist);
    distances.push_back(dist);
  }
  sort( distances.begin(), distances.end() );

  int a = 0, b = 1000000000, c;
  while( b - a > 1 ){
    c = ( a + b ) / 2;
    if( judge(c) ){
      a = c;
    }else{
      b = c;
    }
  }
  cout << a << endl;
  return 0;
}
