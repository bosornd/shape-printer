#ifndef CROSS_H
#define CROSS_H

#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

/**
 * @brief Function to determine if a point is inside a cross shape.
 * @param rows The number of rows in the shape.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @return True if the point is inside the cross shape, false otherwise.
 */
bool insideCross(int rows, int x, int y);

/**
 * @class InsideCross
 * @brief Class representing the logic for checking if a point is inside a cross shape.
 */
class InsideCross : public InsideShape {
public:
    /**
     * @brief Determines if a point is inside the cross shape.
     * @param rows The number of rows in the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @return True if the point is inside the cross shape, false otherwise.
     */
    bool operator()(int rows, int x, int y) const;
};

/**
 * @class Cross
 * @brief Class representing a cross shape.
 */
class Cross : public Shape {
public:
    /**
     * @brief Determines if a point is inside the cross shape.
     * @param rows The number of rows in the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @return True if the point is inside the cross shape, false otherwise.
     */
    bool inside(int rows, int x, int y) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // CROSS_H