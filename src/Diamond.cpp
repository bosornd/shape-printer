#include "Diamond.h"
#include <cmath>

namespace shape_printer {
namespace shape_extension {

// Function to determine if a point is inside a diamond shape
bool insideDiamond(int x, int y, int rows) {
    return std::abs(x) + std::abs(y) < rows;
}

// Determines if a point is inside the diamond shape using InsideDiamond functor
bool InsideDiamond::operator()(int x, int y, int rows) const {
    return std::abs(x) + std::abs(y) < rows;
}

// Determines if a point is inside the diamond shape using Diamond class
bool Diamond::inside(int x, int y, int rows) const {
    return std::abs(x) + std::abs(y) < rows;
}

} // namespace shape_extension
} // namespace shape_printer