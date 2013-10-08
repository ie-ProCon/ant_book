#include <iostream>
#include <set>

using namespace std;

int unit[6] = { 1, 10, 100, 1000, 10000, 100000 };
int field[5][5];
int dx[4] = { 1, 0,-1, 0 };
int dy[4] = { 0, 1, 0,-1 };
set<int> answer;

bool isInside(int y, int x){
  return ( 0 <= y && y < 5 && 0 <= x && x < 5 );
}

void dfs(int y, int x, int value, int count){
  value += field[y][x] * unit[count];
  count++;

  if( count == 6 ){
    answer.insert(value);
    return;
  }

  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if( isInside( ny, nx ) ){
      dfs( ny, nx, value, count );
    }
  }
}

int main(){

  for(int y = 0; y < 5; y++){
    for(int x = 0; x < 5; x++){
      cin >> field[y][x];
    }
  }

  for(int y = 0; y < 5; y++){
    for(int x = 0; x < 5; x++){
      dfs( y, x, 0, 0 );
    }
  }

  cout << answer.size() << endl;

  return 0;
}
