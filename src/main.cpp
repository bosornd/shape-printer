#include <iostream>
#include "Diamond.h"
#include "Cross.h"
#include "PrintShape.h"
#include "StreamOut.h"
#include "BMPCreator.h"
#include "BMP.h"

using namespace shape_printer;
using namespace shape_printer::shape_extension;
using namespace shape_printer::output_extension;

int main() {
    // Create a StreamOut object to print to the console
    StreamOut streamOut;

    // Case 1. print diamond shape using a lambda function
    PrintShape printShape([](int x, int y, int rows) {
        return std::abs(x) + std::abs(y) < rows;
    }, streamOut);
    std::cout << "Diamond using lambda function, size 1:\n";
    printShape(1);

    // Case 2. print diamond shape using insideDiamond function
    printShape.setInsideShape(insideDiamond); // defined in Diamond.h
    std::cout << "\nDiamond using insideDiamond function, size 2:\n";
    printShape(2);

    // Case 3. print diamond shape using InsideShape instance
    InsideDiamond insideDiamond;
    printShape.setInsideShape(insideDiamond);
    std::cout << "\nDiamond using InsideDiamond instance, size 3:\n";
    printShape(3);

    // Case 4. print diamond shape using Shape instance
    Diamond diamond;
    printShape.setInsideShape(diamond);
    std::cout << "\nDiamond using Diamond instance, size 4:\n";
    printShape(4);

    // Print diamond shape to a file using StreamOut
    std::ofstream file("output.txt");
    streamOut.set(file);
    streamOut.set('o');
    printShape.setOutputFunction(streamOut);
    std::cout << "\nDiamond written to output.txt, size 5:\n";
    printShape(5);
    file.close();

    // Print diamond shape to a BMP file using BMPCreator
    BMPCreator bmpCreator("output.bmp");
    bmpCreator.setColor(0xFF, 0, 0);        // Red color
    printShape.setOutputFunction(bmpCreator);
    std::cout << "\nDiamond written to output.bmp, size 10:\n";
    printShape(10);

    // Load diamond shape from BMP file and print to console
    BMP bmp("output.bmp");
    printShape.setInsideShape(bmp);
    streamOut.set(std::cout);
    printShape.setOutputFunction(streamOut);
    std::cout << "\nDiamond loaded from output.bmp:\n";
    printShape(bmp.getWidth() / 2 + 1);

    return 0;
}