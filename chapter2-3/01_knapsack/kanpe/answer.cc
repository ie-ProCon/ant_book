#include <stdio.h>
#include <iostream>
#include <vector>

void input(void);
int solve(void);
int recursion(int i, int j);

const int MAX_N = 100;
const int MAX_W = 10000;
std::vector<std::vector<int> > dp;

int N;
std::vector<std::pair<int, int> > ITEM;
int W;

int main(void) {
    input();
    solve();
    return 0;
}

int recursion(int index, int rest_w) {
    if (N <= index) {
        return 0; 
    }

    if (-1 < dp[index][rest_w]) {
        return dp[index][rest_w]; 
    }

    int weight = ITEM[index].first;
    if (rest_w < weight) {
        return dp[index][rest_w] = recursion(index+1, rest_w);
    }

    int value = ITEM[index].second;
    int put_case     = recursion(index+1, rest_w-weight) + value;
    int non_put_case = recursion(index+1, rest_w);

    return dp[index][rest_w] = std::max(put_case, non_put_case);
}

int solve(void) {
    dp = std::vector<std::vector<int> >(N, std::vector<int>(W+1, -1));
    int start_index = 0;
    int answer = recursion(start_index, W);
    std::cout << answer << std::endl;
}

void input(void) {
    std::cin >> N;
    ITEM = std::vector<std::pair<int, int> >(N);
    for (int i = 0; i < N; i++) {
        int w,v;
        std::cin >> w >> v;
        ITEM[i] = std::pair<int, int>(w, v);
    }
    std::cin >> W;
}
