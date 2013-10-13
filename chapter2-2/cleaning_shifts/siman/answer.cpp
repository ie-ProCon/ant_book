#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> schedule;
vector<schedule> cows;

int N, T;

int main(){
  
  cin >> N >> T;
  int st, et;

  for(int i = 0; i < N; i++){
    cin >> st >> et;
    cows.push_back( schedule(st, et)); 
  }

  sort(cows.begin(), cows.end());

  int i = 0;
  int right = 1;
  int count = 0;

  while( i < N && right != T){
    if( right != 1 ) right++;
    int limit = right;
    while( i < N && cows[i].first <= right ){
      limit = max( limit, cows[i].second );
      i++;
    }

    if( limit == right && limit != T){
      cout << -1 << endl;
      return 0;
    }

    count++;
    right = limit;
  }

  if( right == T ){
    cout << max( 1, count ) << endl;
  }else{
    cout << -1 << endl;
  }

  return 0;
}
