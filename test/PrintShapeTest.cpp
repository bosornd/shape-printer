#include <gtest/gtest.h>
#include "PrintShape.h"
#include "Diamond.h"
#include "Cross.h"
#include "StreamOut.h"
#include "BMPCreator.h"
#include "BMP.h"

using namespace shape_printer;
using namespace shape_printer::shape_extension;
using namespace shape_printer::output_extension;

// Test case for printing a diamond shape using a lambda function
TEST(PrintShapeTest, DiamondUsingLambdaFunction) {
    auto lambdaDiamond = [](int x, int y, int rows) {
        return std::abs(x) + std::abs(y) < rows;
    };

    std::ostringstream oss;
    StreamOut streamOut(oss, '*');
    PrintShape printShape(lambdaDiamond, streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}


// Test case for printing a diamond shape using insideDiamond function
TEST(PrintShapeTest, DiamondUsingSimpleFunction) {
    std::ostringstream oss;
    StreamOut streamOut(oss, '*');
    PrintShape printShape(insideDiamond, streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

// Test case for printing a diamond shape using InsideDiamond functor
TEST(PrintShapeTest, DiamondUsingInsideDiamondFunctor) {
    InsideDiamond insideDiamond;

    std::ostringstream oss;
    StreamOut streamOut(oss);
    PrintShape printShape(insideDiamond, streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

// Test case for printing a diamond shape using Shape instance
TEST(PrintShapeTest, DiamondUsingShapeInstance) {
    Diamond diamond;

    std::ostringstream oss;
    StreamOut streamOut(oss);
    PrintShape printShape(diamond, streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

// Test case for printing a cross shape using InsideCross functor
TEST(PrintShapeTest, CrossUsingInsideCrossFunctor) {
    InsideCross insideCross;

    std::ostringstream oss;
    StreamOut streamOut(oss);
    PrintShape printShape(insideCross, streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        "  *  \n"
        "*****\n"
        "  *  \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

// Test case for printing a cross shape using Shape instance
TEST(PrintShapeTest, CrossUsingShapeInstance) {
    Cross cross;

    std::ostringstream oss;
    StreamOut streamOut(oss, '*');
    PrintShape printShape(cross, streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        "  *  \n"
        "*****\n"
        "  *  \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

// Test case for printing a BMP shape
TEST(PrintShapeTest, BMPShape) {
    // Create a BMP file with a simple pattern
    BMPCreator bmpCreator("test.bmp");
    bmpCreator({
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    });

    BMP bmp("test.bmp");

    std::ostringstream oss;
    StreamOut streamOut(oss);
    PrintShape printShape(bmp, streamOut);

    printShape(3);

    std::string expectedOutput =
        "     \n"
        " *** \n"
        " * * \n"
        " *** \n"
        "     \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
