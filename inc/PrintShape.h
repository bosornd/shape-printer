#ifndef PRINTSHAPE_H
#define PRINTSHAPE_H

#include <functional>
#include <vector>

class InsideShape {
public:
    // True if the point is inside the shape, false otherwise.
    virtual bool operator()(int rows, int x, int y) const = 0;
};

class Shape {
public:
    // True if the point is inside the shape, false otherwise.
    virtual bool inside(int rows, int x, int y) const = 0;
};

class Output {
public:
    // Output the shape defined in 2D boolean image.
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
};

class PrintShape {
public:
    // Constructor accepting a function to determine if a point is inside the shape and an output function.
    PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> output);
    
    // Constructor accepting a Shape object to determine if a point is inside the shape and an output function.
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output);

    // Setter for the function to determine if a point is inside the shape.
    void setInsideShape(std::function<bool(int, int, int)> insideShape);
    
    // Setter for the function to determine if a point is inside the shape using a Shape object.
    void setInsideShape(const Shape& shape);

    // Setter for the output function.
    void setOutputFunction(std::function<void(const std::vector<std::vector<bool>>&)> output);

    // Print the shape for the given number of rows.
    // The size of the shape is [2 * rows - 1] x [2 * rows - 1].
    void operator()(int rows) const;

private:
    std::function<bool(int, int, int)> insideShape; ///< Function to determine if a point is inside the shape.
    std::function<void(const std::vector<std::vector<bool>>&)> output; ///< Function to output the shape.
};

#endif // PRINTSHAPE_H