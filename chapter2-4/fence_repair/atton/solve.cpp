/* Programming Contest Challange Book P.49, 75
 * Fence Repair (POJ 3253)
 */

#include<iostream>
#include<queue>

int main(int argc, char const* argv[]) {
    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int> > woods;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        woods.push(tmp);
    }

    long long cost = 0;

    while (woods.size() != 1) {

        int concat_wood = 0;
        concat_wood += woods.top();
        woods.pop();
        concat_wood += woods.top();
        woods.pop();

        woods.push(concat_wood);
        cost += concat_wood;
    }

    std::cout << cost << std::endl;

    return 0;
}
