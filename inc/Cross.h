#ifndef CROSS_H
#define CROSS_H

#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

/**
 * @brief Function to determine if a point is inside a cross shape.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @param rows The number of rows in the shape.
 * @return True if the point is inside the cross shape, false otherwise.
 */
bool insideCross(int x, int y, int rows);

/**
 * @class InsideCross
 * @brief Class representing the logic for checking if a point is inside a cross shape.
 */
class InsideCross : public InsideShape {
public:
    /**
     * @brief Determines if a point is inside the cross shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param rows The number of rows in the shape.
     * @return True if the point is inside the cross shape, false otherwise.
     */
    bool operator()(int x, int y, int rows) const;
};

/**
 * @class Cross
 * @brief Class representing a cross shape.
 */
class Cross : public Shape {
public:
    /**
     * @brief Determines if a point is inside the cross shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param rows The number of rows in the shape.
     * @return True if the point is inside the cross shape, false otherwise.
     */
    bool inside(int x, int y, int rows) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // CROSS_H