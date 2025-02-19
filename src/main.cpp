#include "PrintShape.h"

#include <iostream>
#include <cmath>

int main() {
    PrintShape printShape(
        [](int rows, int x, int y){ return (abs(x) + abs(y) < rows); },  // inside function
        [](const std::vector<std::vector<bool>>& image) {                // output function
            for (const auto& row : image) {
                for (bool pixel : row) {
                    std::cout << (pixel ? '*' : ' ');
                }
                std::cout << std::endl;
            }
        });
    printShape(5);
    
    return 0;
}