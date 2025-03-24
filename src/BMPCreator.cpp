#include "BMPCreator.h"
#include <fstream>

namespace shape_printer {
namespace output_extension {

BMPCreator::BMPCreator(const std::string& filename, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
    : filename(filename), red(red), green(green), blue(blue), alpha(alpha) {}

void BMPCreator::operator()(const std::vector<std::vector<bool>>& image) const {
    saveBMP(image);
}

void BMPCreator::setColors(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

void BMPCreator::saveBMP(const std::vector<std::vector<bool>>& image) const {
    int height = image.size();
    int width = image[0].size();
    int filesize = 54 + (4 * width) * height;

    unsigned char bmpfileheader[14] = {
        'B', 'M',  // Magic number
        0, 0, 0, 0,  // Size of the BMP file
        0, 0, 0, 0,  // Application specific
        54, 0, 0, 0  // Offset where the pixel array (bitmap data) can be found
    };
    unsigned char bmpinfoheader[40] = {
        40, 0, 0, 0,  // Size of this header
        0, 0, 0, 0,  // Width of the bitmap in pixels
        0, 0, 0, 0,  // Height of the bitmap in pixels
        1, 0,        // Number of color planes being used
        32, 0,       // Number of bits per pixel
        0, 0, 0, 0,  // BI_RGB, no pixel array compression used
        0, 0, 0, 0,  // Size of the raw bitmap data (including padding)
        0, 0, 0, 0,  // Print resolution of the image, 72 DPI x 72 DPI
        0, 0, 0, 0,  // Number of colors in the palette
        0, 0, 0, 0   // 0 means all colors are important
    };

    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);

    bmpinfoheader[4] = (unsigned char)(width);
    bmpinfoheader[5] = (unsigned char)(width >> 8);
    bmpinfoheader[6] = (unsigned char)(width >> 16);
    bmpinfoheader[7] = (unsigned char)(width >> 24);
    bmpinfoheader[8] = (unsigned char)(height);
    bmpinfoheader[9] = (unsigned char)(height >> 8);
    bmpinfoheader[10] = (unsigned char)(height >> 16);
    bmpinfoheader[11] = (unsigned char)(height >> 24);

    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file.write(reinterpret_cast<const char*>(bmpfileheader), sizeof(bmpfileheader));
    file.write(reinterpret_cast<const char*>(bmpinfoheader), sizeof(bmpinfoheader));

    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            unsigned char pixel[4] = {blue, green, red, alpha}; // BGRA format
            if (!image[y][x]) {
                pixel[0] = pixel[1] = pixel[2] = 0; // Black color for background
                pixel[3] = 0; // Fully transparent
            }
            file.write(reinterpret_cast<const char*>(pixel), 4);
        }
    }

    file.close();
}

} // namespace output_extension
} // namespace shape_printer