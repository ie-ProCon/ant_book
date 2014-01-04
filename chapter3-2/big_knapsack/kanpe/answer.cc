#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long Weight;
typedef unsigned long Value;

void input(void);
void show(void);
Value get_ans(void);
Value get_strict_ans(void);

const Value INF = ~Value();
int N;
Value W;
std::vector<Weight> weight_vec;
std::vector<Value>  value_vec;

int main(void) {
    input(); 
    Value answer = get_ans();
    //Value answer = get_strict_ans();
    std::cout << answer << std::endl;
    return 0;
}

Value get_ans(void) {
    int half_N = N / 2;
    /* example
     * N = 10
     * comb sum      = 00 0000 0000
     * 1st half comb =       0 0000
     * 2nd half comb = 00 000
     * */
    int half_comb = 1 << half_N;
    typedef std::pair<Weight, Value> WVPair;
    std::vector<WVPair> wv_pairvec = std::vector<WVPair>(half_comb);
    // first half (all comb) max_half_comb:2^20comb = 1,048,576
    for (int i = 0; i < half_comb; i++) {
        Weight weight = 0;
        Value  value  = 0;
        for (int j = 0; j < half_N; j++) {
            // 1 = put, 0 = not put
            bool put_in_bag = ((i>>j)&1) == 1;
            if (put_in_bag) {
                weight += weight_vec[j];
                value  += value_vec[j];
            }
        }
        wv_pairvec[i] = std::make_pair(weight, value);
    }

    // remove 
    std::sort(wv_pairvec.begin(), wv_pairvec.end());
    int m = 1;
    for (int i = 1; i < half_comb; i++) {
        bool is_useless = wv_pairvec[m-1].second < wv_pairvec[i].second;
        if (is_useless) {
            wv_pairvec[m++] = wv_pairvec[i];
        }
    }

    // second half
    Value answer  = 0;
    int rest_half = N - half_N;
    int rest_comb = 1 << rest_half;
    for (int i = 0; i < rest_comb; i++) {
        Weight weight = 0;
        Value  value  = 0;
        for (int j = 0; j < rest_half; j++) {
            bool put_in_bag = (i>>j) & 1 == 1;
            if (put_in_bag) {
                weight += weight_vec[half_N+j];
                value  += value_vec[half_N+j];
            }
        }
        if (weight <= W) {
            std::vector<WVPair>::iterator itr = std::lower_bound(wv_pairvec.begin(), wv_pairvec.end(), std::make_pair(W-weight, INF)) - 1;
            WVPair wv_pair   = *itr;
            Value temp_value = wv_pair.second;

            Value sum_v = value + temp_value;
            answer      = std::max(answer, sum_v);
        }
    }
    return answer;
}

Value get_strict_ans(void) {
    typedef std::pair<Weight, Value> WVPair;
    int comb = 1 << N;
    std::vector<WVPair> wv_pairvec = std::vector<WVPair>(comb);
    for (int i = 0; i < comb; i++) {
        Weight weight = 0;
        Value  value  = 0;
        for (int j = 0; j < N; j++) {
            bool put_in_bag = ((i>>j) & 1) == 1;
            if (put_in_bag) {
                weight += weight_vec[j]; 
                value  += value_vec[j]; 
            }
        }
        wv_pairvec[i] = std::make_pair(weight, value);
    }

    Value answer = 0;
    for (int i = 0; i < comb; i++) {
        Weight weight = wv_pairvec[i].first;
        Value  value  = wv_pairvec[i].second;
        if (weight <= W) {
            answer = std::max(answer, value);
        }
    }
    return answer;
}

void input(void) {
    std::cin >> N >> W;
    weight_vec = std::vector<Weight>(N);
    value_vec  = std::vector<Value>(N);
    for (int i = 0; i < N; i++) {
        std::cin >> weight_vec[i] >> value_vec[i]; 
    }
}
