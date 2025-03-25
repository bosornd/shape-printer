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
    // Create a 2D boolean array to represent the image
    std::vector<std::vector<bool>> image(2 * n - 1, std::vector<bool>(2 * n - 1, false));
    
    // Fill the image by checking if each point is inside the shape
    // Coordinate transformation: convert from mathematical coordinates to array indices
    for (int y = n - 1; y >= -n + 1; y--) {           // y-axis points upward in math coords
        for (int x = -n + 1; x <= n - 1; x++) {       // x-axis points right
            // Transform (x,y) to array indices (row, col)
            image[n - 1 - y][x + n - 1] = insideShape(x, y, n);
        }
    }
    
    // Output the generated image
    output(image);
}

} // namespace shape_printer