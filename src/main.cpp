#include "Shape.h"

#include <iostream>
#include <cmath>

class Diamond : public Shape {
public:
    Diamond(const Output& output) : Shape(output) {}
    
protected:
    bool inside(int rows, int x, int y) const override {
        return (abs(x) + abs(y) < rows);
    }
};

class StreamOut : public Output {
public:
    void operator()(const std::vector<std::vector<bool>>& image) const override {
        for (const auto& row : image) {
            for (bool pixel : row) {
                std::cout << (pixel ? '*' : ' ');
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    StreamOut streamOut;
    Diamond diamond(streamOut);
    diamond.print(5);

    return 0;
}