#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> coin;

int main(){
  int N, C, V, B;
  int answer = 0;
  vector<coin> coins;

  cin >> N >> C;

  for(int i = 0; i < N; i++){
    cin >> V >> B;
    if( V >= C ){
      answer += B;
    }else{
      coins.push_back( coin( V, B ) );
    }
  }

  sort( coins.begin(), coins.end() );
  reverse( coins.begin(), coins.end() );

  int size = coins.size();
  int cost, count, val, num;
  int i, index = 0;

  while(index < size){
    while( index < size && coins[index].second <= 0 ){
      index++;
    }

    i = index;
    cost = C;

    for(; i < size-1 ; i++){
      val = coins[i].first;
      num = coins[i].second;

      if( num > 0 ){
        count = min( num, cost / val ); 
        cost -= val * count;
        coins[i].second -= count;
        if( cost <= 0 ) break;
      }
    }


    if( cost <= 0 ){
      answer++;
      continue;
    }

    for(; i >= 0 ; i-- ){
      val = coins[i].first;
      num = coins[i].second;

      if( num > 0 ){
        if( cost % val == 0 ){
          count = min( num, cost/val );
        }else{
          count = min( num, cost/val + 1);
        }
        cost -= val * count;
        coins[i].second -= count;
        if( cost <= 0 ) break;
      }
    }

    if( cost > 0 ) break;
    answer++;
  }

  cout << answer << endl;

  return 0;
}
