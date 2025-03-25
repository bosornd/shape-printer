#ifndef PRINTSHAPE_H
#define PRINTSHAPE_H

#include <functional>
#include <vector>

namespace shape_printer {

/**
 * @class InsideShape
 * @brief Interface for checking if a point is inside a shape.
 */
class InsideShape {
public:
    /**
     * @brief Checks if a point is inside the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param n The size parameter of the shape.
     * @return True if the point is inside the shape, false otherwise.
     */
    virtual bool operator()(int x, int y, int n) const = 0;
    virtual ~InsideShape() = default;
};

/**
 * @class Shape
 * @brief Interface for shape classes.
 */
class Shape {
public:
    /**
     * @brief Checks if a point is inside the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param n The size parameter of the shape.
     * @return True if the point is inside the shape, false otherwise.
     */
    virtual bool inside(int x, int y, int n) const = 0;
    virtual ~Shape() = default;
};

/**
 * @class Output
 * @brief Interface for output classes.
 */
class Output {
public:
    /**
     * @brief Outputs a boolean image.
     * @param image The 2D vector of booleans representing the image.
     */
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
    virtual ~Output() = default;
};

/**
 * @class PrintShape
 * @brief Functor for printing shapes.
 */
class PrintShape {
    std::function<bool(int, int, int)> insideShape;
    std::function<void(const std::vector<std::vector<bool>>&)> output;

public:
    /**
     * @brief Constructor using std::function.
     * @param insideShape Function to check if a point is inside the shape.
     * @param output Function to output the shape.
     */
    PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> output);

    /**
     * @brief Constructor using Shape instance.
     * @param shape Shape instance.
     * @param output Function to output the shape.
     */
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output);

    /**
     * @brief Sets the insideShape function.
     * @param newInsideShape The new insideShape function.
     */
    void setInsideShape(std::function<bool(int, int, int)> newInsideShape);

    /**
     * @brief Sets the insideShape function using a Shape instance.
     * @param shape The Shape instance.
     */
    void setInsideShape(const Shape& shape);

    /**
     * @brief Sets the output function.
     * @param newOutput The new output function.
     */
    void setOutput(std::function<void(const std::vector<std::vector<bool>>&)> newOutput);

    /**
     * @brief Prints the shape.
     * @param n The size parameter of the shape.
     */
    void operator()(int n) const;
};

} // namespace shape_printer

#endif // PRINTSHAPE_H