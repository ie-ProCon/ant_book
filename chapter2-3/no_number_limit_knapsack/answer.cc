#include <stdio.h>
#include <iostream>
#include <vector>

void input(void);
int get_ans1(void);
int get_ans2(void);
int get_ans3(void);

const int MAX_Vi = 100;   // one item
const int MAX_Wi = 100;   // one item
const int MAX_N  = 100;
const int MAX_W  = 10000; // knapsack max
const int INF = MAX_W+1;
std::vector<std::vector<int> > dp;
std::vector<int> dp2;

int N;
std::vector<std::pair<int, int> > ITEM;
int W;

int main(void) {
    input();
    //int ans = get_ans1();
    //int ans = get_ans2();
    int ans = get_ans3();
    std::cout << ans << std::endl;
    return 0;
}

int get_ans3(void) {
    dp2 = std::vector<int>(W+1, 0); 
    for (int i = 0; i < N; i++) {
        int weight = ITEM[i].first;
        int value  = ITEM[i].second;
        for (int j = weight; j <= W; j++) {
            int non_put_case = dp2[j];
            int put_case     = dp2[j-weight] + value;
            dp2[j] = std::max(non_put_case, put_case); 
        }
    }
    return dp2[W];
}

int get_ans2(void) {
    dp = std::vector<std::vector<int> >(N+1, std::vector<int>(W+1, 0));
    for (int i = 0; i < N; i++) {
        int weight = ITEM[i].first;
        int value  = ITEM[i].second;
        for (int j = 0; j <= W; j++) {
            if (j < weight) {
                dp[i+1][j] = dp[i][j]; 
                continue;
            }
            int non_put_case = dp[i][j];
            int put_case     = dp[i+1][j-weight] + value;
            dp[i+1][j] = std::max(non_put_case, put_case);
        }
    }
    return dp[N][W];
}

int get_ans1(void) {
    dp = std::vector<std::vector<int> >(N+1, std::vector<int>(W+1, 0));
    for (int i = 0; i < N; i++) {
        int weight = ITEM[i].first;
        int value  = ITEM[i].second;
        for (int j = 0; j <= W; j++) {
            for (int k = 0; k*weight <= j; k++) {
                int sum_w = k * weight;
                int sum_v = k * value;

                int non_put_case = dp[i+1][j];
                int put_case     = dp[i][j-sum_w] + sum_v;
                dp[i+1][j] = std::max(non_put_case, put_case);
            }
        }
    }
    return dp[N][W];
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
