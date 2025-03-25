#ifndef STREAMOUT_H
#define STREAMOUT_H

#include <iostream>
#include <vector>
#include "PrintShape.h"

namespace shape_printer {
namespace output_extension {

// Define the StreamOut class extending Output
// This class is used to print a boolean image to an output stream
// The characters used to represent true and false values can be set
class StreamOut : public Output {
    std::ostream* output;
    std::string inChar;     // Character to represent true values
    std::string outChar;    // Character to represent false values
    std::string eolChar;    // Character to represent end of line

public:
    StreamOut(std::ostream& output = std::cout, std::string inChar = "*", std::string outChar = " ", std::string eolChar = "\n");

    void setOutput(std::ostream& newOutput);
    void setCharacters(const std::string& newInChar = "*", const std::string& newOutChar = " ", const std::string& newEolChar = "\n");

    // Overloaded operator() to print a boolean image to output stream
    void operator()(const std::vector<std::vector<bool>>& image) const override;
};

} // namespace output_extension
} // namespace shape_printer

#endif // STREAMOUT_H