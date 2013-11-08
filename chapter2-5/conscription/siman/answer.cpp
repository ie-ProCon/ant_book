#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10010;
const int MAX_M = 10010;

int parent[MAX_N+MAX_M];
int height[MAX_N+MAX_M];

void union_init( int n ){
  for(int i = 0; i < n; i++){
    parent[i] = i;
    height[i] = 0;
  }
}

int find( int n ){
  if( parent[n] == n ){
    return n;
  }else{
    return parent[n] = find(parent[n]);
  }
}

void unite( int n, int m ){
  n = find(n);
  m = find(m);

  if( n == m ){
    return;
  }else{
    if( height[n] < height[m] ){
      parent[n] = m;
    }else{
      parent[m] = n;
      if( height[n] == height[m] ){
        height[n]++;
      }
    }
  }
}

bool same( int n, int m ){
  return find(n) == find(m);
}

struct edge {
  int n, m;
  int cost;
};

bool comp( const edge &e1, const edge &e2 ){
  return e1.cost < e2.cost;
}


int solve(){

  int n, m, num;
  cin >> n >> m >> num;
  vector<edge> edge_list(num);

  union_init( n+m );

  for(int i = 0; i < num; i++){
    edge e;
    scanf("%d %d %d", &e.n, &e.m, &e.cost );
    e.m += n;
    e.cost *= -1;
    edge_list[i] = e;
  }

  int total_cost = 0;

  sort( edge_list.begin(), edge_list.end(), comp );

  for(int i = 0; i < num; i++){
    edge e = edge_list[i];

    if( same( e.n, e.m ) ) continue;

    unite( e.n, e.m );

    total_cost += e.cost;
  }

  cout << (n+m) * 10000 + total_cost << endl;

  return 0;
}

int main(){
  int cnt;
  cin >> cnt;

  for(int i = 0; i < cnt; i++){
    solve();
  }

  return 0;
}
