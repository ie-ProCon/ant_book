#include <iostream>

std::string get_ans(const int num);

int main(void) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        std::string ans = get_ans(num);
        std::cout << ans << std::endl;
    }
    return 0;
}

std::string get_ans(const int num) {
    if (num == 1) {
        return "No";
    }
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return "No";
        }
    }
    return "Yes";
}
