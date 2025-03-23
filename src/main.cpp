#include <iostream>
#include <cmath>
#include <functional>

bool insideDiamond(int x, int y, int n) {
    return std::abs(x) + std::abs(y) < n;
}

void printShape(int n, std::function<bool(int, int, int)> insideShape) {
    for (int y = n - 1; y >= -n + 1; y--) {
        for (int x = -n + 1; x <= n - 1; x++) {
            if (insideShape(x, y, n))
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of rows for the diamond: ";
    std::cin >> n;

    printShape(n, insideDiamond);

    return 0;
}