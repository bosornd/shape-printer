#include <iostream>
#include <functional>
#include <fstream>
#include <vector>
#include "PrintShape.h"
#include "Diamond.h"
#include "StreamOut.h"
#include "BMPCreator.h"
#include "Image.h"
#include "BMP.h"

using namespace shape_printer;
using namespace shape_printer::shape_extension;
using namespace shape_printer::output_extension;

int main() {
    // Create a StreamOut instance for console output
    StreamOut streamOut;

    // case 1. print a diamond shape using lambda function
    PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; }, streamOut);

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

    // print a shape using Image class
    Image image({{false, false, true, false, false},
                 {false, true, false, true, false},
                 {true, false, false, false, true},
                 {false, true, false, true, false},
                 {false, false, true, false, false}});
    printShape.setInsideShape(image);
    printShape(image.getSize());

    // change printing characters
    streamOut.setCharacters("O", ".");
    printShape.setOutput(streamOut);
    printShape.setInsideShape(diamond);
    printShape(5);

    // print a diamond shape to a BMP file
    BMPCreator bmpCreator("diamond.bmp");
    bmpCreator.setColors(255, 0, 0, 255);   // red color
    printShape.setOutput(bmpCreator);
    printShape(20);

    // print a shape using BMP class
    BMP bmp("diamond.bmp");
    printShape.setInsideShape(bmp);
    printShape.setOutput(streamOut);
    printShape(bmp.getSize());

    // print a diamond shape to a file
    std::ofstream file("diamond.txt");
    streamOut.setOutput(file);
    printShape.setOutput(streamOut);
    printShape(10);
    
    return 0;
}