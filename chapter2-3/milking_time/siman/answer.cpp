#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

struct data {
  int start_hour;
  int end_hour;
  int effective;

  bool operator<(const data& e) const {
    return end_hour < e.end_hour;
  }
};


int main(){

  int N, M, R;
  int start_hour, end_hour, effective;
  vector<data> working_list;

  cin >> N >> M >> R;

  vector<ll> dp(1000001);
  map< int, ll > info;

  for(int i = 0; i < M; i++){
    cin >> start_hour >> end_hour >> effective;
    data d;
    d.start_hour = start_hour;
    d.end_hour = end_hour;
    d.effective = effective;

    working_list.push_back(d);
  }

  sort( working_list.begin(), working_list.end() );

  dp[0] = 0;
  info[0] = 0;
  ll max_effective = 0;

  for(int i = 0; i < M; i++){
    data d = working_list[i];
    map< int, ll >::iterator it = info.begin();

    while( it != info.end() ){
      if( (*it).first <= max( 0, d.start_hour-R ) ){
        dp[d.end_hour] = max( dp[d.end_hour], dp[(*it).first] + d.effective );
        max_effective = max( max_effective, dp[d.end_hour] );
        info[d.end_hour] = dp[d.end_hour];
      }
      it++;
    }
  }

  cout << max_effective << endl;

  return 0;
}
