#include "BMP.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

namespace shape_printer {
namespace shape_extension {

// Constructor that initializes the image with given dimensions
Image::Image(int width, int height) : width(width), height(height) {
    image.resize(height, std::vector<bool>(width, false));
}

// Constructor that initializes the image with a given 2D vector
Image::Image(const std::vector<std::vector<bool>>& img) : image(img) {
    height = img.size();
    width = img.empty() ? 0 : img[0].size();
}

// Determines if a point is inside the image shape
bool Image::inside(int rows, int x, int y) const {
    int newX = x + width / 2;
    int newY = y + height / 2;

    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
        return image[newY][newX];
    }
    return false;
}

// Sets the value of a pixel in the image
void Image::setPixel(int x, int y, bool value) {
    int newX = x + width / 2;
    int newY = y + height / 2;

    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
        image[newY][newX] = value;
    }
}

// Gets the width of the image
int Image::getWidth() const {
    return width;
}

// Gets the height of the image
int Image::getHeight() const {
    return height;
}

// Constructor that initializes the BMP object and loads the BMP file
BMP::BMP(const std::string& filename) : Image(loadBMP(filename)) {
}

// Loads the BMP file and populates the image vector
std::vector<std::vector<bool>> BMP::loadBMP(const std::string& filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        throw std::runtime_error("Unable to open BMP file");
    }

    unsigned char bmpfileheader[14];
    unsigned char bmpinfoheader[40];

    file.read(reinterpret_cast<char*>(bmpfileheader), 14);
    file.read(reinterpret_cast<char*>(bmpinfoheader), 40);

    int width = bmpinfoheader[4] + (bmpinfoheader[5] << 8) + (bmpinfoheader[6] << 16) + (bmpinfoheader[7] << 24);
    int height = bmpinfoheader[8] + (bmpinfoheader[9] << 8) + (bmpinfoheader[10] << 16) + (bmpinfoheader[11] << 24);

    std::vector<std::vector<bool>> image(height, std::vector<bool>(width, false));

    file.seekg(54, std::ios::beg);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char pixel[4];
            file.read(reinterpret_cast<char*>(pixel), 4);
            image[i][j] = (pixel[3] != 0);              // Check if the alpha channel is not 0
        }
    }

    file.close();

    return image;
}

} // namespace shape_extension
} // namespace shape_printer