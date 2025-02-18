#include "StreamOut.h"

namespace shape_printer {
namespace output_extension {

// Constructor with default parameters for output characters
StreamOut::StreamOut(std::ostream& os, char inChar, char outChar, char eolChar)
    : os(&os), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

// Sets the output stream for the object
void StreamOut::set(std::ostream& os) {
    this->os = &os;
}

// Sets the characters used for printing shapes
void StreamOut::set(char inChar, char outChar, char eolChar) {
    this->inChar = inChar;
    this->outChar = outChar;
    this->eolChar = eolChar;
}

// Outputs the shape to the stream
void StreamOut::operator()(const std::vector<std::vector<bool>>& image) const {
    for (const auto& row : image) {
        for (bool pixel : row) {
            *os << (pixel ? inChar : outChar);
        }
        *os << eolChar;
    }
}

} // namespace output_extension
} // namespace shape_printer