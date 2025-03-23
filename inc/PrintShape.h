#ifndef PRINTSHAPE_H
#define PRINTSHAPE_H

#include <functional>
#include <vector>

namespace shape_printer {

// Define the InsideShape interface as a functor
class InsideShape {
public:
    virtual bool operator()(int x, int y, int n) const = 0;
    virtual ~InsideShape() = default;
};

// Define the Shape interface
class Shape {
public:
    virtual bool inside(int x, int y, int n) const = 0;
    virtual ~Shape() = default;
};

// Define the Output interface
class Output {
public:
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
    virtual ~Output() = default;
};

// Define the PrintShape functor with a member variable to store insideShape function
class PrintShape {
    std::function<bool(int, int, int)> insideShape;
    std::function<void(const std::vector<std::vector<bool>>&)> output;

public:
    // Constructor using std::function
    PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> output);

    // Constructor using Shape instance
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output);

    void setInsideShape(std::function<bool(int, int, int)> newInsideShape);

    void setInsideShape(const Shape& shape);

    void setOutput(std::function<void(const std::vector<std::vector<bool>>&)> newOutput);

    void operator()(int n) const;
};

} // namespace shape_printer

#endif // PRINTSHAPE_H