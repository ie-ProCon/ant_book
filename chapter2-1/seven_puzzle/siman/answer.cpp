#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef pair<int, int> info;
typedef pair<string, info> data;

bool isInside( int index ){
  return ( 0 <= index && index < 8 );
}

int main(){

  map<string, bool> check_list;
  map<string, int> answer_list;
  char num;

  queue<data> que;
  que.push(data("01234567", info(0, 0)));
  answer_list["01234567"] = 0;

  while( !que.empty() ){
    data d = que.front(); que.pop();
    if( check_list[d.first] ) continue;

    string s = d.first;
    int index = d.second.first;
    int count = d.second.second;

    answer_list[s] = count;
    check_list[s] = true;

    if( index != 3 && isInside( index+1 ) ){
      string ns = s;
      ns[index] = ns[index+1];
      ns[index+1] = '0';
      que.push(data(ns, info(index+1, count+1)));
    }
    if( isInside( index+4 ) ){
      string ns = s;
      ns[index] = ns[index+4];
      ns[index+4] = '0';
      que.push(data(ns, info(index+4, count+1)));
    }
    if( index != 4 && isInside( index-1 ) ){
      string ns = s;
      ns[index] = ns[index-1];
      ns[index-1] = '0';
      que.push(data(ns, info(index-1, count+1)));
    }
    if( isInside( index-4 ) ){
      string ns = s;
      ns[index] = ns[index-4];
      ns[index-4] = '0';
      que.push(data(ns, info(index-4, count+1)));
    }
  }

  while(true){
    string goal = "";
    for(int i = 0; i < 8; i++){
      cin >> num;
      if(cin.eof()) return 0;
      goal += num;
    }
    cout << answer_list[goal] << endl;
  }

  return 0;
}
