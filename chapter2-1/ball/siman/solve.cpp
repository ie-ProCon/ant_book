#include <iostream>

using namespace std;

int main(){
  int n, num, right, left;
  bool flag;

  cin >> n;

  for(int i = 0; i < n; i++){
    right = 0;
    left = 0;
    flag = true;

    for(int j = 0; j < 10; j++){
      cin >> num;

      if(right < num){
        right = num;
      }else if(left < num){
        left = num;
      }else{
        flag = false;
      }
    }

    if(flag){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  return 0;
}
