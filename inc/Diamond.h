#ifndef DIAMOND_H
#define DIAMOND_H

#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

/**
 * @brief Function to determine if a point is inside a diamond shape.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @param rows The number of rows in the shape.
 * @return True if the point is inside the diamond shape, false otherwise.
 */
bool insideDiamond(int x, int y, int rows);

/**
 * @class InsideDiamond
 * @brief Class representing the logic for checking if a point is inside a diamond shape.
 */
class InsideDiamond : public InsideShape {
public:
    /**
     * @brief Determines if a point is inside the diamond shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param rows The number of rows in the shape.
     * @return True if the point is inside the diamond shape, false otherwise.
     */
    bool operator()(int x, int y, int rows) const;
};

/**
 * @class Diamond
 * @brief Class representing a diamond shape.
 */
class Diamond : public Shape {
public:
    /**
     * @brief Determines if a point is inside the diamond shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param rows The number of rows in the shape.
     * @return True if the point is inside the diamond shape, false otherwise.
     */
    bool inside(int x, int y, int rows) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // DIAMOND_H