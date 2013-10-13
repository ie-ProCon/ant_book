#include <iostream>

using namespace std;

const int dx[4] = { 1, 0, -1, 0};
const int dy[4] = { 0, 1, 0, -1};

int W, H;

char field[20][20];

bool check_range(int y, int x){
  return (0 <= y && y < H && 0 <= x && x < W)? true : false;
}

int dfs(int y, int x){
  int nx, ny, count = 1;
  field[y][x] = 'x';

  for(int i = 0; i < 4; i++){
    ny = y + dy[i];
    nx = x + dx[i];

    if(check_range( ny, nx ) && field[ny][nx] == '.'){
      count += dfs(ny, nx);
    }
  }

  return count;
}

int main(){
  int sx, sy;
  
  while(true){
    cin >> W >> H;
    if( W == 0 && H == 0 ) break;

    for(int y = 0; y < H; y++){
      for(int x = 0; x < W; x++){
        cin >> field[y][x];        

        if(field[y][x] == '@'){
          sy = y;
          sx = x;
        }
      }
    }

    cout << dfs( sy, sx ) << endl;
  }
  return 0;
}
