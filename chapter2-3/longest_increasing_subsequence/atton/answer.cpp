/* Programming Contest Challange Book P.63
 * Longest Increasing Subsequence
 * ant book original problem
 */

#include<iostream>

#define MAX_N  10000010
#define INF    100000000

int a[MAX_N];
int dp[MAX_N];

int main(int argc, char const* argv[]) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::fill_n(dp, MAX_N, INF);
    for (int i = 0; i < n; i++) {
        *std::lower_bound(dp, dp+n, a[i]) = a[i];
    }

    std::cout << std::lower_bound(dp, dp+n, INF)-dp << std::endl;

    return 0;
}
