#ifndef PRINTSHAPE_H
#define PRINTSHAPE_H

#include <functional>
#include <vector>

namespace shape_printer {

/**
 * @class InsideShape
 * @brief Abstract base class representing a shape's interior logic.
 */
class InsideShape {
public:
    /**
     * @brief Pure virtual function to determine if a point is inside the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param rows The number of rows in the shape.
     * @return True if the point is inside the shape, false otherwise.
     */
    virtual bool operator()(int x, int y, int rows) const = 0;
};

/**
 * @class Shape
 * @brief Abstract base class representing a shape.
 */
class Shape {
public:
    /**
     * @brief Pure virtual function to determine if a point is inside the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param rows The number of rows in the shape.
     * @return True if the point is inside the shape, false otherwise.
     */
    virtual bool inside(int x, int y, int rows) const = 0;
};

/**
 * @class Output
 * @brief Abstract base class for outputting the shape.
 */
class Output {
public:
    /**
     * @brief Pure virtual function to output the shape.
     * @param image The 2D vector representing the shape.
     */
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
};

/**
 * @class PrintShape
 * @brief Class responsible for printing shapes.
 */
class PrintShape {
public:
    /**
     * @brief Constructor accepting a function to determine if a point is inside the shape and an output function.
     * @param insideShape Function to determine if a point is inside the shape.
     * @param outputFunction Function to output the shape.
     */
    PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction);
    
    /**
     * @brief Constructor accepting a Shape object and an output function.
     * @param shape Shape object to determine if a point is inside the shape.
     * @param outputFunction Function to output the shape.
     */
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction);

    /**
     * @brief Sets a new function to determine if a point is inside the shape.
     * @param newInsideShape New function to determine if a point is inside the shape.
     */
    void setInsideShape(std::function<bool(int, int, int)> newInsideShape);
    
    /**
     * @brief Sets a new Shape object to determine if a point is inside the shape.
     * @param shape New Shape object to determine if a point is inside the shape.
     */
    void setInsideShape(const Shape& shape);

    /**
     * @brief Sets a new output function.
     * @param outputFunction New function to output the shape.
     */
    void setOutputFunction(std::function<void(const std::vector<std::vector<bool>>&)> outputFunction);

    /**
     * @brief Prints the shape with the given number of rows.
     * @param rows The number of rows in the shape.
     */
    void operator()(int rows) const;

private:
    std::function<bool(int, int, int)> insideShape; ///< Function to determine if a point is inside the shape.
    std::function<void(const std::vector<std::vector<bool>>&)> output; ///< Function to output the shape.
};

} // namespace shape_printer

#endif // PRINTSHAPE_H