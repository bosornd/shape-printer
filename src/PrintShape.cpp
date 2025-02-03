#include "PrintShape.h"

#include <iostream>
#include <vector>

namespace shape_printer {

PrintShape::PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction)
    : insideShape(insideShape), output(outputFunction) {}

PrintShape::PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction)
    : output(outputFunction) {
    insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
}

void PrintShape::setInsideShape(std::function<bool(int, int, int)> newInsideShape) {
    insideShape = newInsideShape;
}

void PrintShape::setInsideShape(const Shape& shape) {
    insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
}

void PrintShape::setOutputFunction(std::function<void(const std::vector<std::vector<bool>>&)> outputFunction) {
    output = outputFunction;
}

void PrintShape::operator()(int rows) const {
    std::vector<std::vector<bool>> image(2 * rows - 1, std::vector<bool>(2 * rows - 1, false));

    for (int i = -rows + 1; i < rows; i++) {
        for (int j = -rows + 1; j < rows; j++) {
            if (insideShape(i, j, rows)) {
                image[i + rows - 1][j + rows - 1] = true;
            }
        }
    }

    output(image);
}

} // namespace shape_printer