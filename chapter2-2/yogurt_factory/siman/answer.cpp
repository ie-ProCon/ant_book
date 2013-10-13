#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> week_info;
typedef long long ll;

ll cost_list[10000];
vector<week_info> weeks;

int main(){
  int N, S; 
  ll cost, produce;

  cin >> N >> S;

  for(int i = 0; i < N; i++){
    cin >> cost >> produce;
    cost_list[i] = cost * produce;
    weeks.push_back(week_info( cost, produce ));
  }

  ll total_cost = 0;

  for(int i = 0; i < N; i++){
    total_cost += cost_list[i];
    cost = weeks[i].first;
    for(int j = i+1; j < N; j++){
      cost += S;
      if( cost < weeks[j].first ){
        cost_list[j] = min( cost_list[j], cost * weeks[j].second);
      }
    }
  }

  cout << total_cost << endl;

  return 0;
}
