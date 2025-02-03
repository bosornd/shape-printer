#ifndef DIAMOND_H
#define DIAMOND_H

#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

bool insideDiamond(int x, int y, int rows);

class InsideDiamond : public InsideShape {
public:
    bool operator()(int x, int y, int rows) const;
};

class Diamond : public Shape {
public:
    bool inside(int x, int y, int rows) const override;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // DIAMOND_H