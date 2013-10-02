#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void input(void);
int get_ans(void);

int n;
std::vector<std::pair<int, int> > end_start; // end, start

int main(void) {
    input();
    int ans = get_ans();
    std::cout << ans << std::endl;
    return 0;
}

int get_ans(void) {
    int ans = 0;

    std::sort(end_start.begin(), end_start.end());

    int end_time = 0;
    for (int i = 0; i < n; i++) {
        int start_time = end_start[i].second;
        if (end_time < start_time) {
            int new_end = end_start[i].first;
            end_time = new_end;
            ans++; 
        }
    }

    return ans;
}


void input(void) {
    std::string buf;
    std::cin >> buf; // "n"
    std::cin >> n;
    std::cin >> buf; // "s"
    std::vector<int> start_vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> start_vec[i]; 
    }

    end_start = std::vector<std::pair<int, int> >(n);

    std::cin >> buf; // "t"
    for (int i = 0; i < n; i++) {
        int start_time = start_vec[i]; 
        int end_time;
        std::cin >> end_time;
        end_start[i] = std::pair<int, int>(end_time, start_time);
    }
}
