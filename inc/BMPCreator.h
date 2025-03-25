#ifndef BMPCREATOR_H
#define BMPCREATOR_H

#include <vector>
#include <string>
#include "PrintShape.h"

namespace shape_printer {
namespace output_extension {

/**
 * @class BMPCreator
 * @brief Class for creating BMP files from boolean images.
 */
class BMPCreator : public Output {
    std::string filename;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;

public:
    /**
     * @brief Constructor for BMPCreator class.
     * @param filename The name of the BMP file to create.
     * @param red The red color component.
     * @param green The green color component.
     * @param blue The blue color component.
     * @param alpha The alpha transparency component.
     */
    BMPCreator(const std::string& filename, unsigned char red = 255, unsigned char green = 255, unsigned char blue = 255, unsigned char alpha = 255);

    /**
     * @brief Overloaded operator() to create a BMP file from a boolean image.
     * @param image The 2D vector of booleans representing the image.
     */
    void operator()(const std::vector<std::vector<bool>>& image) const override;

    /**
     * @brief Sets the colors for the shape to be printed. Background color is transparent black.
     * @param red The red color component.
     * @param green The green color component.
     * @param blue The blue color component.
     * @param alpha The alpha transparency component.
     */
    void setColors(unsigned char red = 255, unsigned char green = 255, unsigned char blue = 255, unsigned char alpha = 255);

private:
    /**
     * @brief Saves the boolean image as a BMP file.
     * @param image The 2D vector of booleans representing the image.
     */
    void saveBMP(const std::vector<std::vector<bool>>& image) const;
};

} // namespace output_extension
} // namespace shape_printer

#endif // BMPCREATOR_H