#include "BMPCreator.h"
#include <vector>
#include <string>
#include <fstream>

namespace shape_printer {
namespace output_extension {

// Constructor accepting a filename for the BMP file
BMPCreator::BMPCreator(const std::string& filename) : filename(filename) {}

// Creates the BMP file from the shape
void BMPCreator::operator()(const std::vector<std::vector<bool>>& image) const {
    writeBMP(image);
}

// Writes the BMP file
void BMPCreator::writeBMP(const std::vector<std::vector<bool>>& image) const {
    int width = image[0].size();
    int height = image.size();
    int filesize = 54 + 4 * width * height;

    unsigned char bmpfileheader[14] = {
        'B', 'M',  // Magic number
        0, 0, 0, 0,  // Size of the BMP file
        0, 0,  // Reserved
        0, 0,  // Reserved
        54, 0, 0, 0  // Start position of pixel data
    };

    unsigned char bmpinfoheader[40] = {
        40, 0, 0, 0,  // Size of this header
        0, 0, 0, 0,  // Width of the bitmap
        0, 0, 0, 0,  // Height of the bitmap
        1, 0,  // Number of color planes
        32, 0,  // Number of bits per pixel
        0, 0, 0, 0,  // Compression method
        0, 0, 0, 0,  // Size of the raw bitmap data
        0, 0, 0, 0,  // Print resolution of the image
        0, 0, 0, 0,  // Print resolution of the image
        0, 0, 0, 0,  // Number of colors in the palette
        0, 0, 0, 0   // Number of important colors
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

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char color = image[i][j] ? 0 : 255;
            unsigned char pixel[4] = { color, color, color, 255 }; // 32 bits per pixel (RGBA)
            file.write(reinterpret_cast<const char*>(pixel), sizeof(pixel));
        }
    }

    file.close();
}

} // namespace output_extension
} // namespace shape_printer