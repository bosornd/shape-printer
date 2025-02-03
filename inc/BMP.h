#ifndef BMP_H
#define BMP_H

#include "PrintShape.h"
#include <vector>
#include <string>
#include <fstream>

namespace shape_printer {
namespace shape_extension {

/**
 * @class BMP
 * @brief Class representing a BMP image as a shape.
 */
class BMP : public Shape {
public:
    /**
     * @brief Constructor that loads a BMP file.
     * @param filename The name of the BMP file.
     */
    BMP(const std::string& filename);

    /**
     * @brief Determines if a point is inside the BMP shape.
     * @param rows The number of rows in the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @return True if the point is inside the shape, false otherwise.
     */
    bool inside(int rows, int x, int y) const override;

    /**
     * @brief Gets the width of the BMP image.
     * @return The width of the BMP image.
     */
    int getWidth() const;

    /**
     * @brief Gets the height of the BMP image.
     * @return The height of the BMP image.
     */
    int getHeight() const;

private:
    std::string filename; ///< Filename of the BMP image.
    std::vector<std::vector<bool>> image; ///< 2D vector representing the BMP image.
    int width; ///< Width of the BMP image.
    int height; ///< Height of the BMP image.

    /**
     * @brief Loads the BMP file.
     */
    void loadBMP();
};

} // namespace shape_extension
} // namespace shape_printer

#endif // BMP_H