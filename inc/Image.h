#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

class Image : public Shape {
    std::vector<std::vector<bool>> image;

public:
    Image(const std::vector<std::vector<bool>>& image);

    bool inside(int x, int y, int n) const override;

    int getSize() const; // Add getSize method
};

} // namespace shape_extension
} // namespace shape_printer

#endif // IMAGE_H