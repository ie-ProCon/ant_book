/* Programming Contest Challange Book P.62
 * limit number subset sum problem
 * ant book original problem
 */

#include<iostream>

#define MAX_N 110
#define MAX_K 100010

int a[MAX_N], m[MAX_N];
int dp[MAX_K];

int main(int argc, char const* argv[]) {

    int n,k;

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < n; i++) std::cin >> m[i];
    std::cin >> k;

    std::fill_n(dp, MAX_K, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (dp[j] < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }

    std::string ans = (dp[k] >= 0) ? "YES" : "NO";
    std::cout << ans << std::endl;

    return 0;
}
