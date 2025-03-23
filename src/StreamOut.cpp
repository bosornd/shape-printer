#include "StreamOut.h"

namespace shape_printer {
namespace output_extension {

// Constructor
StreamOut::StreamOut(std::ostream& output, std::string inChar, std::string outChar, std::string eolChar)
    : output(&output), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

// Set the output stream
void StreamOut::setOutput(std::ostream& newOutput) {
    output = &newOutput;
}

// Set the characters for printing
void StreamOut::setCharacters(const std::string& newInChar, const std::string& newOutChar, const std::string& newEolChar) {
    inChar = newInChar;
    outChar = newOutChar;
    eolChar = newEolChar;
}

// Overloaded operator() to print a boolean image
void StreamOut::operator()(const std::vector<std::vector<bool>>& image) const {
    for (const auto& row : image) {
        for (bool pixel : row) {
            if (pixel)
                *output << inChar;
            else
                *output << outChar;
        }
        *output << eolChar;
    }
}

} // namespace output_extension
} // namespace shape_printer