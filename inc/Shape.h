#ifndef SHAPE_H
#define SHAPE_H

#include <functional>
#include <vector>

class Output {
public:
    // Output the shape defined in 2D boolean image.
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
};

class Shape {
public:
    // Constructor accepting an output function.
    Shape(const Output& output);

    // Print the shape for the given number of rows.
    // Shape is defined by the inside() method.
    // The size of the shape is [2 * rows - 1] x [2 * rows - 1].
    void print(int rows) const;

protected:
    // True if the point is inside the shape, false otherwise.
    virtual bool inside(int rows, int x, int y) const = 0;

private:
    const Output& output; ///< Reference to the function to output the shape.
};

#endif // SHAPE_H