#include <iostream>

using namespace std;

#define MAX_N 1000

int parent[MAX_N]; // 親の番号
int height[MAX_N]; // 木の高さ

// n要素で初期化
void init(int n){
  for(int i = 0; i < n; i++){
    parent[i] = i;
    height[i] = 0;
  }
}

// 木の根を求める
int find(int x){
  if(parent[x] == x){
    return x;
  }else{
    return parent[x] = find(parent[x]);
  }
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if( x == y ) return;

  if(height[x] < height[y]){
    parent[x] = y;
  }else{
    parent[y] = x;
    if(height[x] == height[y]) height[x]++;
  }
}

/*
 * 同じグループに属しているかどうかを調べる
 */
bool same(int x, int y){
  return find(x) == find(y);
}

int main(){
  init(MAX_N);

  return 0;
}

