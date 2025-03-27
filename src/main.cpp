#include <iostream>
#include <cmath>
#include <functional>
#include <fstream>
#include <vector>

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

// Define the Output interface
class Output {
public:
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
    virtual ~Output() = default;
};

// Define the StreamOut class extending Output
class StreamOut : public Output {
    std::ostream* output;
    std::string inChar;
    std::string outChar;
    std::string eolChar;

public:
    StreamOut(std::ostream& output = std::cout, std::string inChar = "*", std::string outChar = " ", std::string eolChar = "\n")
        : output(&output), inChar(inChar), outChar(outChar), eolChar(eolChar) {}

    void setOutput(std::ostream& newOutput) {
        output = &newOutput;
    }

    void setCharacters(const std::string& newInChar = "*", const std::string& newOutChar = " ", const std::string& newEolChar = "\n") {
        inChar = newInChar;
        outChar = newOutChar;
        eolChar = newEolChar;
    }

    // Overloaded operator() to print a boolean image
    void operator()(const std::vector<std::vector<bool>>& image) const override {
        for (const auto& row : image) {
            for (bool pixel : row) {
                if (pixel)
                    *output << inChar;
                else
                    *output << outChar;
            }
            *output << eolChar;
        }
    }
};

// Define the PrintShape functor with a member variable to store insideShape function
class PrintShape {
    std::function<bool(int, int, int)> insideShape;
    std::function<void(const std::vector<std::vector<bool>>&)> output;

public:
    // Constructor using std::function
    PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> output) 
        : insideShape(insideShape), output(output) {}

    // Constructor using Shape instance
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> output) 
        : insideShape(std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)), 
          output(output) {}

    void setInsideShape(std::function<bool(int, int, int)> newInsideShape) {
        insideShape = newInsideShape;
    }

    void setInsideShape(const Shape& shape) {
        insideShape = std::bind(&Shape::inside, &shape, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

    void setOutput(std::function<void(const std::vector<std::vector<bool>>&)> newOutput) {
        output = newOutput;
    }

    void operator()(int n) const {
        std::vector<std::vector<bool>> image(2 * n - 1, std::vector<bool>(2 * n - 1, false));
        for (int y = n - 1; y >= -n + 1; y--) {
            for (int x = -n + 1; x <= n - 1; x++) {
                image[n - 1 - y][x + n - 1] = insideShape(x, y, n);
            }
        }
        output(image);
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
    // Create a StreamOut instance for console output
    StreamOut streamOut;

    // case 1. print a diamond shape using lambda function
    PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; }, streamOut);
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
    streamOut.setCharacters("O", ".");
    printShape.setOutput(streamOut);
    printShape(5);

    // print a diamond shape to a file
    std::ofstream file("diamond.txt");
    streamOut.setOutput(file);
    printShape.setOutput(streamOut);
    printShape(10);

    return 0;
}
