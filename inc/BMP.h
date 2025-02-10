#ifndef BMP_H
#define BMP_H

#include "PrintShape.h"
#include <vector>
#include <string>
#include <fstream>

namespace shape_printer {
namespace shape_extension {

/**
 * @class Image
 * @brief Class representing a shape defined by a boolean image.
 */
class Image : public Shape {
public:
    /**
     * @brief Constructor that initializes the image with given dimensions.
     * @param width The width of the image.
     * @param height The height of the image.
     */
    Image(int width, int height);
    /**
     * @brief Constructor that initializes the image with a given 2D vector.
     * @param img The 2D vector representing the image.
     */
    Image(const std::vector<std::vector<bool>>& image);

    /**
     * @brief Determines if a point is inside the image shape.
     * @param rows The number of rows in the shape.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @return True if the point is inside the shape, false otherwise.
     */
    bool inside(int rows, int x, int y) const override;

    /**
     * @brief Sets the value of a pixel in the image.
     * @param x The x-coordinate of the pixel.
     * @param y The y-coordinate of the pixel.
     * @param value The value to set (true for inside, false for outside).
     */
    void setPixel(int x, int y, bool value);

    /**
     * @brief Gets the width of the image.
     * @return The width of the image.
     */
    int getWidth() const;

    /**
     * @brief Gets the height of the image.
     * @return The height of the image.
     */
    int getHeight() const;

private:
    std::vector<std::vector<bool>> image; ///< 2D vector representing the image.
    int width; ///< Width of the image.
    int height; ///< Height of the image.
};

/**
 * @class BMP
 * @brief Class representing a BMP image as a shape.
 */
class BMP : public Image {
public:
    /**
     * @brief Constructor that loads a BMP file.
     * @param filename The name of the BMP file.
     */
    BMP(const std::string& filename);

private:
    /**
     * @brief Loads the BMP file.
     * @param filename The name of the BMP file.
     */
    std::vector<std::vector<bool>> loadBMP(const std::string& filename);
};

} // namespace shape_extension
} // namespace shape_printer

#endif // BMP_H