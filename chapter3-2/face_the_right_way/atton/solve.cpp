/* Programming Contest Challenge Book P.139
 * Face The Right Way (POJ 3276)
 * http://poj.org/problem?id=3276
 */

#include<iostream>
#define MAX_N 5010

int N;
int directions[MAX_N];
int flip_counts[MAX_N];

int calc_min_step(int);
void solve(void);

int main(int argc, char const* argv[]) {

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char direction;
        std::cin >> direction;
        directions[i] = (direction == 'F') ? 0 : 1;
    }

    solve();

    return 0;
}


int calc_min_step(int flip_size) {
    std::fill_n(flip_counts, MAX_N, 0);

    int result    = 0;      // flip count
    int range_flip_sum = 0; // sum flip count in k-range

    for (int i = 0; i + flip_size <= N; i++) {

        if ((directions[i] + range_flip_sum) % 2 != 0) {
            result++;
            flip_counts[i] = 1;
        }

        range_flip_sum += flip_counts[i];

        int passed_cow_position = i - flip_size + 1;
        if (passed_cow_position >= 0) {
            range_flip_sum -= flip_counts[passed_cow_position];
        }
    }

    for (int i = N - flip_size + 1; i < N; i++) {
        if ((directions[i] + range_flip_sum) % 2 != 0) {
            return -1;  // no answer for this flip_size
        }

        int passed_cow_position = i - flip_size + 1;
        if (passed_cow_position >= 0) {
            range_flip_sum -= flip_counts[passed_cow_position];
        }
    }
    return result;
}

void solve() {
    int optimized_flip_size = 1;
    int min_count = N;

    for (int flip_size = 1; flip_size <= N; flip_size++) {

        int result = calc_min_step(flip_size);
        if (0 <= result && result < min_count) {
            optimized_flip_size = flip_size;
            min_count           = result;
        }
    }

    std::cout << optimized_flip_size << " " << min_count << std::endl;
}
