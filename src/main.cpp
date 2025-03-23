#include <iostream>
#include <cmath>
#include <functional>
#include <fstream>

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
    std::ostream* output;
    std::string inChar;
    std::string outChar;
    std::string eolChar;

public:
    // Constructor using std::function
    PrintShape(std::function<bool(int, int, int)> insideShape, std::ostream& output = std::cout, 
               std::string inChar = "*", std::string outChar = " ", std::string eolChar = "\n") 
        : insideShape(insideShape), output(&output), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

    // Constructor using Shape instance
    PrintShape(const Shape& shape, std::ostream& output = std::cout, 
               std::string inChar = "*", std::string outChar = " ", std::string eolChar = "\n") 
        : insideShape(std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)), 
          output(&output), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

    void setInsideShape(std::function<bool(int, int, int)> newInsideShape) {
        insideShape = newInsideShape;
    }

    void setInsideShape(const Shape& shape) {
        insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

    void setOutput(std::ostream& newOutput) {
        output = &newOutput;
    }

    void setCharacters(const std::string& newInChar = "*", const std::string& newOutChar = " ", const std::string& newEolChar = "\n") {
        inChar = newInChar;
        outChar = newOutChar;
        eolChar = newEolChar;
    }

    void operator()(int n) const {
        for (int y = n - 1; y >= -n + 1; y--) {
            for (int x = -n + 1; x <= n - 1; x++) {
                if (insideShape(x, y, n))
                    *output << inChar;
                else
                    *output << outChar;
            }
            *output << eolChar;
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

    // change printing characters
    printShape.setCharacters("O", ".");
    printShape(5);

    // print a diamond shape to a file
    std::ofstream file("diamond.txt");
    printShape.setOutput(file);
    printShape(10);

    return 0;
}