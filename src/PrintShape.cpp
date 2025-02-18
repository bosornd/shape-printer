#include "PrintShape.h"

#include <iostream>
#include <vector>

namespace shape_printer {

// Constructor accepting a function to determine if a point is inside the shape and an output function
PrintShape::PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction)
    : insideShape(insideShape), output(outputFunction) {}

// Constructor accepting a Shape object and an output function
PrintShape::PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction)
    : output(outputFunction) {
    // Bind the Shape's inside method to the insideShape function
    insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
}

// Set a new function to determine if a point is inside the shape
void PrintShape::setInsideShape(std::function<bool(int, int, int)> newInsideShape) {
    insideShape = newInsideShape;
}

// Set a new Shape object to determine if a point is inside the shape
void PrintShape::setInsideShape(const Shape& shape) {
    // Bind the Shape's inside method to the insideShape function
    insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
}

// Set a new output function
void PrintShape::setOutputFunction(std::function<void(const std::vector<std::vector<bool>>&)> outputFunction) {
    output = outputFunction;
}

// Operator to print the shape with the given number of rows
void PrintShape::operator()(int rows) const {
    // Create a 2D vector to represent the image
    std::vector<std::vector<bool>> image(2 * rows - 1, std::vector<bool>(2 * rows - 1));

    // Iterate through each point in the image
    for (int y = -rows + 1; y < rows; y++) {
        for (int x = -rows + 1; x < rows; x++) {
            // Set the point to true if it is inside the shape
            image[y + rows - 1][x + rows - 1] = insideShape(rows, x, y);
        }
    }

    // Output the image
    output(image);
}

} // namespace shape_printer