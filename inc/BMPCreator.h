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
     */
    BMPCreator(const std::string& filename);

    /**
     * @brief Creates the BMP file from the shape.
     * @param image The 2D vector representing the shape.
     */
    void operator()(const std::vector<std::vector<bool>>& image) const override;

private:
    std::string filename; ///< Filename for the BMP file.

    /**
     * @brief Writes the BMP file.
     * @param image The 2D vector representing the shape.
     */
    void writeBMP(const std::vector<std::vector<bool>>& image) const;
};

} // namespace output_extension
} // namespace shape_printer

#endif // BMPCREATOR_H