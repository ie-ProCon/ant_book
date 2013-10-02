/* Programming Contest Challange Book P.34
 * Subset Sum Problem
 */

#include<iostream>

int n;
int numbers[30];

bool dfs(int target_num, int sum, int index) {
    if (index == n) return target_num == sum;

    if (dfs(target_num, sum + numbers[index], index+1)) return true;
    if (dfs(target_num, sum, index+1)) return true;

    return false;
}

int main(int argc, char const* argv[]) {

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int target_num;
    std::cin >> target_num;

    if (dfs(target_num, 0, 0)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
