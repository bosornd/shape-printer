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
     * @brief Sets the output stream for the object.
     * 
     * This function sets the output stream to the provided std::ostream object.
     * If no argument is provided, it defaults to std::cout.
     * 
     * @param os The output stream to be set. Defaults to std::cout.
     */
    void set(std::ostream& os = std::cout);

    /**
     * @brief Sets the characters used for printing shapes.
     * 
     * @param inChar The character to be used for the shape itself. Default is '*'.
     * @param outChar The character to be used for the space outside the shape. Default is ' '.
     * @param eolChar The character to be used for the end of line. Default is '\n'.
     */
    void set(char inChar = '*', char outChar = ' ', char eolChar = '\n');

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