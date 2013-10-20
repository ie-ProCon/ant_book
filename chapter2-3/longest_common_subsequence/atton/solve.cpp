/* Programming Contest Challange Book P.56
 * Longest Common Subsequence
 * ant book original problem
 */

#include<iostream>

int dp[1010][1010] = {0};

int main(int argc, char const* argv[]) {
    int n,m;
    std::string s,t;

    std::cin >> n;
    std::cin >> m;

    std::cin >> s;
    std::cin >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s.at(i) == t.at(j)) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+i] = std::max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    std::cout << dp[n][m] << std::endl;

    return 0;
}
