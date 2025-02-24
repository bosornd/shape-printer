#include "Shape.h"
#include <vector>

Shape::Shape(const Output& output) : output(output) {}

void Shape::print(int rows) const {
    int size = 2 * rows - 1;
    std::vector<std::vector<bool>> img(size, std::vector<bool>(size));
    for (int y = -rows + 1; y < rows; ++y) {
        for (int x = -rows + 1; x < rows; ++x) {
            img[y + rows - 1][x + rows - 1] = inside(rows, x, y);
        }
    }
    output(img);
}
