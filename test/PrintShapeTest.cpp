#include <gtest/gtest.h>

#include "PrintShape.h"
#include <cmath>
#include <sstream>

// Test case for printing a diamond shape using a lambda function
TEST(PrintShapeTest, DiamondUsingLambdaFunction) {
    std::ostringstream oss;
    PrintShape printShape(
        [](int rows, int x, int y){ return (abs(x) + abs(y) < rows); },  // inside function
        [&oss](const std::vector<std::vector<bool>>& image) {                // output function
            for (const auto& row : image) {
                for (bool pixel : row) {
                    oss << (pixel ? '*' : ' ');
                }
                oss << std::endl;
            }
        });
    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

