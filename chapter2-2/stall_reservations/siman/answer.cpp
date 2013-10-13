#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> schedule;
typedef pair<int, int> stall;
typedef pair<schedule, int> cow;

int main(){
  int a, b, n, id = 1;
  vector<cow> cows;
  priority_queue< stall, vector<stall>, greater<stall> > que;

  cin >> n;

  vector<int> scheduling(n);

  for(int i = 0; i < n; i++){
    cin >> a >> b;
    cows.push_back(cow(schedule(a, b), i));
  }

  sort(cows.begin(), cows.end());

  for(int i = 0; i < n; i++){
    cow c = cows[i];
    schedule cs = c.first;

    if( que.empty() ){
      que.push(stall(cs.second, id));
      scheduling[c.second] = id;
    }else if( que.top().first < cs.first ){
      stall s = que.top(); que.pop();
      que.push(stall(cs.second, s.second));
      scheduling[c.second] = s.second;
    }else{
      id++;
      que.push(schedule(cs.second, id));
      scheduling[c.second] = id;
    }
  }

  int size = scheduling.size();

  cout << id << endl;
  for(int i = 0; i < size; i++){
    cout << scheduling[i] << endl;
  }

  return 0;
}
