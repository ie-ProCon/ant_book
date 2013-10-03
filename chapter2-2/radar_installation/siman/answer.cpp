#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef pair<int, int> coord;
typedef pair<double, coord> info;
const double EPS = 1e-6;

bool isInside(double x1, double y1, double x2, double y2, int d){
  double dx = x1 - x2;
  double dy = y1 - y2;

  return (sqrt( dx*dx + dy*dy ) <= d + EPS);
}

bool isReach( int y, int d ){
  return ( d - y >= 0 );
}

double searchPoint( int y, int x, int d ){
  return x + sqrt( (double)(d*d - y*y) );
}

int main(){
  int n, d, x, y, count;
  int case_num = 1;
  double point;

  while(true){

    cin >> n >> d;

    if( n == 0 && d == 0 ) break;

    vector<info> info_list;

    for(int i = 0; i < n; i++){
      cin >> x >> y; 
      point = searchPoint( y, x, d );

      info_list.push_back(info(point, coord(x, y)));
    }

    sort(info_list.begin(), info_list.end());

    count = 0;
    int i = 0;

    while( i < n ){
      info data = info_list[i++];
      count++;

      if( data.second.second > d ){
        count = -1;
        break;
      }

      while( i < n ){
        coord pos = info_list[i].second;
        if( isInside( pos.first, pos.second, data.first, 0, d ) ){
          i++;
        }else{
          break;
        }
      }
    }

    printf("Case %d: %d\n", case_num, count);
    case_num++;
  }
  return 0;
}
