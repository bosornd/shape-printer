#ifndef DIAMOND_H
#define DIAMOND_H

#include <cmath>
#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

// Declare the insideDiamond function
bool insideDiamond(int x, int y, int n);

// Define the InsideDiamond functor extending InsideShape
class InsideDiamond : public shape_printer::InsideShape {
public:
    bool operator()(int x, int y, int n) const override;
};

// Define the Diamond class extending Shape
class Diamond : public shape_printer::Shape {
public:
    bool inside(int x, int y, int n) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // DIAMOND_H