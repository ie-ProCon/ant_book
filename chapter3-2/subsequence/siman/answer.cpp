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
int number_list[100010];

void solver(int n, int s){
  int answer = INT_MAX;
  int start = 0, end = 0, sum;
  for(int i = 0; i < n; i++){
    scanf("%d", &number_list[i]);
  }
  sum = number_list[0];
  while( true ){
    if( s <= sum ){
      answer = min( answer, start - end + 1 );
      if( end < start ){
        sum -= number_list[end];
        end++;
      }else if( start < n-1 ){
        start++;
        sum += number_list[start];
      }
    }else if( start < n-1 ){
      start++;
      sum += number_list[start];
    }

    if( start == n-1 && sum <= s ) break;
  }
  printf("%d\n", ( answer == INT_MAX )? 0 : answer );
}

int main(){
  int t, n, s;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
    scanf("%d %d", &n, &s);
    solver( n, s );
  }
  return 0;
}
