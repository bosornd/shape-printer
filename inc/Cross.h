#ifndef CROSS_H
#define CROSS_H

#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

bool insideCross(int x, int y, int rows);

class InsideCross : public InsideShape {
public:
    bool operator()(int x, int y, int rows) const;
};

class Cross : public Shape {
public:
    bool inside(int x, int y, int rows) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // CROSS_H