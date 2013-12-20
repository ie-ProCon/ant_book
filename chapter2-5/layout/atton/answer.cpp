/* Programming Contest Challange Book P.104
 * Layout (POJ 3169)
 */

#include<iostream>

#define INF    1000000000
#define MAX_N  1010
#define MAX_ML 10010
#define MAX_MD 10010

int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_ML];

int d[MAX_N];

int main(int argc, char const* argv[]) {
    int N, ML, MD;
    std::cin >> N >> ML >> MD;

    for (int i = 0; i < ML; i++) {
        std::cin >> AL[i] >> BL[i] >> DL[i];
    }
    for (int i = 0; i < MD; i++) {
        std::cin >> AD[i] >> BD[i] >> DD[i];
    }

    std::fill_n(d, MAX_N, INF);
    d[0] = 0;

    for (int k = 0; k < N; k++) {
        // not condition
        for (int i = 0; i < N; i++) {
            if (d[i + 1] < INF) d[i] = std::min(d[i], d[i + 1]);
        }

        // ML condition
        for (int i = 0; i < ML; i++) {
            if (d[AL[i] - 1] < INF)
                d[BL[i] - 1] = std::min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
        }

        // MD condition
        for (int i = 0; i < MD; i++) {
            if (d[BD[i] - 1] < INF)
                d[AD[i] - 1] = std::min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
        }
    }

    int answer = d[N - 1];

    if (d[0] < 0) {
        // graph has negative loop
        answer = -1;
    } else if (answer == INF) {
        // distance is infinity
        answer = -2;
    }

    std::cout << answer << std::endl;

    return 0;
}
