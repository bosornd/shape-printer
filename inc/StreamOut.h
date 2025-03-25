#ifndef STREAMOUT_H
#define STREAMOUT_H

#include <iostream>
#include <vector>
#include "PrintShape.h"

namespace shape_printer {
namespace output_extension {

/**
 * @class StreamOut
 * @brief Class for outputting boolean images to a stream.
 */
class StreamOut : public Output {
    std::ostream* output;
    std::string inChar;
    std::string outChar;
    std::string eolChar;

public:
    /**
     * @brief Constructor for StreamOut class.
     * @param output The output stream.
     * @param inChar The character representing the inside of the shape.
     * @param outChar The character representing the outside of the shape.
     * @param eolChar The end-of-line character.
     */
    StreamOut(std::ostream& output = std::cout, std::string inChar = "*", std::string outChar = " ", std::string eolChar = "\n");

    /**
     * @brief Sets the output stream.
     * @param newOutput The new output stream.
     */
    void setOutput(std::ostream& newOutput);

    /**
     * @brief Sets the characters used for printing.
     * @param newInChar The character representing the inside of the shape.
     * @param newOutChar The character representing the outside of the shape.
     * @param newEolChar The end-of-line character.
     */
    void setCharacters(const std::string& newInChar = "*", const std::string& newOutChar = " ", const std::string& newEolChar = "\n");

    /**
     * @brief Overloaded operator() to print a boolean image.
     * @param image The 2D vector of booleans representing the image.
     */
    void operator()(const std::vector<std::vector<bool>>& image) const override;
};

} // namespace output_extension
} // namespace shape_printer

#endif // STREAMOUT_H