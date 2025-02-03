#include "StreamOut.h"

namespace shape_printer {
namespace output_extension {

// Constructor with default parameters for output characters
StreamOut::StreamOut(std::ostream& os, char inChar, char outChar, char eolChar)
    : os(&os), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

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