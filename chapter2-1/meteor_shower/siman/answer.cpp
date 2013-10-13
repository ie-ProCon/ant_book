#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> coord;
typedef pair<int, coord> human;

const int W = 310;
const int H = 310;
const int SAFE = 9999;

vector< vector<int> > field(H, vector<int>(W, SAFE));
vector< vector<bool> > check_list(H, vector<bool>(W, false));

bool isInside(int y, int x){
  return (0 <= y && y < H && 0 <= x && x < W);
}

int main(){
  int M, X, Y, T;

  cin >> M;

  for(int i = 0; i < M; i++){
    cin >> X >> Y >> T;

    field[Y][X] = min( field[Y][X], T );

    if(isInside( Y, X+1 )) field[Y][X+1] = min( field[Y][X+1], T );
    if(isInside( Y+1, X )) field[Y+1][X] = min( field[Y+1][X], T );
    if(isInside( Y, X-1 )) field[Y][X-1] = min( field[Y][X-1], T );
    if(isInside( Y-1, X )) field[Y-1][X] = min( field[Y-1][X], T );
  }

  queue<human> que;
  que.push( human(0, coord(0 , 0)));
  int y, x, t;

  while( !que.empty() ){
    human h = que.front(); que.pop();
    t = h.first;
    y = h.second.first;
    x = h.second.second;

    if( field[y][x] == SAFE ){
      cout << t << endl;
      return 0;
    }

    if( field[y][x] <= t || check_list[y][x]) continue;
    check_list[y][x] = true;

    if( isInside( y, x+1 ) && !check_list[y][x+1]){
      que.push( human(t+1, coord( y, x+1 )) );
    }
    if( isInside( y+1, x ) && !check_list[y+1][x]){
      que.push( human(t+1, coord( y+1, x )) );
    }
    if( isInside( y, x-1 ) && !check_list[y][x-1]){
      que.push( human(t+1, coord( y, x-1 )) );
    }
    if( isInside( y-1, x ) && !check_list[y-1][x]){
      que.push( human(t+1, coord( y-1, x )) );
    }
  }

  cout << -1 << endl;

  return 0;
}
