#include <iostream>
#include <cstdio>

using namespace std;

int parent[150010];
int rankh[150010];

void init( int n ){
  for(int i = 0; i < n; i++){
    parent[i] = i;
    rankh[i] = 0;
  }
}

int find( int x ){
  if( parent[x] == x ){
    return x;
  }else{
    return parent[x] = find( parent[x] );
  }
}

void unite( int x, int y ){
  x = find(x);
  y = find(y);

  if( x == y ) return;

  if( rankh[x] < rankh[y] ){
    parent[x] = y;
  }else{
    parent[y] = x;
    if( rankh[x] == rankh[y] ) rankh[x]++;
  }
}

bool same( int x, int y ){
  return find(x) == find(y);
}

int main(){
  int N, K;

  cin >> N >> K;

  init( N * 3 );

  int ans = 0;
  int t, x, y;
  for(int i = 0; i < K; i++){
    /* cinだと遅すぎてTLE */
    scanf("%d %d %d", &t, &x, &y );

    x--;
    y--;

    if( x < 0 || N <= x || y < 0 || N <= y ){
      ans++;
      continue;
    }

    if( t == 1 ){
      if( same( x, y + N ) || same( x, y + 2 * N ) ){
        ans++;
      }else{
        unite( x, y );
        unite( x + N, y + N );
        unite( x + N * 2, y + N * 2 );
      }
    }else{
      if( same( x, y ) || same( x, y + 2 * N ) ){
        ans++;
      }else{
        unite( x, y + N );
        unite( x + N, y + 2 * N );
        unite( x + 2 * N, y );
      }
    }
  }

  printf("%d\n", ans );
}
