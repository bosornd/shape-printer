#include "PrintShape.h"

namespace shape_printer {

// Constructor using std::function
PrintShape::PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> output) 
    : insideShape(insideShape), output(output) {}

// Constructor using Shape instance
PrintShape::PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output) 
    : insideShape(std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)), 
      output(output) {}

void PrintShape::setInsideShape(std::function<bool(int, int, int)> newInsideShape) {
    insideShape = newInsideShape;
}

void PrintShape::setInsideShape(const Shape& shape) {
    insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
}

void PrintShape::setOutput(std::function<void(const std::vector<std::vector<bool>>&)> newOutput) {
    output = newOutput;
}

void PrintShape::operator()(int n) const {
    std::vector<std::vector<bool>> image(2 * n - 1, std::vector<bool>(2 * n - 1, false));
    for (int y = n - 1; y >= -n + 1; y--) {
        for (int x = -n + 1; x <= n - 1; x++) {
            image[n - 1 - y][x + n - 1] = insideShape(x, y, n);
        }
    }
    output(image);
}

} // namespace shape_printer