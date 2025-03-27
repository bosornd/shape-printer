#include <iostream>
#include <functional>
#include <fstream>
#include <vector>
#include "PrintShape.h"
#include "Diamond.h"
#include "StreamOut.h"
#include "BMPCreator.h"

using namespace shape_printer;
using namespace shape_printer::shape_extension;
using namespace shape_printer::output_extension;

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

    // print a diamond shape to a BMP file
    BMPCreator bmpCreator("diamond.bmp");
    bmpCreator.setColors(255, 0, 0, 255);   // red color
    printShape.setOutput(bmpCreator);
    printShape(20);

    return 0;
}
