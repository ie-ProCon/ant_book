/* Programming Contest Challenge Book P.117
 * Minimum Scalar Product
 * https://code.google.com/codejam/contest/32016/dashboard
 */

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

#define MAX_N 810

void solve(int);

int main(int argc, char const* argv[]) {
    std::string str;
    std::getline(std::cin, str);
    int count = std::atoi(str.c_str());

    for (int i = 0; i < count; i++) {
        solve(i+1);
    }

    return 0;
}

void solve(int case_num) {
    std::string tmp;
    std::getline(std::cin, tmp);
    int n = std::atoi(tmp.c_str());

    std::vector<long> a;
    std::vector<long> b;

    for (int i = 0; i < 2; i++) {
        std::string line;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string str;
        while(getline(iss, str, ' ')) (i == 0 ? a : b).push_back(std::atol(str.c_str()));
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), std::greater<long>());

    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += a.at(i) * b.at(i);
    }

    std::cout << "Case #" << case_num << ": " << answer << std::endl;
}
