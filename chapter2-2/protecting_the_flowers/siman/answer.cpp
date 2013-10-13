#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
ll total_time;
ll sum;

struct cow {
  int t,d;

  bool operator <(const cow &e) const{
    return t*e.d < e.t*d;
  }   
};

vector<cow> cow_list;

int main(){
  ll N, T, D;
  ll answer = 0;
  total_time = 0;
  sum = 0;

  cin >> N;

  for(ll i = 0; i < N; i++){
    cin >> T >> D;
    sum += D;

    cow c;
    c.t = T;
    c.d = D;
    cow_list.push_back(c);
  }

  sort( cow_list.begin(), cow_list.end());

  for(int i = 0; i < N; i++){
    sum -= cow_list[i].d;
    answer += 2 * sum * cow_list[i].t;
  }

  cout << answer << endl;

  return 0;
}
