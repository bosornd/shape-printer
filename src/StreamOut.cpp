#include "StreamOut.h"

namespace shape_printer {
namespace output_extension {

StreamOut::StreamOut(std::ostream& os, char inChar, char outChar, char eolChar)
    : os(&os), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

void StreamOut::operator()(const std::vector<std::vector<bool>>& image) const {
    for (const auto& row : image) {
        for (bool pixel : row) {
            *os << (pixel ? inChar : outChar);
        }
        *os << eolChar;
    }
}

void StreamOut::set(std::ostream& os, char inChar, char outChar, char eolChar) {
    this->os = &os;
    this->inChar = inChar;
    this->outChar = outChar;
    this->eolChar = eolChar;
}

} // namespace output_extension
} // namespace shape_printer