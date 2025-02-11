#include "PrintShape.h"

#include <iostream>
#include <cmath>

int main() {
    PrintShape printer(
        [](int rows, int x, int y){ return (abs(x) + abs(y) < rows); },  // inside function
        [](const std::vector<std::vector<bool>>& image) {                // output function
            for (const auto& row : image) {
                for (bool pixel : row) {
                    std::cout << (pixel ? '*' : ' ');
                }
                std::cout << std::endl;
            }
        });
    printer(5);
    
    return 0;
}