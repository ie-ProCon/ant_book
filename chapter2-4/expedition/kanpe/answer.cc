#include <iostream>
#include <queue>
#include <algorithm>

void input(void);
int  get_ans(void);

typedef int Distance;
typedef int Amount;
typedef std::pair<Distance, Amount> DAPair;

int N;
int L;
int P;
std::vector<DAPair> dapair_vec;

int main(int argc,char* argv[]) {
    input();
    int ans = get_ans(); 
    std::cout << ans << std::endl;
    return 0;
}

int get_ans(void) {
    std::sort(dapair_vec.begin(), dapair_vec.end());

    int answer        = 0;
    Distance position = L;
    Amount rest_tank  = P;
    std::priority_queue<Amount> pque;
    std::vector<DAPair>::reverse_iterator itr = dapair_vec.rbegin();
    while (itr != dapair_vec.rend()) {
        DAPair dapair = *itr;
        itr++;

        Distance town2stand = dapair.first;
        Distance pre2next   = position - town2stand;
        while (rest_tank-pre2next < 0) {
            if (pque.empty()) {
                return -1;
            }
            Amount refuel = pque.top();
            rest_tank    += refuel;
            pque.pop();
            answer++;
        }
        rest_tank -= pre2next;
        position   = town2stand;

        Amount gone_stand = dapair.second;
        pque.push(gone_stand);
    }
    return answer;
}

void input(void) {
    std::cin >> N;
    dapair_vec = std::vector<DAPair>(N+1);
    dapair_vec[0] = DAPair(0, 0);
    for (int i = 1; i <= N; i++) {
        Distance distance;
        Amount   amount;
        std::cin >> distance >> amount;
        dapair_vec[i] = DAPair(distance, amount);
    }
    std::cin >> L >> P;
}
