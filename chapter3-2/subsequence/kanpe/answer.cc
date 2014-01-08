#include <iostream>
#include <algorithm>
#include <vector>

void input(void);
int get_ans1(void);
int get_ans2(void);

int N, S;
std::vector<int> array;

int main(void) {
    int case_num;
    std::cin >> case_num;
    for (int i = 0; i < case_num; i++) {
        input();
        //int ans = get_ans1();
        int ans = get_ans2();
        std::cout << ans << std::endl;
    }
    return 0;
}

// O(N*log(N))
int get_ans1(void) {
    std::vector<int> sum = std::vector<int>(N+1, 0);
    for (int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + array[i];
    }
    if (sum[N] < S) {
        return 0; 
    }

    int result = N;
    for (int s = 0; sum[s]+S <= sum[N]; s++) {
        int t = std::lower_bound(sum.begin()+s, sum.begin()+N, sum[s]+S) - sum.begin();
        result = std::min(result, t-s);
    }
    return result;
}

// O(N)
int get_ans2(void) {
    int result = N + 1;
    int s = 0, t = 0, sum = 0;
    while (true) {
        while (t<N && sum<S) {
            sum += array[t++]; 
        }
        if (sum < S) {
            break; 
        }
        result = std::min(result, t-s);
        sum   -= array[s++];
    }

    if (N < result) {
        return 0; 
    }
    return result;
}

void input(void) {
    std::cin >> N >> S; 
    array = std::vector<int>(N);
    for (int i = 0; i < N; i++) {
        std::cin >> array[i]; 
    }
}
