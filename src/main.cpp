#include <iostream>
#include <cmath>
#include <functional>

// Define the InsideShape interface as a functor
class InsideShape {
public:
    virtual bool operator()(int x, int y, int n) const = 0;
    virtual ~InsideShape() = default;
};

// Define the Shape interface
class Shape {
public:
    virtual bool inside(int x, int y, int n) const = 0;
    virtual ~Shape() = default;
};

bool insideDiamond(int x, int y, int n) {
    return std::abs(x) + std::abs(y) < n;
}

// Define the PrintShape functor with a member variable to store insideShape function
class PrintShape {
    std::function<bool(int, int, int)> insideShape;

public:
    // Constructor using std::function
    PrintShape(std::function<bool(int, int, int)> insideShape) : insideShape(insideShape) {}

    // Constructor using Shape instance
    PrintShape(const Shape& shape) : insideShape(std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)) {}

    void setInsideShape(std::function<bool(int, int, int)> newInsideShape) {
        insideShape = newInsideShape;
    }

    void setInsideShape(const Shape& shape) {
        insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

    void operator()(int n) const {
        for (int y = n - 1; y >= -n + 1; y--) {
            for (int x = -n + 1; x <= n - 1; x++) {
                if (insideShape(x, y, n))
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Define the InsideDiamond functor extending InsideShape
class InsideDiamond : public InsideShape {
public:
    bool operator()(int x, int y, int n) const override {
        return std::abs(x) + std::abs(y) < n;
    }
};

// Define the Diamond class extending Shape
class Diamond : public Shape {
public:
    bool inside(int x, int y, int n) const override {
        return std::abs(x) + std::abs(y) < n;
    }
};

int main() {
    // case 1. print a diamond shape using lambda function
    PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; });
    printShape(1);

    // case 2. print a diamond shape using general function
    printShape.setInsideShape(insideDiamond);
    printShape(2);

    // case 3. print a diamond shape using InsideShape functor
    printShape.setInsideShape(InsideDiamond());
    printShape(3);

    // case 4. print a diamond shape using Shape instance
    Diamond diamond;
    printShape.setInsideShape(diamond);
    printShape(4);

    return 0;
}