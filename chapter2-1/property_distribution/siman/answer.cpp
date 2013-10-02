#include <iostream>

using namespace std;

int H, W;

char field[100][100];

bool check_range(int y, int x){
  return (0 <= x && x < W && 0 <= y && y < H)? true : false;
}

void dfs(int y, int x, char type){
  field[y][x] = '.';

  if(check_range(y, x+1) && type == field[y][x+1]) dfs(y, x+1, type);
  if(check_range(y+1, x) && type == field[y+1][x]) dfs(y+1, x, type);
  if(check_range(y, x-1) && type == field[y][x-1]) dfs(y, x-1, type);
  if(check_range(y-1, x) && type == field[y-1][x]) dfs(y-1, x, type);
}

int main(){

  while(true){
    int count = 0;
    cin >> H >> W;

    if( H == 0 && W == 0 ) break;

    for(int y = 0; y < H; y++){
      for(int x = 0; x < W; x++){
        cin >> field[y][x];
      }
    }

    for(int y = 0; y < H; y++){
      for(int x = 0 ; x < W; x++){
        if(field[y][x] != '.'){
          count++;
          dfs(y, x, field[y][x]);
        }
      }
    }

    cout << count << endl;
  }
  return 0;
}
