#include "BMP.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

namespace shape_printer {
namespace shape_extension {

// Constructor that initializes the BMP object and loads the BMP file
BMP::BMP(const std::string& filename) : filename(filename) {
    loadBMP();
}

// Determines if a point is inside the BMP shape
bool BMP::inside(int x, int y, int rows) const {
    int centerX = width / 2;
    int centerY = height / 2;

    int newX = x + centerX;
    int newY = y + centerY;

    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
        return image[newY][newX];
    }
    return false;
}

// Gets the width of the BMP image
int BMP::getWidth() const {
    return width;
}

// Gets the height of the BMP image
int BMP::getHeight() const {
    return height;
}

// Loads the BMP file and populates the image vector
void BMP::loadBMP() {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Unable to open BMP file");
    }

    unsigned char bmpfileheader[14];
    unsigned char bmpinfoheader[40];

    file.read(reinterpret_cast<char*>(bmpfileheader), 14);
    file.read(reinterpret_cast<char*>(bmpinfoheader), 40);

    width = bmpinfoheader[4] + (bmpinfoheader[5] << 8) + (bmpinfoheader[6] << 16) + (bmpinfoheader[7] << 24);
    height = bmpinfoheader[8] + (bmpinfoheader[9] << 8) + (bmpinfoheader[10] << 16) + (bmpinfoheader[11] << 24);

    image.resize(height, std::vector<bool>(width, false));

    file.seekg(54, std::ios::beg);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char pixel[4];
            file.read(reinterpret_cast<char*>(pixel), 4);
            image[i][j] = (pixel[0] == 0 && pixel[1] == 0 && pixel[2] == 0);
        }
    }

    file.close();
}

} // namespace shape_extension
} // namespace shape_printer