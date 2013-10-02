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
void solve(void);
std::vector<std::vector<char> > get_maze(std::vector<std::string> input_lines);
void init_distance_field(std::vector<std::vector<char> > maze);
int get_answer(void);
std::vector<char> string2charvector(const std::string& str);

const int INF = 1000000000;
const char START_CHAR = 'S';
const char GOAL_CHAR  = 'G';
const char WALL_CHAR  = '#';
const int WALL  = -1;
const int START = 0;
const int dx[4] = {1, 0, -1, 0}; 
const int dy[4] = {0, 1, 0, -1}; 

//int sx, sy;
//int gx, gy;
std::pair<int, int> start;
std::pair<int, int> goal;
std::vector<std::vector<int> >  distance_field;

int main(int argc, char* argv[]) {
    const std::string filename = argv[1];
    std::vector<std::string> str_vec = read_file(filename);
    std::vector<std::vector<char> > maze = get_maze(str_vec);
    init_distance_field(maze);
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
// if impossible, return INF
int get_answer(void) {
    std::queue<std::pair<int, int> > que;
    que.push(start);
    const size_t y_max = distance_field.size();
    const size_t x_max = distance_field[0].size();
    const int sx = start.first;
    const int sy = start.second;
    const int gx = goal.first;
    const int gy = goal.second;
    while (que.size()) {
        std::pair<int, int> cur_pos = que.front(); 
        que.pop();
        int cx = cur_pos.first;
        int cy = cur_pos.second;
        if (cx == gx && cy == gy) {
            break; 
        }
        for (int i = 0; i < 4; i++) {
            int x_next = cur_pos.first + dx[i];
            int y_next = cur_pos.second + dy[i]; 
            bool x_inside = (0 <= x_next) && (x_next < x_max);
            bool y_inside = (0 <= y_next) && (y_next < y_max);
            if (!x_inside || !y_inside) {
                continue; 
            }
            bool not_wall = distance_field[y_next][x_next] != WALL;
            bool yet_visited = distance_field[y_next][x_next] == INF;
            if (not_wall && yet_visited) {
                std::pair<int, int> next_pos = std::pair<int, int>(x_next, y_next);
                que.push(next_pos); 
                int prev_distance = distance_field[cur_pos.second][cur_pos.first]; 
                distance_field[y_next][x_next] = prev_distance + 1;
            }
        }
    }
    int ans = distance_field[gy][gx];
    return ans;
}

void init_distance_field(std::vector<std::vector<char> > maze) {
    size_t y_max = maze.size();
    size_t x_max = maze[0].size();
    for (int y = 0; y < y_max; y++) {
        std::vector<int> row;
        for (int x = 0; x < x_max; x++) {
            char c = maze[y][x];
            if (c == WALL_CHAR) {
                row.push_back(WALL);
                continue; 
            }
            if (c == START_CHAR) {
                start = std::pair<int, int>(x, y);
                row.push_back(START);
                continue;
            }
            if (c == GOAL_CHAR) {
                goal = std::pair<int, int>(x, y);
            }
            row.push_back(INF);
        }
        distance_field.push_back(row);
    }
}

std::vector<std::vector<char> > get_maze(std::vector<std::string> input_lines) {
    std::vector<std::vector<char> > maze_field;
    std::vector<std::string>::iterator itr = input_lines.begin();
    while (itr != input_lines.end()) {
        std::vector<char> char_vec = string2charvector(*itr);
        maze_field.push_back(char_vec);
        itr++; 
    }
    return maze_field;
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
    std::cout << "START = (" << start.first << "," << start.second << ")\n";
    std::cout << "GOAL  = (" << goal.first << "," << goal.second << ")\n";
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



