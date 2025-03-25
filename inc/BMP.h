#ifndef BMP_H
#define BMP_H

#include <string>
#include "Image.h"

namespace shape_printer {
namespace shape_extension {

/**
 * @class BMP
 * @brief Class for handling BMP image files.
 */
class BMP : public Image {
public:
    /**
     * @brief Constructor for BMP class.
     * @param filename The name of the BMP file to load.
     */
    BMP(const std::string& filename);

private:
    /**
     * @brief Loads a BMP file.
     * @param filename The name of the BMP file to load.
     * @return A 2D vector of booleans representing the image.
     */
    std::vector<std::vector<bool>> loadBMP(const std::string& filename) const;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // BMP_H