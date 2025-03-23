#include "Diamond.h"

namespace shape_printer {
namespace shape_extension {

// Define the insideDiamond function
bool insideDiamond(int x, int y, int n) {
    return std::abs(x) + std::abs(y) < n;
}

// Define the InsideDiamond functor extending InsideShape
bool InsideDiamond::operator()(int x, int y, int n) const {
    return std::abs(x) + std::abs(y) < n;
}

// Define the Diamond class extending Shape
bool Diamond::inside(int x, int y, int n) const {
    return std::abs(x) + std::abs(y) < n;
}

} // namespace shape_extension
} // namespace shape_printer