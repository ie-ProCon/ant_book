#include <iostream>
#include <vector>

void input(void);
bool is_ok(double x);
double get_ans(void);


const int MAX_N         = 10000;
const int CABLE_MAX_LEN = 100000;
int N,K;
std::vector<double> cable_vec;

int main(void) {
    input();
    double ans = get_ans();
    printf("%.2f\n",ans);
    return 0;
}

bool is_ok(double x) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        num += (int)(cable_vec[i] / x); 
    }
    bool is_ok = K <= num;
    return is_ok;
}

double get_ans(void) {
    double l = 0;
    double r = MAX_N * CABLE_MAX_LEN;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0; 
        if (is_ok(mid)) {
            l = mid; 
            continue;
        }
        r = mid;
    }
    double floor_ans = (int)(r*100.0) / 100.0;
    return floor_ans;
}

void input(void) {
    std::cin >> N >> K;
    cable_vec = std::vector<double>(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cable_vec[i]; 
    }
}
