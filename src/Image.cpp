#include "Image.h"
#include <algorithm>

namespace shape_printer {
namespace shape_extension {

Image::Image(const std::vector<std::vector<bool>>& image) : image(image) {}

bool Image::inside(int x, int y, int n) const {
    int centerX = image.size() / 2;
    int centerY = image[0].size() / 2;
    int translatedX = x + centerX;
    int translatedY = y + centerY;

    if (translatedX >= 0 && translatedX < image.size() && translatedY >= 0 && translatedY < image[0].size()) {
        return image[translatedX][translatedY];
    }
    return false;
}

int Image::getSize() const {
    int width = image.size();
    int height = image[0].size();
    return std::max(width, height) / 2 + 1;
}

} // namespace shape_extension
} // namespace shape_printer