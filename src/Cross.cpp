#include "Cross.h"

namespace shape_printer {
namespace shape_extension {

// Function to determine if a point is inside a cross shape
bool insideCross(int rows, int x, int y) {
    return x == 0 || y == 0;
}

// Determines if a point is inside the cross shape using InsideCross functor
bool InsideCross::operator()(int rows, int x, int y) const {
    return x == 0 || y == 0;
}

// Determines if a point is inside the cross shape using Cross class
bool Cross::inside(int rows, int x, int y) const {
    return x == 0 || y == 0;
}

} // namespace shape_extension
} // namespace shape_printer