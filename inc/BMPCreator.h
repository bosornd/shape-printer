#ifndef BMPCREATOR_H
#define BMPCREATOR_H

#include "PrintShape.h"
#include <vector>
#include <string>
#include <fstream>

namespace shape_printer {
namespace output_extension {

/**
 * @class BMPCreator
 * @brief Class for creating BMP files from shapes.
 */
class BMPCreator : public Output {
public:
    /**
     * @brief Constructor accepting a filename for the BMP file.
     * @param filename The name of the BMP file.
     * @param color The color to use for the shape in the BMP file.
     */
    BMPCreator(const std::string& filename, uint32_t color = 0xFFFFFFFF);

    /**
     * @brief Creates the BMP file from the shape.
     * @param image The 2D vector representing the shape.
     */
    void operator()(const std::vector<std::vector<bool>>& image) const override;

    /**
     * @brief Sets the color using RGBA values.
     * @param r Red component (0-255).
     * @param g Green component (0-255).
     * @param b Blue component (0-255).
     * @param a Alpha component (0-255).
     */
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

private:
    std::string filename; ///< Filename for the BMP file.
    uint32_t color; ///< Color to use for the shape in the BMP file.

    /**
     * @brief Writes the BMP file.
     * @param image The 2D vector representing the shape.
     */
    void writeBMP(const std::vector<std::vector<bool>>& image) const;
};

} // namespace output_extension
} // namespace shape_printer

#endif // BMPCREATOR_H