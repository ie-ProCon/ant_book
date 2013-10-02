#include <iostream>

using namespace std;

int N, M;
char field[100][100];

bool check_range(int y, int x){
  return (0 <= x && x < M && 0 <= y && y < N)? true : false;
}

void dfs(int y, int x){
  if(field[y][x] == 'W'){
    field[y][x] = '.';
    if(check_range(y,x+1)) dfs(y, x+1);
    if(check_range(y+1,x)) dfs(y+1, x);
    if(check_range(y,x-1)) dfs(y, x-1);
    if(check_range(y-1,x)) dfs(y-1, x);

    if(check_range(y-1,x+1)) dfs(y-1, x+1);
    if(check_range(y+1,x+1)) dfs(y+1, x+1);
    if(check_range(y+1,x-1)) dfs(y+1, x-1);
    if(check_range(y-1,x-1)) dfs(y-1, x-1);
  }
}

int main(){
  int count = 0;

  cin >> N >> M;

  for(int y = 0; y < N; y++){
    for(int x = 0; x < M; x++){
      cin >> field[y][x];
    }
  }

  for(int y = 0; y < N; y++){
    for(int x = 0; x < M; x++){
      if(field[y][x] == 'W'){
        dfs(y, x);
        count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}
