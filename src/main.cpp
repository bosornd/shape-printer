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
    // By default, it uses "*" for inside, " " for outside, and "\n" for end of line
    StreamOut streamOut;

    // DIFFERENT WAYS TO DEFINE A SHAPE:
    
    // Case 1: Using a lambda function to define the shape
    // The lambda checks if |x| + |y| < n (diamond shape)
    PrintShape printShape([](int x, int y, int n) { return std::abs(x) + std::abs(y) < n; }, streamOut);
    printShape(1);  // Output a diamond of size 1
    
    // Case 2: Using a standalone function
    // insideDiamond is defined in Diamond.cpp
    printShape.setInsideShape(insideDiamond);
    printShape(2);  // Output a diamond of size 2
    
    // Case 3: Using a functor (function object)
    // InsideDiamond is a class that overloads operator()
    printShape.setInsideShape(InsideDiamond());
    printShape(3);  // Output a diamond of size 3
    
    // Case 4: Using a class that extends Shape
    // Diamond implements the Shape interface with the inside method
    Diamond diamond;
    printShape.setInsideShape(diamond);
    printShape(4);  // Output a diamond of size 4
    
    // USING IMAGE AS A SHAPE:
    
    // Create an image representing a custom shape (a small diamond)
    Image image({{false, false, true, false, false},
                 {false, true, false, true, false},
                 {true, false, false, false, true},
                 {false, true, false, true, false},
                 {false, false, true, false, false}});
    printShape.setInsideShape(image);
    printShape(image.getSize());  // Use the image's natural size
    
    // CUSTOMIZING OUTPUT:
    
    // Change the characters used for printing
    // "O" for inside, "." for outside, "\n" remains the default for end of line
    streamOut.setCharacters("O", ".");
    printShape.setOutput(streamOut);
    printShape.setInsideShape(diamond);  // Back to the Diamond shape
    printShape(5);  // Output a diamond of size 5 with the new characters
    
    // OUTPUT TO BMP FILE:
    
    // Create a BMP file with a diamond shape
    BMPCreator bmpCreator("diamond.bmp");
    bmpCreator.setColors(255, 0, 0, 255);   // Set foreground color to red (R=255, G=0, B=0, A=255)
    printShape.setOutput(bmpCreator);
    printShape(20);  // Output a large diamond to the BMP file
    
    // LOADING FROM BMP:
    
    // Load the BMP file we just created and use it as a shape
    BMP bmp("diamond.bmp");
    printShape.setInsideShape(bmp);
    printShape.setOutput(streamOut);  // Back to console output
    printShape(bmp.getSize());  // Use the BMP's natural size
    
    // OUTPUT TO TEXT FILE:
    
    // Create a text file with a diamond shape
    std::ofstream file("diamond.txt");
    streamOut.setOutput(file);  // Redirect output to the file
    printShape.setOutput(streamOut);
    printShape(10);  // Output a diamond of size 10 to the file
    
    return 0;
}