#include <gtest/gtest.h>
#include "PrintShape.h"

using namespace shape_printer;

bool insideDiamond(int x, int y, int n) {
    return std::abs(x) + std::abs(y) < n;
}

class MockShape : public Shape {
public:
    bool inside(int x, int y, int n) const override {
        return std::abs(x) + std::abs(y) < n;
    }
};

TEST(PrintShapeTest, LambdaFunction) {
    std::vector<std::vector<bool>> expected = {
        {false, true, false},
        {true, true, true},
        {false, true, false}
    };

    std::vector<std::vector<bool>> result;
    auto output = [&result](const std::vector<std::vector<bool>>& image) {
        result = image;
    };

    PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; }, output);
    printShape(2);

    EXPECT_EQ(result, expected);
}

TEST(PrintShapeTest, InsideShapeFunction) {
    std::vector<std::vector<bool>> expected = {
        {false, true, false},
        {true, true, true},
        {false, true, false}
    };

    std::vector<std::vector<bool>> result;
    auto output = [&result](const std::vector<std::vector<bool>>& image) {
        result = image;
    };

    PrintShape printShape(insideDiamond, output);
    printShape(2);

    EXPECT_EQ(result, expected);
}

TEST(PrintShapeTest, InsideShapeFunctor) {
    std::vector<std::vector<bool>> expected = {
        {false, true, false},
        {true, true, true},
        {false, true, false}
    };

    std::vector<std::vector<bool>> result;
    auto output = [&result](const std::vector<std::vector<bool>>& image) {
        result = image;
    };

    PrintShape printShape(MockShape(), output);
    printShape(2);

    EXPECT_EQ(result, expected);
}

TEST(PrintShapeTest, ShapeInstance) {
    std::vector<std::vector<bool>> expected = {
        {false, true, false},
        {true, true, true},
        {false, true, false}
    };

    std::vector<std::vector<bool>> result;
    auto output = [&result](const std::vector<std::vector<bool>>& image) {
        result = image;
    };

    MockShape mockShape;
    PrintShape printShape(mockShape, output);
    printShape(2);

    EXPECT_EQ(result, expected);
}