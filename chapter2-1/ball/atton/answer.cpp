/* AOJ 0033 Ball */

#include<iostream>

using namespace std;

int balls[15];

bool dfs(int ball_index, int right, int left) {
    if (ball_index == 10) return true;

    int last_ball = balls[ball_index];
    if (last_ball > right) return dfs(ball_index+1, last_ball, left);
    if (last_ball > left)  return dfs(ball_index+1, right, last_ball);

    return false;
}

void solve() {
    for (int i = 0; i < 10; i++) {
        cin >> balls[i];
    }

    if (dfs(0, 0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(int argc, char const* argv[]) {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solve();
    }

    return 0;
}
