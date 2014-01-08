#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int flip[20][20];
int origin_flip[20][20];
bool answer_stamp[20][20];
bool stamp[20][20];
int dy[5] = { 0, 1, 0, -1, 0 };
int dx[5] = { 1, 0, -1, 0, 0 };

void flip_rot(int y, int x){
  int ny, nx;
  stamp[y][x] = true;
  for(int i = 0; i < 5; i++){
    ny = y + dy[i];
    nx = x + dx[i];
    flip[ny][nx] ^= 1;
  }
}

int main(){
  int M, N;
  int min_rot = INT_MAX;
  cin >> M >> N;

  for(int y = 1; y <= M; y++){
    for(int x = 1; x <= N; x++){
      cin >> origin_flip[y][x];
    }
  }

  int size = (1 << 15) - 1;
  bool success;
  int rot_cnt;

  for(int i = 0; i < size; i++){
    memcpy( flip, origin_flip, sizeof(origin_flip) );
    memset( stamp, false, sizeof(stamp) );
    success = true;
    rot_cnt = 0;

    for(int j = 0; j < N; j++){
      if(( i >> j ) & 1){
        flip_rot( 1, N-j );
        rot_cnt++;
      }
    }

    for(int y = 2; y <= M; y++){
      for(int x = 1; x <= N; x++){
        if( flip[y-1][x] ){
          flip_rot( y, x );
          rot_cnt++;
        }
      }
    }

    for(int x = 1; x <= N; x++){
      if( flip[M][x] ) success = false;
    }
    if( success && min_rot > rot_cnt ){
      min_rot = rot_cnt;
      memcpy( answer_stamp, stamp, sizeof(stamp) );
    }
  }

  if( min_rot != INT_MAX ){
    for(int y = 1; y <= M; y++){
      for(int x = 1; x <= N; x++){
        cout << answer_stamp[y][x];
        if( x != N ){
          cout << " ";
        }
      }
      cout << endl;
    }
  }else{
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
