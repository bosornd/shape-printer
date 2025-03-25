#ifndef DIAMOND_H
#define DIAMOND_H

#include <cmath>
#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

// Function to determine if the point (x, y) is inside the diamond shape for the given number n.
// The size of the shape is [2*n-1]x[2*n-1].
// The point (0, 0) is at the center of the shape.
bool insideDiamond(int x, int y, int n);

// Define the InsideDiamond functor extending InsideShape
class InsideDiamond : public shape_printer::InsideShape {
public:
    // Determines if the point (x, y) is inside the diamond shape for the given number of rows.
    bool operator()(int x, int y, int n) const override;
};

// Define the Diamond class extending Shape
class Diamond : public shape_printer::Shape {
public:
    // Determines if the point (x, y) is inside the diamond shape for the given number of rows.
    bool inside(int x, int y, int n) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // DIAMOND_H