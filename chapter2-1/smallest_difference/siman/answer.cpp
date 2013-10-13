#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

vector<string> split(string s, char del = ' '){
  vector<string> res;
  replace(s.begin(),s.end(),del,' ');
  stringstream ss(s);
  string elem;
  for(int i = 0; ss >> elem; i++){
    res.push_back(elem);
  }
  return res;
}

int toInteger(string str){
  return atoi(str.c_str());
}

int to_i(char val){
  return int(val-'0');
}

int unit[5] = { 1, 10, 100, 1000, 10000 };

int main(){
  ll n, b, size;
  string line, s1, s2;
  ll min_diff, diff, v1, v2;

  cin >> n; cin.ignore();

  for(int i = 0; i < n; i++){
    min_diff = 1000000000;
    map<string, bool> check_list;
    getline(cin, line);
    vector<string> data = split(line);
    size = data.size();
    b = size/2;

    for(int k = 0; k < size; k++){
      string s = data[k];
      check_list[s] = true;
    }

    if( size == 10 ){
      cout << 247 << endl;
      continue;
    }else if( size == 9 ){
      if( !check_list["0"] ){
        cout << 2469 << endl;
        continue;
      }else if( !check_list["1"] ){
        cout << 10469 << endl;
        continue;
      }else if( !check_list["2"] || !check_list["8"] ){
        cout << 469 << endl;
        continue;
      }else if( !check_list["3"] || !check_list["7"] ){
        cout << 369 << endl;
        continue;
      }else if( !check_list["4"] || !check_list["6"] ){
        cout << 359 << endl;
        continue;
      }else if( !check_list["5"] ){
        cout << 358 << endl;
        continue;
      }else{
        cout << 1469 << endl;
        continue;
      }
    }

    do {
      if( (b > 1 || size == 3 ) && (data[0] == "0" || data[b] == "0") ) continue;
      v1 = 0;
      v2 = 0;

      for(int j = 0; j < size; j++){
        if( j < b ){
          v1 = v1 * 10 + to_i(data[j][0]);
        }else{
          v2 = v2 * 10 + to_i(data[j][0]);
        }
      }

      diff = abs( v1 - v2 );
      min_diff = min( min_diff, diff );

    } while( next_permutation( data.begin(), data.end() ));

    cout << min_diff << endl;
  }
}
