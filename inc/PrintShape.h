#ifndef PRINTSHAPE_H
#define PRINTSHAPE_H

#include <functional>
#include <vector>

namespace shape_printer {

// Define the InsideShape interface as a functor
class InsideShape {
public:
    // True if the point is inside the shape, false otherwise.
    virtual bool operator()(int x, int y, int n) const = 0;
    virtual ~InsideShape() = default;
};

// Define the Shape interface
class Shape {
public:
    // True if the point is inside the shape, false otherwise.
    virtual bool inside(int x, int y, int n) const = 0;
    virtual ~Shape() = default;
};

// Define the Output interface
class Output {
public:
    // Print the boolean image to the output
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
    virtual ~Output() = default;
};

// Define the PrintShape functor with a member variable to store insideShape function
class PrintShape {
    std::function<bool(int, int, int)> insideShape;                     // Function to determine if a point is inside the shape
    std::function<void(const std::vector<std::vector<bool>>&)> output;  // Function to output the boolean image

public:
    PrintShape(std::function<bool(int, int, int)> shape, std::function<void(const std::vector<std::vector<bool>>&)> output);
    PrintShape(const InsideShape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output);
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output);
    PrintShape(std::function<bool(int, int, int)> shape, const Output& output);
    PrintShape(const InsideShape& shape, const Output& output);
    PrintShape(const Shape& shape, const Output& output);

    void setShape(std::function<bool(int, int, int)> shape);
    void setShape(const InsideShape& shape);
    void setShape(const Shape& shape);

    void setOutput(std::function<void(const std::vector<std::vector<bool>>&)> output);
    void setOutput(const Output& output);

    // The shape is printed to the output using the insideShape function.
    // The size of the shape is [2*n-1]x[2*n-1].
    // The point (0, 0) is at the center of the shape.
    // The point (x, y) is inside the shape if insideShape(x, y, n) returns true.
    // The output is a boolean image where true values represent points inside the shape.
    void operator()(int n) const;
};

} // namespace shape_printer

#endif // PRINTSHAPE_H