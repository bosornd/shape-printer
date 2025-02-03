#ifndef STREAMOUT_H
#define STREAMOUT_H

#include <iostream>
#include <vector>
#include "PrintShape.h"

namespace shape_printer {
namespace output_extension {

class StreamOut : public Output {
public:
    StreamOut(std::ostream& os = std::cout, char inChar = '*', char outChar = ' ', char eolChar = '\n');

    void set(std::ostream& os = std::cout, char inChar = '*', char outChar = ' ', char eolChar = '\n');

    void operator()(const std::vector<std::vector<bool>>& image) const override;

private:
    std::ostream* os;
    char inChar;
    char outChar;
    char eolChar;
};

} // namespace output_extension
} // namespace shape_printer

#endif // STREAMOUT_H