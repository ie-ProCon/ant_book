#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

priority_queue<double> stripes;

int main(){
  int n;
  double size;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> size;
    stripes.push(size);
  }

  while(stripes.size() > 1){
    double m1 = stripes.top(); stripes.pop();
    double m2 = stripes.top(); stripes.pop();

    stripes.push(2.0 * sqrt( m1 * m2 ) );
  }

  printf("%.3f\n", stripes.top());
  return 0;
}
