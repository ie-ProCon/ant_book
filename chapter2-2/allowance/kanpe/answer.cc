/*
 * POJ 3040 
 * Allowance
 * http://poj.org/problem?id=3040
 */

/* 
 * ---[Input]
 * N C
 * V1 B1
 * V2 B2
 * ...
 * ---[解釈]
 * N : コインの種類
 * C : 週に渡す最低限のお金
 * Vi : 〇〇円玉
 * Bi : 持っている枚数
 * ---[Output]
 * 何週間渡せるか
 */


#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

void input(void);
void solve(void);
bool pay_oneweek(void);


int N; // 1 <= N <= 20
int C; // 1 <= C <= 10^8
typedef std::pair<int, int> COIN;
std::vector<COIN> money;

int main(void) {
    input();
    solve();
    return 0;
}

int pay_over(int rest_payment, const int index, const int step) {
     if (index<0 || N-1<index || rest_payment<=0) {
        return rest_payment; 
    }
    int value = money[index].first;
    int num   = money[index].second;
    if (rest_payment<=value && 0<num) {
        money[index].second--;
        return rest_payment - value;
    }
    return pay_over(rest_payment, index+step, step);
}

int pay_larger(int rest_payment, int index) {
    if (index < 0) {
        return rest_payment; 
    }
    int value = money[index].first;
    int num   = money[index].second;
    if (value<=rest_payment && 0<num) {
        int pay_num = std::min(num, rest_payment/value);

        money[index].second -= pay_num;
        rest_payment        -= value * pay_num;
    }
    return pay_larger(rest_payment, --index);
}

bool pay_oneweek() {
    int rest_payment = C;

    int start_index1 = N-1;
    int step1        = -1;
    int start_index2 = 0;
    int step2        = 1;

    rest_payment = pay_over(rest_payment, start_index1, step1);
    rest_payment = pay_larger(rest_payment, N-1);
    rest_payment = pay_over(rest_payment, start_index2, step2);
    return rest_payment <= 0;
}

void solve(void) {
    std::sort(money.begin(), money.end());
    int  ans     = 0;
    bool can_pay = true;
    while (can_pay) {
        can_pay = pay_oneweek(); 
        ans += can_pay & 1;
    }
    std::cout << ans << std::endl;
}

void input(void) {
    std::cin >> N >> C;
    money = std::vector<COIN>(N);
    for (int i = 0; i < N; i++) {
        int value,num;
        std::cin >> value >> num;
        money[i] = COIN(value, num);
    }
}
