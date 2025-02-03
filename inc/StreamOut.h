#ifndef STREAMOUT_H
#define STREAMOUT_H

#include <iostream>
#include <vector>
#include "PrintShape.h"

namespace shape_printer {
namespace output_extension {

/**
 * @class StreamOut
 * @brief Class for outputting shapes to a stream.
 */
class StreamOut : public Output {
public:
    /**
     * @brief Constructor with default parameters for output characters.
     * @param os The output stream.
     * @param inChar The character for inside the shape.
     * @param outChar The character for outside the shape.
     * @param eolChar The end of line character.
     */
    StreamOut(std::ostream& os = std::cout, char inChar = '*', char outChar = ' ', char eolChar = '\n');

    /**
     * @brief Outputs the shape to the stream.
     * @param image The 2D vector representing the shape.
     */
    void operator()(const std::vector<std::vector<bool>>& image) const override;

private:
    std::ostream* os; ///< Output stream.
    char inChar; ///< Character for inside the shape.
    char outChar; ///< Character for outside the shape.
    char eolChar; ///< End of line character.
};

} // namespace output_extension
} // namespace shape_printer

#endif // STREAMOUT_H