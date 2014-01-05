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
map<ll, int> item_cnt;
ll page_list[1000010];

int main(){
  int p, total;
  set<int> pages;
  scanf("%d", &p);
  for(int i = 0; i < p; i++){
    scanf("%lld", &page_list[i]);
    pages.insert(page_list[i]);
  }
  total = pages.size();

  int start = 0, end = 0, sum = 1;
  int answer = INT_MAX, item_num;
  item_cnt[page_list[0]]++;
  while(true){
    while( start < p-1 && sum != total ){
      start++;
      item_num = page_list[start];
      item_cnt[item_num]++;
      if( item_cnt[item_num] == 1 ) sum++;
    }
    while( end < p && sum == total ){
      answer = min( answer, start - end + 1 );
      item_num = page_list[end];
      item_cnt[item_num]--;
      if( item_cnt[item_num] == 0 ) sum--;
      end++;
    }

    if( start >= p-1 && sum < total ) break;
  }
  printf("%d\n", answer );
  return 0;
}
