#include <iostream>
#include <vector>

int get_ans(const int num);

int main(void) {
    int n;
    std::cin >> n;
    int ans = get_ans(n+1);
    std::cout << ans << std::endl;
    return 0;
}

int get_ans(const int num) {
    int ans = 0;
    std::vector<bool> is_prime = std::vector<bool>(num, true); 
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 0; i < num; i++) {
        if (!is_prime[i]) {
            continue; 
        }
        ans++;
        for (int j = 2*i; j < num; j += i) {
            is_prime[j] = false; 
        }
    }
    return ans;
}
