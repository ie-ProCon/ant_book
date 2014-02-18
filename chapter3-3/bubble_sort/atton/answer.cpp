/* Programming Contest Challenge Book P.162
 * exchange count on bubble sort
 */

#include<iostream>

const int MAX_N = 100010;

int n;
int a[MAX_N];
int bit[MAX_N + 1];

int sum(int index) {
    int sum = 0;

    while (index > 0) {
        sum   += bit[index];
        index -= index & -index;        // minus last bit
    }

    return sum;
}

void add(int index, int value) {
    while (index <= n) {
        bit[index] += value;
        index      += index & -index;   // add last bit
    }
}


long long solve() {
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        answer += i - sum(a[i]);
        add(a[i], 1);
    }

    return answer;
}

int main(int argc, char const* argv[]) {

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cout << solve() << std::endl;

    return 0;
}
