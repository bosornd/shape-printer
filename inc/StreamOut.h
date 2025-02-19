#ifndef STREAMOUT_H
#define STREAMOUT_H

#include <iostream>
#include <vector>

#include "PrintShape.h"

// Class for outputting shapes to a stream.
class StreamOut : public Output {
public:
    // Constructor with default parameters for output characters.
    StreamOut(std::ostream& os = std::cout, char inChar = '*', char outChar = ' ', char eolChar = '\n');

    // Sets the output stream for the object.
    void set(std::ostream& os = std::cout);

    // Sets the characters used for printing shapes.
    void set(char inChar = '*', char outChar = ' ', char eolChar = '\n');

    // Outputs the shape to the stream.
    void operator()(const std::vector<std::vector<bool>>& image) const override;

private:
    std::ostream* os; ///< Output stream.
    char inChar; ///< Character for inside the shape.
    char outChar; ///< Character for outside the shape.
    char eolChar; ///< End of line character.
};

#endif // STREAMOUT_H