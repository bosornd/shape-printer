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

TEST(PrintShapeTest, DiamondUsingInsideDiamondFunctor) {
    InsideDiamond insideDiamond;
    StreamOut streamOut(std::cout);
    PrintShape printShape(insideDiamond, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PrintShapeTest, DiamondUsingShapeInstance) {
    Diamond diamond;
    StreamOut streamOut(std::cout);
    PrintShape printShape(diamond, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PrintShapeTest, CrossUsingInsideCrossFunctor) {
    InsideCross insideCross;
    StreamOut streamOut(std::cout);
    PrintShape printShape(insideCross, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        "  *  \n"
        "*****\n"
        "  *  \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PrintShapeTest, CrossUsingShapeInstance) {
    Cross cross;
    StreamOut streamOut(std::cout);
    PrintShape printShape(cross, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        "  *  \n"
        "*****\n"
        "  *  \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PrintShapeTest, DiamondUsingLambdaFunction) {
    auto lambdaDiamond = [](int x, int y, int rows) {
        return std::abs(x) + std::abs(y) < rows;
    };
    StreamOut streamOut(std::cout);
    PrintShape printShape(lambdaDiamond, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PrintShapeTest, DiamondUsingInsideDiamondFunction) {
    StreamOut streamOut(std::cout);
    PrintShape printShape(insideDiamond, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

TEST(PrintShapeTest, DiamondUsingLambdaFunctionSizes) {
    auto lambdaDiamond = [](int x, int y, int rows) {
        return std::abs(x) + std::abs(y) < rows;
    };
    StreamOut streamOut(std::cout);
    PrintShape printShape(lambdaDiamond, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    for (int size = 1; size <= 4; ++size) {
        printShape(size);
        oss << "\n";
    }

    std::string expectedOutput =
        "*\n"
        "\n"
        " * \n"
        "***\n"
        " * \n"
        "\n"
        "  *  \n"
        " *** \n"
        "*****\n"
        " *** \n"
        "  *  \n"
        "\n"
        "   *   \n"
        "  ***  \n"
        " ***** \n"
        "*******\n"
        " ***** \n"
        "  ***  \n"
        "   *   \n"
        "\n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

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
    StreamOut streamOut(std::cout);
    PrintShape printShape(bmp, streamOut);

    std::ostringstream oss;
    streamOut.set(oss, '*', ' ', '\n');
    printShape.setOutputFunction(streamOut);

    printShape(3);

    std::string expectedOutput =
        "     \n"
        " *** \n"
        " * * \n"
        " *** \n"
        "     \n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
