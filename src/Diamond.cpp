#include "Diamond.h"
#include <cmath>

namespace shape_printer {
namespace shape_extension {

bool insideDiamond(int x, int y, int rows) {
    return std::abs(x) + std::abs(y) < rows;
}

bool InsideDiamond::operator()(int x, int y, int rows) const {
    return std::abs(x) + std::abs(y) < rows;
}

bool Diamond::inside(int x, int y, int rows) const {
    return std::abs(x) + std::abs(y) < rows;
}

} // namespace shape_extension
} // namespace shape_printer