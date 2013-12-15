#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

ll solve( ll a, ll b ){
  ll prime_num = b - a;
  bool prime_check[(int)floor(sqrt(b))+1];
  bool section_prime_check[prime_num];

  memset( prime_check, true, sizeof(prime_check) );
  memset( section_prime_check, true, sizeof(section_prime_check) );

  if( a < 2 ){
    section_prime_check[0] = false;
    prime_num--;
  }

  for(int i = 2; i * i < b; i++ ){
    if( prime_check[i] ){
      for(int j = 2 * i; (ll)(j * j) < b; j+=i ){
        prime_check[j] = false;
      }
      for(int j = max( 2LL, (a+i-1)/i) * i; j < b; j+=i ){
        if( j != i && section_prime_check[j-a] ){
          section_prime_check[j-a] = false;
          prime_num--;
        }
      }
    }
  }

  return prime_num;
}

void test_case1(){
  ll a = 22;
  ll b = 37;
  ll expected = 3;
  ll recieved = solve( a, b );
  if( recieved == expected ){
    printf("Test Case #1...PASSED\n");
  }else{
    printf("Test Case #1...FAILED\n");
    printf("\tExpected: %lld\n", expected );
    printf("\tRecieved: %lld\n", recieved );
  }
}

void test_case2(){
  ll a = 1;
  ll b = 100;
  ll expected = 25;
  ll recieved = solve( a, b );
  if( recieved == expected ){
    printf("Test Case #2...PASSED\n");
  }else{
    printf("Test Case #2...FAILED\n");
    printf("\tExpected: %lld\n", expected );
    printf("\tRecieved: %lld\n", recieved );
  }
}

void test_case3(){
  ll a = 100;
  ll b = 20000;
  ll expected = 2237;
  ll recieved = solve( a, b );
  if( recieved == expected ){
    printf("Test Case #3...PASSED\n");
  }else{
    printf("Test Case #3...FAILED\n");
    printf("\tExpected: %lld\n", expected );
    printf("\tRecieved: %lld\n", recieved );
  }
}

void test_case4(){
  ll a = 300;
  ll b = 100000;
  ll expected = 9530;
  ll recieved = solve( a, b );
  if( recieved == expected ){
    printf("Test Case #4...PASSED\n");
  }else{
    printf("Test Case #4...FAILED\n");
    printf("\tExpected: %lld\n", expected );
    printf("\tRecieved: %lld\n", recieved );
  }
}

void test_case5(){
  ll a = 1;
  ll b = 3;
  ll expected = 1;
  ll recieved = solve( a, b );
  if( recieved == expected ){
    printf("Test Case #5...PASSED\n");
  }else{
    printf("Test Case #5...FAILED\n");
    printf("\tExpected: %lld\n", expected );
    printf("\tRecieved: %lld\n", recieved );
  }
}

int main(){
  test_case1();
  test_case2();
  test_case3();
  test_case4();
  test_case5();
  return 0;
}
