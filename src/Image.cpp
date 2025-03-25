#include "Image.h"
#include <algorithm>

namespace shape_printer {
namespace shape_extension {

Image::Image(const std::vector<std::vector<bool>>& image) : image(image) {}

bool Image::inside(int x, int y, int n) const {
    // Calculate the center of the image
    int centerX = image.size() / 2;
    int centerY = image[0].size() / 2;
    
    // Transform coordinates from shape system to image system
    int translatedX = x + centerX;
    int translatedY = y + centerY;

    // Check if the coordinates are within the image bounds
    if (translatedX >= 0 && translatedX < image.size() && 
        translatedY >= 0 && translatedY < image[0].size()) {
        return image[translatedX][translatedY];
    }
    // Points outside the image bounds are considered outside the shape
    return false;
}

int Image::getSize() const {
    int width = image.size();
    int height = image[0].size();
    return std::max(width, height) / 2 + 1;
}

} // namespace shape_extension
} // namespace shape_printer