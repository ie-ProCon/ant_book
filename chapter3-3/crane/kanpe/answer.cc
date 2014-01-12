#include <iostream>
#include <vector>
#include <math.h>

const double PI = 3.14159265359;
int N,C;
std::vector<int> L;
std::vector<int> angle_vec;

void output_ans(void);

int main(void) {
    std::string line;
    int init_angle = 180;
    bool flag = false;
    while (std::cin >> N >> C) {
        if (flag) {
            printf("\n");
        }
        L = std::vector<int>(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &L[i]);
        }

        angle_vec = std::vector<int>(N, init_angle);
        for (int i = 0; i < C; i++) {
            int S,A;
            scanf("%d %d", &S, &A);
            angle_vec[S] = A;
            output_ans();
        }
        flag = true; 
    }
    return 0;
}

void output_ans(void) {
    double x = 0;
    double y = L[0];
    int angle = 90;
    for (int i = 1; i < N; i++) {
        angle += angle_vec[i] - 180;
        double r = angle * (PI/180);
        x += L[i] * cos(r);
        y += L[i] * sin(r);
    }
    printf("%0.02f %0.02f\n", x, y);
}
