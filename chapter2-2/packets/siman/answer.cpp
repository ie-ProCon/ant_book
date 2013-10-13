#include <iostream>
#include <algorithm>

using namespace std;

int count_list[6];

int pack_six(){
  int num = 0;
  num = count_list[5];
  count_list[5] = 0;

  return num;
}

int pack_five(){
  int num = 0;
  num = count_list[4];
  count_list[0] = max(0, count_list[0] - num * 11);

  return num;
}

int pack_four(){
  int num = 0;
  num = count_list[3];

  if( num > 0 ){
    if( count_list[1] % 5 == 0 ){
      int tc = count_list[1] / 5;
      count_list[1] = max( 0, count_list[1] - min(tc, num) * 5 );
      count_list[0] = max( 0, count_list[0] - max( 0, num-tc ) * 20);
    }else{
      int tc = count_list[1] / 5;
      int mc = count_list[1] % 5;
      if( tc > 0 ){
        if( num > tc ){
          count_list[1] = max( 0, count_list[1] - tc * 5);
          count_list[0] = max( 0, count_list[0] - (num-tc-1) * 20);
          count_list[1] = max( 0, count_list[1] - mc);
          count_list[0] = max( 0, count_list[0] - ( 20 - mc*4 ));
        }else{
          count_list[1] = max( 0, count_list[1] - num * 5);
        }
      }else{
        count_list[1] = 0;
        count_list[0] = max( 0, count_list[0] - (num-tc-1) * 20);
        count_list[0] = max( 0, count_list[0] - ( 20 - mc*4 ));
      }
    }
  }

  return num;
}

int pack_three(){
  int num = 0, count;
  num = count_list[2] / 4;
  count_list[2] %= 4;

  switch(count_list[2]){
    case 1:
      count = min( count_list[1], 5 );
      count_list[1] -= count;
      count_list[0] = max( 0, count_list[0] - ( 27 - 4 * count ));
      num++;
      break;
    case 2:
      count = min( count_list[1], 3 );
      count_list[1] -= count;
      count_list[0] = max( 0, count_list[0] - ( 18 - 4 * count ));
      num++;
      break;
    case 3:
      if( count_list[1] > 0 ){
        count_list[1]--;
        count_list[0] = max(0, count_list[0] - 5);
      }else{
        count_list[0] = max(0, count_list[0] - 9);
      }
      num++;
      break;
    default:
      break;
  }

  return num;
}

int pack_two(){
  int num = 0;
  num = count_list[1] / 9;
  count_list[1] %= 9;
  if( count_list[1] > 0 ){
    count_list[0] = max(0, count_list[0] - (36 - count_list[1] * 4));
    num++;
  }

  return num;
}

int pack_one(){
  if( count_list[0] % 36 == 0 ){
    return count_list[0] / 36;
  }else{
    return count_list[0] / 36 + 1;
  }
}

int main(){
  int total_count, answer;

  while(true){
    total_count = 0;
    answer = 0;
    for(int i = 0; i < 6; i++){
      cin >> count_list[i];
      total_count += count_list[i];
    }

    if( total_count == 0 ) break;

    answer += pack_six();
    answer += pack_five();
    answer += pack_four();
    answer += pack_three();
    answer += pack_two();
    answer += pack_one();

    cout << answer << endl;
  }

  return 0;
}
