#include <iostream>
/*
 * int's MAX       = 2147483647 > 10^9 = 1oku
 * 0 <= C <= 10^9
 * 0 <= A <= 10^9
 * */

void input(void);
int get_ans(void);
int min(int a, int b);


const int COIN_SUM = 6;
const int COIN_UNIT[COIN_SUM] = {500, 100, 50, 10, 5, 1};

int A;
int COIN[COIN_SUM];

int main(void) {
    input();
    int ans = get_ans();
    std::cout << ans << std::endl;
    return 0;
}

int get_ans(void) {
    int coin_count = 0;
    for (int i = 0; i < COIN_SUM; i++) {
        if (COIN[i] == 0) {
            continue; 
        }
        int use_count = min((int)A/COIN_UNIT[i], COIN[i]); 
        A -= COIN_UNIT[i] * use_count;
        coin_count += use_count;
    }
    return coin_count;
}

void input(void) {
    std::string buf;
    std::cin >> buf; // "A"
    std::cin >> A;
    std::cin >> buf; // "C1_C5_C10..."
    for (int i = 0; i < COIN_SUM; i++) {
        std::cin >> COIN[i]; 
    }
}

int min(int a, int b) {
    return (a < b)? a : b;
}
