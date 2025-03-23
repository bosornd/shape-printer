#include <iostream>
#include <cmath>
#include <functional>

// Define the InsideShape interface as a functor
struct InsideShape {
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

void printShape(int n, std::function<bool(int, int, int)> insideShape) {
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

// Define the InsideDiamond functor extending InsideShape
struct InsideDiamond : public InsideShape {
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
    printShape(1, [](int x, int y, int n) {
        return std::abs(x) + std::abs(y) < n;
    });

    // case 2. print a diamond shape using a named function
    printShape(2, insideDiamond);

    // case 3. print a diamond shape using a functor
    printShape(3, InsideDiamond());

    // case 4. print a diamond shape using a Diamond class
    Diamond diamond;
    printShape(4, std::bind(&Diamond::inside, &diamond, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    return 0;
}