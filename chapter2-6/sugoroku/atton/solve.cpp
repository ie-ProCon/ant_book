/* Programming Contest Challange Book P.109
 * sugoroku
 */

#include<iostream>

int extgcd(int a, int b, int& x, int&y) {
    int d = a;

    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }

    return d;
}

int main(int argc, char const* argv[]) {
    int a, b;
    std::cin >> a >> b;

    int x, y;
    int d = extgcd(4, 11, x, y);;

    if (d != 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    if (x > 0) {
        std::cout << x << " " << 0 << " ";
    } else {
        std::cout << 0 << " " << -x << " ";
    }

    if (y > 0) {
        std::cout << y << " " << 0 << " ";
    } else {
        std::cout << 0 << " " << -y << " ";
    }

    std::cout << std::endl;
    return 0;
}
