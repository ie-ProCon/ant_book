#include <sys/time.h> 
#include <stdlib.h>   // for exit, EXIT_FAILURE
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <queue>

double get_dtime(void);
std::vector<std::string> read_file(const std::string filename); 
template<typename T> void show_input(const std::vector<T>& data);
std::vector<char> string2charvector(const std::string& str);
std::string cin_line();
void solve(void);
void init_maze(std::vector<std::string> input_lines);
void init_distance_field(void);
int get_answer(void);

const int INF = 1000000000;
const char START_CHAR = 'S';
const char GOAL_CHAR  = 'G';
//typedef std::pair<int, int> P;
const int dx[4] = {1, 0, -1, 0}; 
const int dy[4] = {0, 1, 0, -1}; 

int sx, sy;
int gx, gy;
std::vector<std::vector<char> > maze_field;
std::vector<std::vector<int> >  distance_field;

int main(int argc, char* argv[]) {
    const std::string filename = argv[1];
    std::vector<std::string> str_vec = read_file(filename);
    init_maze(str_vec);
    init_distance_field();
    show_input(str_vec);
    solve();
    return 0;
}


void solve(void) {
    double s = 0;
    double e = 0;
    std::cout << "----------------------------[ O(4*N*M) ]\n";
    s = get_dtime();
    int ans = get_answer();
    e = get_dtime();
    std::cout << "A. " << ans << "\n";
    std::cout << "TIME : " << e - s << " msec\n";
    std::cout << "----------------------------[ O(4*N*M) ]\n";
}

// (sx, sy) -> (gx, gy)
// impossible is INF
int get_answer(void) {
    std::queue<std::pair<int, int> > que;
    const size_t y_max = maze_field.size();
    const size_t x_max = maze_field[0].size();
    que.push(std::pair<int, int>(sx, sy)); 
    distance_field[sy][sx] = 0;
    while (que.size()) {
        std::pair<int, int> pair = que.front(); 
        que.pop();
        if (pair.first == gx && pair.second == gy) {
            break; 
        }
        for (int i = 0; i < 4; i++) {
            int x_next = pair.first + dx[i];
            int y_next = pair.second + dy[i]; 
            bool x_inside = (0 <= x_next) && (x_next < x_max);
            bool y_inside = (0 <= y_next) && (y_next < y_max);
            if (!x_inside || !y_inside) {
                continue; 
            }
            bool not_wall = maze_field[y_next][x_next] != '#';
            bool yet_visited = distance_field[y_next][x_next] == INF;
            if (not_wall && yet_visited) {
                que.push(std::pair<int, int>(x_next, y_next)); 
                int prev_distance = distance_field[pair.second][pair.first]; 
                distance_field[y_next][x_next] = prev_distance + 1;
            }
        }
    }
    int ans = distance_field[gy][gx];
    return ans;
}

void init_distance_field(void) {
    size_t y_max = maze_field.size();
    size_t x_max = maze_field[0].size();
    for (int y = 0; y < y_max; y++) {
        std::vector<int> row;
        for (int x = 0; x < x_max; x++) {
            row.push_back(INF);
            char c = maze_field[y][x];
            if (c == START_CHAR) {
                sx = x;
                sy = y;
            }
            if (c == GOAL_CHAR) {
                gx = x;
                gy = y;
            }
        }
        distance_field.push_back(row);
    }
}

void init_maze(std::vector<std::string> input_lines) {
    std::vector<std::string>::iterator itr = input_lines.begin();
    while (itr != input_lines.end()) {
        std::vector<char> char_vec = string2charvector(*itr);
        maze_field.push_back(char_vec);
        itr++; 
    }
}

double get_dtime(void) {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    // ミリ秒を計算
    return ((double)(tv.tv_sec)*1000 + (double)(tv.tv_usec)*0.001);
}

std::vector<std::string> read_file(const std::string filename) {
    std::vector<std::string> contents;
    // contentsに詰める
    std::ifstream ifs(filename.c_str());
    if (!ifs) {
        std::cout << "ERROR\n";
        std::cout << "Can't open " << filename << "\n"; 
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (getline(ifs,line)) {
        contents.push_back(line); 
    }
    return contents;
}

template<typename T> void show_input(const std::vector<T>& data) {
    size_t N = data.size();
    size_t M = data[0].size();
    std::cout << "M = X_MAX = " << M << "\n";
    std::cout << "N = Y_MAX = " << N << "\n";
    std::cout << "START = (" << sx << "," << sy << ")\n";
    std::cout << "GOAL  = (" << gx << "," << gy << ")\n";
    for (size_t i = 0; i < N; i++) {
        std::cout << data[i] << "\n";
    }
}

std::vector<char> string2charvector(const std::string& str) {
   std::string::const_iterator itr = str.begin();
   std::vector<char> ret_vec;
    while (itr != str.end()) {
        const char tmp = *itr;
        ret_vec.push_back(tmp);
        itr++;
    }
    return ret_vec;
}



