#include <iostream>
#include <vector>
#include <cmath>

void input(void);
std::vector<char> get_ans(void);
void show_vec(std::vector<char> ans);
int get_dic_min(void); 
bool min_left(int left, int right); 

int N;
std::vector<char> INPUT_STR;

int main(int argc,char* argv[]) {
    input();
    std::vector<char> ans = get_ans();    
    show_vec(ans);
    return 0;
}

std::vector<char> get_ans(void) {
    std::vector<char> ans(N);
    for (int i = 0; i < N; i++) {
        int index = std::abs(get_dic_min());
        ans[i] = INPUT_STR[index];
    }
    return ans;
}

int get_dic_min(void) {
    static int left  = 0;
    static int right = 1-N;
    int abs_r = std::abs(right);
    if (0 <= left+right) {
        return left; 
    }
    char lc = INPUT_STR[left];
    char rc = INPUT_STR[abs_r];
    if (lc == rc) {
        int& index = (min_left(left+1, right+1))? left : right;
        return index++;
    }
    int& index = (lc < rc)? left : right;
    return index++;
}

bool min_left(int left, int right) {
     if (0 <= left+right) {
        return true; 
    }
    int abs_r = std::abs(right);
    char lc = INPUT_STR[left];
    char rc = INPUT_STR[abs_r];
    if (lc == rc) {
        return min_left(left+1, right+1); 
    }
    return lc < rc; 
}

void input(void) {
    std::cin >> N;
    INPUT_STR = std::vector<char>(N);
    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> INPUT_STR[i];
    }
}

void show_vec(std::vector<char> ans) {
    for (int i = 0; i < N; i++) {
        if (i%80 == 0 && i!= 0) {
            std::cout << std::endl;
        }
        std::cout << ans[i]; 
    }
}
