#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "PrintShape.h"

namespace shape_printer {
namespace shape_extension {

/**
 * @class Image
 * @brief Class for handling image shapes.
 */
class Image : public Shape {
    std::vector<std::vector<bool>> image;

public:
    /**
     * @brief Constructor for Image class.
     * @param image The 2D vector of booleans representing the image.
     */
    Image(const std::vector<std::vector<bool>>& image);

    /**
     * @brief Checks if a point is inside the image.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param n The size parameter of the shape.
     * @return True if the point is inside the image, false otherwise.
     */
    bool inside(int x, int y, int n) const override;

    /**
     * @brief Gets the size of the image for PrintShape.
     * @return The size of the image.
     */
    int getSize() const;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // IMAGE_H