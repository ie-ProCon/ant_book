/* Programming Contest Challenge Book P.128
 * lower_bound
 */
#include<iostream>
#include<sstream>
#include<string>
#define INFINITY 100000000000
#define MAX_N 1000010

long long numbers[MAX_N];
int solve(int, int);

int main(int argc, char const* argv[]) {
    std::string str;

    std::getline(std::cin, str);
    int n = std::atoi(str.c_str());

    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int i = 0;

    numbers[i++] = -1;
    while(getline(iss, str, ' ')) {
        numbers[i++] = std::atoll(str.c_str());
    }
    numbers[i++] = INFINITY;

    std::getline(std::cin, str);
    int k = std::atoi(str.c_str());

    std::cout << solve(n, k) << std::endl;

    return 0;
}

int solve(int n, int k) {
    int upper_bound = n+2;
    int lower_bound = 0;
    int middle = (upper_bound + lower_bound) / 2;

    while (upper_bound - lower_bound > 1) {
        middle = (upper_bound + lower_bound) / 2;
        if (numbers[middle] < k) {
            lower_bound = middle;
        } else {
            upper_bound = middle;
        }

    }

    return lower_bound; // if k over max value in arr, return sentinel value arr.size
}
