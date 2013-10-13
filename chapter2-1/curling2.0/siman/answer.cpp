#include <iostream>
#include <queue>

using namespace std;

int w, h, min_count;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

typedef pair<int, int> coord;

bool check_range(int y, int x){
  return (0 <= x && x < w && 0 <= y && y < h)? true : false;
}

char field[20][20];

coord searchNextPoint(int y, int x, int d){
  int nx, ny, step;
  coord point(-1, -1);
  step = 0;

  while(check_range( y + dy[d], x + dx[d] )){
    nx = x + dx[d];
    ny = y + dy[d];

    if( field[ny][nx] == 1 ){
      if( step > 0 ){
        point.first = y;
        point.second = x;
        field[ny][nx] = 0;
      }
      break;
    }else if( field[ny][nx] == 3){
      point.first = ny;
      point.second = nx;
      break;
    }else{
      y = ny;
      x = nx;
      step++;
    }
  }

  return point;
}

void dfs(int y, int x, int count){
  if(count > 10) return;
  if(field[y][x] == 3 && min_count > count){
    min_count = count;
    return;
  }

  coord point;

  for(int d = 0; d < 4; d++){
    point = searchNextPoint( y, x, d );
    if(point.first != -1){
      if(field[point.first][point.second] == 3){
        dfs( point.first, point.second, count + 1 );
      }else{
        dfs( point.first, point.second, count + 1 );
        field[point.first + dy[d]][point.second + dx[d]] = 1;
      }
    }
  }
}

int main(){
  int sx, sy, num;

  while(true){
    cin >> w >> h;
    min_count = 9999;

    if( w == 0 && h == 0 ) break;

    for(int y = 0; y < h; y++){
      for(int x = 0; x < w; x++){
        cin >> num;
        field[y][x] = num;
        if(num == 2){
          sx = x; 
          sy = y;
        }
      }
    }

    dfs( sy, sx, 0 );
    if(min_count == 9999){
      cout << -1 << endl;
    }else{
      cout << min_count << endl;
    }
  }
  return 0;
}
