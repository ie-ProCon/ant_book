#include <iostream>
#include <vector>
#include <map> 

using namespace std;

int pascal[10][10];
int N, SUM;
vector<int> answer;
map<int, bool> check_list;
bool flag = false;

void init_pascal(int n){
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= i; j++){
      if( 0 <= j - 1 ){
        pascal[i][j] += pascal[i-1][j-1];
      }
      if( j < i ){
        pascal[i][j] += pascal[i-1][j];
      }
    }
  }
}

void dfs(vector<int> &data, int index){
  if(flag) return;

  if( index != N ){
    for(int i = 1; i <= N; i++){
      if( !check_list[i] ){
        check_list[i] = true;
        data[index] = i;
        dfs( data, index+1 );
        check_list[i] = false;
      }
    }
  }else{
    int sum = 0;
    for(int j = 0; j < N; j++){
      sum += data[j] * pascal[N-1][j];
    }
    if( sum == SUM ){
      answer = data;
      flag = true;
    }
  }

  return;
}


int main(){
  memset( pascal, 0, sizeof(pascal));
  pascal[0][0] = 1;
  cin >> N >> SUM;

  init_pascal( N );

  vector<int> data(N);
  dfs( data, 0 );

  for(int i = 0; i < N; i++){
    cout << answer[i];
    if( i != N-1 ){
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}
