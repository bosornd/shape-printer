#ifndef DIAMOND_H
#define DIAMOND_H

#include <cmath>
#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

/**
 * @brief Checks if a point is inside a diamond shape.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @param n The size parameter of the shape.
 * @return True if the point is inside the diamond, false otherwise.
 */
bool insideDiamond(int x, int y, int n);

/**
 * @class InsideDiamond
 * @brief Functor for checking if a point is inside a diamond shape.
 */
class InsideDiamond : public shape_printer::InsideShape {
public:
    /**
     * @brief Checks if a point is inside the diamond shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param n The size parameter of the shape.
     * @return True if the point is inside the diamond, false otherwise.
     */
    bool operator()(int x, int y, int n) const override;
};

/**
 * @class Diamond
 * @brief Class for diamond shapes.
 */
class Diamond : public shape_printer::Shape {
public:
    /**
     * @brief Checks if a point is inside the diamond shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param n The size parameter of the shape.
     * @return True if the point is inside the diamond, false otherwise.
     */
    bool inside(int x, int y, int n) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // DIAMOND_H