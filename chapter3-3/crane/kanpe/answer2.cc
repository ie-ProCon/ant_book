#include <iostream>
#include <vector>
#include <math.h>

#define MAX_N (10000+10)
#define MAX_C (10000+10)

const double PI = 3.14159265358979323846;
const int ST_SIZE = (1 << 15) - 1;

int N,C;
std::vector<int> L;
std::vector<int> S;
std::vector<int> A;

double vx[ST_SIZE], vy[ST_SIZE];
double angle[ST_SIZE];

double prv[MAX_N];

void init(int k, int l, int r);
void change(int s, double a, int v, int l, int r);
void solve(void);

int main(void) {
    while(scanf("%d %d", &N, &C) != EOF) {
        L = std::vector<int>(N);
        S = std::vector<int>(C);
        A = std::vector<int>(C);
        for(int i = 0; i < N; i++) {
            scanf("%d", &L[i]);
        }
        for(int i = 0; i < C; i++) {
            scanf("%d %d", &S[i], &A[i]);
        }
        solve();
    }
    return 0;
}

void init(int k, int l, int r) {
    angle[k] = 0.0;
    vx[k]    = 0.0;

    if ((r-l) == 1) {
        // reaf
        vy[k] = L[l];
        return;
    }

    // not reaf
    int chl = k * 2 + 1;
    int chr = k * 2 + 2;
    init(chl, l, (l + r) / 2);
    init(chr, (l + r) / 2, r);
    vy[k] = vy[chl] + vy[chr];
}

void change(int s, double a, int v, int l, int r) {
    if ((s<=l) || (r<=s)) {
        return;
    }
    int chl = v * 2 + 1;
    int chr = v * 2 + 2;
    int mid = (l+r) / 2;
    change(s, a, chl, l, mid);
    change(s, a, chr, mid, r);
    if (s <= mid) {
        angle[v] += a;
    }

    double sin_v = sin(angle[v]);
    double cos_v = cos(angle[v]);
    vx[v] = vx[chl] + (cos_v * vx[chr] - sin_v * vy[chr]);
    vy[v] = vy[chl] + (sin_v * vx[chr] + cos_v * vy[chr]);
}

void solve(void) {
    init(0, 0, N);
    for(int i = 1; i < N; i++) { 
        prv[i] = PI;
    }

    for(int i = 0; i < C; i++) {
        int    s = S[i];
        double a = A[i] / 360.0 * 2 * PI;
        change(s, a-prv[s], 0, 0, N);
        prv[s] = a;
        printf("%.2f %.2f\n", vx[0], vy[0]);
    }
}
