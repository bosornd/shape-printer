#include "Cross.h"

namespace shape_printer {
namespace shape_extension {

bool insideCross(int x, int y, int rows) {
    return x == 0 || y == 0;
}

bool InsideCross::operator()(int x, int y, int rows) const {
    return x == 0 || y == 0;
}

bool Cross::inside(int x, int y, int rows) const {
    return x == 0 || y == 0;
}

} // namespace shape_extension
} // namespace shape_printer