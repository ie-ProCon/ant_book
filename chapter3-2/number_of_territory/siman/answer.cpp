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
int W, H, N;
bool field[100][100];

int compress(int *x1, int *x2, int w ){
  vector<int> xs;

  for(int i = 0; i < N; i++){
    for(int d = -1; d <= 1; d++){
      int tx1 = x1[i] + d;
      int tx2 = x2[i] + d;
      if( 1 <= tx1 && tx1 <= w ) xs.push_back(tx1);
      if( 1 <= tx2 && tx2 <= w ) xs.push_back(tx2);
    }
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());

  for(int i = 0; i < N; i++){
    x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin() + 1;
    x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin() + 1;
  }

  return xs.size();
}

void show_field(){
  for(int y = 1; y <= H; y++){
    for(int x = 1; x <= W; x++){
      cout << (( field[y][x] )? '*' : '.');
    }
    cout << endl;
  }
}

int main(){
  scanf("%d %d %d", &W, &H, &N);
  int x1[N];
  int x2[N];
  int y1[N];
  int y2[N];

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < N; j++){
      switch(i){
        case 0:
          scanf("%d", &x1[j]);
          break;
        case 1:
          scanf("%d", &x2[j]);
          break;
        case 2:
          scanf("%d", &y1[j]);
          break;
        case 3:
          scanf("%d", &y2[j]);
          break;
      }
    }
  }

  memset( field, false, sizeof(field) );
  for(int i = 0; i < N; i++){
    for(int y = y1[i]; y <= y2[i]; y++){
      for(int x = x1[i]; x <= x2[i]; x++){
        field[y][x] = true;
      }
    }
  }
  show_field();

  W = compress( x1, x2, W );
  H = compress( y1, y2, H );

  cout << endl;
  memset( field, false, sizeof(field) );
  for(int i = 0; i < N; i++){
    for(int y = y1[i]; y <= y2[i]; y++){
      for(int x = x1[i]; x <= x2[i]; x++){
        field[y][x] = true;
      }
    }
  }
  show_field();

  for(int i = 0; i < N; i++){
    cout << x1[i] << " ";
  }
  cout << endl;

  for(int i = 0; i < N; i++){
    cout << x2[i] << " ";
  }
  cout << endl;

  for(int i = 0; i < N; i++){
    cout << y1[i] << " ";
  }
  cout << endl;

  for(int i = 0; i < N; i++){
    cout << y2[i] << " ";
  }
  cout << endl;

  return 0;
}
