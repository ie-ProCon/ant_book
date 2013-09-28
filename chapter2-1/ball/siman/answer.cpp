#include <iostream>
#include <string.h>

using namespace std;

int ball_list[10];
int right_list[10];
int left_list[10];

bool flag;

void dfs(int right, int left){
  int count = right + left;

  if(count == 10){
    flag = true;
  }else{
    if(right == 0 || right_list[right-1] < ball_list[count]){
      if(right == 0){
        right_list[0] = ball_list[count];
      }else{
        right_list[right] = ball_list[count];
      }
      dfs(right+1, left);
    }
    if(left == 0 || left_list[left-1] < ball_list[count]){
      if(left == 0){
        left_list[0] = ball_list[count];
      }else{
        left_list[left] = ball_list[count];
      }
      dfs(right, left+1);
    }
  }
}

int main(){
  int n;

  cin >> n;

  for(int i = 0; i < n; i++){
    flag = false;
    memset(right_list, 0, sizeof(right_list));
    memset(left_list, 0, sizeof(left_list));

    for(int j = 0; j < 10; j++){
      cin >> ball_list[j];
    }
    
    dfs(0, 0);

    if(flag){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  return 0;
}
