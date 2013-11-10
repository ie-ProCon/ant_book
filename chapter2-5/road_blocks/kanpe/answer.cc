#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int from;
    int to;
    int cost;
};

typedef std::pair<int, int> Pair;
typedef std::vector<Edge> EdgeVec;

void input(void);
int  get_ans(void);

const int MAX_N    = 5000;
const int MAX_R    = 100000;
const int MAX_COST = 5000;
const int INF      = MAX_R * MAX_COST + 1; 
int N,R;
std::vector<EdgeVec> G;
std::vector<int> cost;
std::vector<int> cost2;

int main() {
    input();
    int ans = get_ans();
    std::cout << ans << std::endl;
    return 0;
}

int get_ans(void) {
    cost    = std::vector<int>(MAX_N, INF);
    cost2   = std::vector<int>(MAX_N, INF);
    cost[0] = 0;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair> > que;
    int start_id   = 0;
    int start_cost = 0;
    que.push(Pair(start_cost, start_id));

    while (!que.empty()) {
        Pair pair = que.top();
        que.pop();
        int node_id = pair.second;
        int c       = pair.first;
        if (cost2[node_id] < c) {
            continue; 
        }
        for (int i = 0; i < (int)G[node_id].size(); i++) {
            Edge& edge     = G[node_id][i];
            int   cost_sum = c + edge.cost; 
            if (cost_sum < cost[edge.to]) {
                std::swap(cost[edge.to], cost_sum);
                que.push(Pair(cost[edge.to], edge.to));
            }
            if ((cost_sum<cost2[edge.to]) && (cost[edge.to]<cost_sum)) {
                cost2[edge.to] = cost_sum;
                que.push(Pair(cost2[edge.to], edge.to));
            }
        }
    }
    int answer = cost2[N-1];
    return answer;
}

void input(void) {
    std::cin >> N >> R;
    G = std::vector<EdgeVec>(MAX_N);
    for (int i = 0; i < R; i++) {
        int from;
        int to;
        int cost;
        std::cin >> from >> to >> cost;
        Edge edge1 = Edge();
        edge1.from = --from;
        edge1.to   = --to;
        edge1.cost = cost;
        G[from].push_back(edge1);
        Edge edge2 = Edge();
        edge2.from = to;
        edge2.to   = from;
        edge2.cost = cost;
        G[to].push_back(edge2);
    }
}
