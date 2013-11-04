#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NONE = 0;
const int WHITE = 1;
const int BLACK = 2;

const int MAX_V = 1000;

void test_case0();
void test_case1();

struct edge {
  int to; 
  int cost;
};

struct node_data {
  int id; 
  int color;
  vector<edge> edge_list;
};

 vector<node_data> node_list(MAX_V);

bool dfs( int id, int color ){
  node_list[id].color = color;

  int size = node_list[id].edge_list.size();

  for(int i = 0; i < size; i++ ){
    edge e = node_list[id].edge_list[i];
    node_data other = node_list[e.to];

    if( other.color == NONE ){
      if( !dfs( other.id, ( node_list[id].color == WHITE )? BLACK : WHITE ) ) return false;
    }else if( other.color == node_list[id].color ){
      cout << "NO" << endl;
      return false;
    }
  }

  return true;
};

string solve( vector<string> graph ){
  int size = graph.size();

  for(int i = 0; i < size; i++){
    node_data node;
    node.id = i;
    node.color = NONE;
    for(int j = 0; j < size; j++){
      if( graph[i][j] == 'Y' ){
        edge e;
        e.to = j;
        node.edge_list.push_back(e);
      }
    }
    node_list[i] = node;
  }


  if( dfs( 0, WHITE ) ){
    return "YES";
  }else{
    return "NO";
  }
}

int main(){

  test_case0();
  test_case1();
  return 0;
}

void test_case0(){
  string test_case[] = {
    "NYY",
    "YNY",
    "YYN"
  };

  vector<string> graph_info( test_case, test_case + ( sizeof(test_case) / sizeof( string ) ));

  string expected = "NO";
  string recieved = solve( graph_info );

  if( recieved == expected ){
    printf("Test Case #0...PASSED\n");
  }else{
    printf("Test Case #0...FAILED\n");
    printf("\tExpected: %s\n", expected.c_str());
    printf("\tRecieved: %s\n", recieved.c_str());
  }
}

void test_case1(){
  string test_case[] = {
    "NYNY",
    "YNYN",
    "NYNY",
    "YNYN"
  };

  vector<string> graph_info( test_case, test_case + ( sizeof(test_case) / sizeof( string ) ));

  string expected = "YES";
  string recieved = solve( graph_info );

  if( recieved == expected ){
    printf("Test Case #1...PASSED\n");
  }else{
    printf("Test Case #1...FAILED\n");
    printf("\tExpected: %s\n", expected.c_str());
    printf("\tRecieved: %s\n", recieved.c_str());
  }
}
