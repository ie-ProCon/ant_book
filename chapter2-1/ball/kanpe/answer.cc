#include <iostream>
#include <vector>

int read_line_sum(void);
std::vector<int> read_ball_line(void);
std::string solve1(const std::vector<int>& data);
std::string solve2(const std::vector<int>& data);
bool is_ok(const std::vector<int>& data, int comb_num);

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0033
// BALL
const int BALL_NUM = 10;
const std::string YES = "YES";
const std::string NO  = "NO";
const int LEFT  = 0;
const int RIGHT = 1;

int main() {
    int n = read_line_sum();
    for (int i = 0; i < n; i++) {
        std::vector<int> data = read_ball_line(); 
        std::string yes_no = solve1(data);
        std::cout << yes_no << std::endl;
    }
    return 0;
}

// full search
std::string solve1(const std::vector<int>& data) {
    int all_comb_sum = 1 << BALL_NUM;
    bool result = false;
    for (int i = 0; i < all_comb_sum; i++) {
        result |= is_ok(data, i); 
    }
    std::string ans = (result)? YES : NO;
    return ans;
}

// little fast
std::string solve2(const std::vector<int>& data) {
    int all_comb_sum = 1 << BALL_NUM;
    bool result = false;
    for (int i = 0; i < all_comb_sum; i++) {
        result = is_ok(data, i); 
        if (result) {
            return YES; 
        }
    }
    return NO;
}

bool is_ok(const std::vector<int>& data, int comb_num) {
    std::vector<int> lr_index(2);
    lr_index[LEFT]  = 0;
    lr_index[RIGHT] = 0;

    std::vector<std::vector<int> > lr_vec(2);
    lr_vec[LEFT]  = std::vector<int>(BALL_NUM);
    lr_vec[RIGHT] = std::vector<int>(BALL_NUM);
    for (int i = 0; i < BALL_NUM; i++) {
        int lr    = comb_num>>i & 1;
        int index = lr_index[lr]++;
        lr_vec[lr][index] = data[i];
        if (index < 1) {
            continue; 
        }
        int pre_value = lr_vec[lr][index-1];
        int cur_value = lr_vec[lr][index];
        if (cur_value < pre_value) {
            return false; 
        }
    }
    return true;
}

int read_line_sum() {
    int n;
    std::cin >> n;
    return n;
}

std::vector<int> read_ball_line() {
    std::vector<int> data(BALL_NUM);
    for (int i = 0; i < BALL_NUM; i++) {
        std::cin >> data[i]; 
    }
    return data;
}


