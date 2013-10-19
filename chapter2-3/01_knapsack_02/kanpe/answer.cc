#include <stdio.h>
#include <iostream>
#include <vector>

void input(void);
void solve(void);

const int MAX_Vi = 100;        // one item
const int MAX_Wi = 10000000;   // one item
const int MAX_N  = 100;
const int MAX_W  = 1000000000; // knapsack max
const int INF = MAX_W+1;
std::vector<std::vector<int> > dp;

int N;
std::vector<std::pair<int, int> > ITEM;
int W;

int main(void) {
    input();
    solve();
    return 0;
}

void solve(void) {
    dp = std::vector<std::vector<int> >(N+1, std::vector<int>(MAX_N*MAX_Vi+1, INF));
    dp[0][0] = 0;
    int j_max = MAX_N * MAX_Vi;
    for (int i = 0; i < N; i++) {
        int weight = ITEM[i].first;
        int value  = ITEM[i].second;
        for (int j = 0; j <= j_max; j++) {
            if (j < value) {
                dp[i+1][j] = dp[i][j];
                continue;
            }
            int non_put_case = dp[i][j];
            int put_case     = dp[i][j-value] + weight;
            dp[i+1][j] = std::min(non_put_case, put_case);
        }
    }

    int ans = 0;
    for (int j = 0; j <= j_max; j++) {
        if (dp[N][j] <= W) {
            ans = j; 
        }
    }

    std::cout << ans << std::endl;
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
