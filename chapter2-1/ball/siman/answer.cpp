#include <iostream>
#include <string.h>

using namespace std;

int ball_list[10];
int right_val;      
int left_val;

bool flag;

void dfs(int right, int left){
  int count = right + left;
  int num = ball_list[count];

  if(flag) return;

  if(count == 10){
    flag = true;
  }else{
    if(right_val < ball_list[count]){
      right_val = num;
      dfs(right+1, left);
    }
    if(left_val < ball_list[count]){
      left_val = num;
      dfs(right, left+1);
    }
  }
}

int main(){
  int n;

  cin >> n;

  for(int i = 0; i < n; i++){
    flag = false;
    right_val = 0;
    left_val = 0;

    for(int j = 0; j < 10; j++){
      cin >> ball_list[j];
    }
    
    dfs(0, 0);

    cout << ((flag)? "YES" : "NO") << endl;
  }

  return 0;
}
