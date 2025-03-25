#include "BMP.h"
#include <fstream>
#include <stdexcept>

namespace shape_printer {
namespace shape_extension {

BMP::BMP(const std::string& filename) : Image(loadBMP(filename)) {}

std::vector<std::vector<bool>> BMP::loadBMP(const std::string& filename) const {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Unable to open BMP file");
    }

    // Read width and height from the BMP header (at offset 18)
    file.seekg(18);
    int width = 0;
    int height = 0;
    file.read(reinterpret_cast<char*>(&width), 4);
    file.read(reinterpret_cast<char*>(&height), 4);

    // Initialize the image with the correct dimensions
    std::vector<std::vector<bool>> image(height, std::vector<bool>(width, false));

    // Read the pixel data (starting at offset 54 for standard BMP)
    file.seekg(54);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char pixel[4];
            file.read(reinterpret_cast<char*>(pixel), 4);
            // Check if the pixel is not fully transparent black
            // Format: BGRA (Blue, Green, Red, Alpha)
            image[y][x] = !(pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0 && pixel[3] == 0);
        }
    }

    return image;
}

} // namespace shape_extension
} // namespace shape_printer