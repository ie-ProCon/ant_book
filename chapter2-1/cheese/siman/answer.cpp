#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int H, W, N;
typedef pair<int, int> coord;

struct data {
  int y, x, cost, dist;

  bool operator >(const data &e) const{
    return cost > e.cost;
  }
};

bool isInside( int y, int x ){
  return ( 0 <= y && y < H && 0 <= x && x < W );
}

int main(){

  cin >> H >> W >> N;

  vector< vector<char> > field(H, vector<char>(W));
  vector<coord> coord_list(N+1);
  int sy, sx, gy, gx;

  for(int y = 0; y < H; y++){
    for(int x = 0; x < W; x++){
      cin >> field[y][x];

      if( field[y][x] != 'S' && field[y][x] != '.' ){
        coord_list[field[y][x] - '0'] = coord(y,x);
      }else if( field[y][x] == 'S' ){
        sy = y;
        sx = x;
      }
    }
  }

  int answer = 0;
  int x, y;

  for(int i = 1; i <= N; i++){
    gy = coord_list[i].first;
    gx = coord_list[i].second;

    priority_queue<data, vector<data>, greater<data> > que;
    vector< vector<bool> > check_field(H, vector<bool>(W));

    data d;
    d.dist = 0;
    d.cost = 0;
    d.y = sy;
    d.x = sx;

    que.push(d);

    while( !que.empty() ){
      d = que.top(); que.pop();
      y = d.y;
      x = d.x;
      check_field[y][x] = true;

      if( d.y == gy && d.x == gx ){
        sy = gy;
        sx = gx;
        answer += d.dist;
        break;
      }
      if( isInside( y, x+1 ) && !check_field[y][x+1] && field[y][x+1] != 'X'){
        data nd;
        nd.y = y;
        nd.x = x+1;
        nd.dist = d.dist + 1;
        nd.cost = nd.dist + abs( gy - nd.y ) + abs( gx - nd.x );
        que.push(nd);
      }
      if( isInside( y+1, x ) && !check_field[y+1][x] && field[y+1][x] != 'X'){
        data nd;
        nd.y = y+1;
        nd.x = x;
        nd.dist = d.dist + 1;
        nd.cost = nd.dist + abs( gy - nd.y ) + abs( gx - nd.x );
        que.push(nd);
      }
      if( isInside( y, x-1 ) && !check_field[y][x-1] && field[y][x-1] != 'X'){
        data nd;
        nd.y = y;
        nd.x = x-1;
        nd.dist = d.dist + 1;
        nd.cost = nd.dist + abs( gy - nd.y ) + abs( gx - nd.x );
        que.push(nd);
      }
      if( isInside( y-1, x ) && !check_field[y-1][x] && field[y-1][x] != 'X'){
        data nd;
        nd.y = y-1;
        nd.x = x;
        nd.dist = d.dist + 1;
        nd.cost = nd.dist + abs( gy - nd.y ) + abs( gx - nd.x );
        que.push(nd);
      }
    }
  }

  cout << answer << endl;
  return 0;
}
