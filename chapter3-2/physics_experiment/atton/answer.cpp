/* Programming Contest Challenge Book P.147
 * Physics Experiment (POJ 3684)
 * http://poj.org/problem?id=3684
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>

const double g  = 10.0;
const int MAX_N = 105;

double ball_positions[MAX_N];

int N, Height, Radius, Time;

double calc(int);
void   solve(void);

int main(int argc, char const* argv[]) {
    int question_count;

    std::cin >> question_count;
    for (int i = 0; i < question_count; i++) {
        std::cin >> N >> Height >> Radius >> Time;
        solve();
    }

    return 0;
}

double calc(int time) {
    if (time < 0) return Height;

    double t = std::sqrt(2 * Height / g);
    int    k = (int) time / t;

    double d;
    if (k % 2 == 0) {
        d = time - k * t;
    } else {
        d = k * t + t - time;
    }

    return Height - g * d * d / 2;
}

void solve() {
    for (int i = 0; i < N; i++) {
        ball_positions[i] = calc(Time - i);
    }

    std::sort(ball_positions, ball_positions + N);

    for (int i = 0; i < N; i++) {
        double value = ball_positions[i] + 2 * Radius * i / 100.0;
        char   delim = (i + 1 == N) ? '\n' : ' ';
        printf("%.2f%c", value, delim);
    }
}
