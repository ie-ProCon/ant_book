#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, R, point, index, count, val;

  while(true){
    cin >> R >> N;

    if( R == -1 && N == -1 ) break;
    vector<int> field; 
    count = 0;
    index = 0;

    for(int i = 0 ; i < N; i++){
      cin >> point;
      field.push_back(point);
    }

    sort(field.begin(), field.end());

    while( index < N ){
      val = field[index++];

      while( index < N && val + R >= field[index]) index++;

      val = field[index-1];

      while( index < N && val + R >= field[index]) index++;

      count++;
    }

    cout << count << endl;
  }
  return 0;
}
