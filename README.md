# Shape Printer

Shape Printer is a C++ project that allows you to generate and print various shapes to different output formats, such as the console and BMP files. The project includes several shape definitions and output extensions to demonstrate its capabilities.

## Project Structure

The project is organized as follows:

```
shape-printer/
├── inc/                        # Header files
│   ├── BMP.h
│   ├── BMPCreator.h
│   ├── Cross.h
│   ├── Diamond.h
│   ├── PrintShape.h
│   └── StreamOut.h
├── src/                        # Source files
│   ├── BMP.cpp
│   ├── BMPCreator.cpp
│   ├── Cross.cpp
│   ├── Diamond.cpp
│   ├── main.cpp
│   ├── PrintShape.cpp
│   └── StreamOut.cpp
├── test/                       # Test files
│   ├── main.cpp
│   └── PrintShapeTest.cpp
└── CMakeLists.txt              # CMake build script
```

## Features

- Define custom shapes using lambda functions or classes.
- Print shapes to the console or to BMP files.
- **Easily extendable to add new shapes and output formats**.

## Shapes

The project includes the following shapes:

- **Diamond**: A diamond shape defined by the sum of the absolute values of the coordinates.
- **Cross**: A cross shape defined by the coordinates being zero.
- **Image**: A image shape defined by boolean array.
- **BMP**: A bitmap shape defined in BMP file.

## Output Extensions

The project includes the following output extensions:

- **StreamOut**: Prints the shape to an output stream (e.g., console or file).
- **BMPCreator**: Generates a BMP file with the shape.

## Getting Started

### Prerequisites

- CMake 3.10 or higher
- A C++11 compatible compiler

### Building the Project

1. Clone the repository:
   ```sh
   git clone https://github.com/bosornd/shape-printer.git
   cd shape-printer
   ```
2. Create a build directory:
   ```sh
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```sh
   cmake ..
   ```
4. Build the project:
   ```sh
   cmake --build .
   ```

## Running the Application

After building the project, you can run the application by executing the generated executable in the build directory. The application will print shapes to the console, the file (output.txt), and the file (output.bmp).

### Example Usage

The `main.cpp` file demonstrates how to use the `PrintShape` class to print different shapes:

```cpp
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
```

## Running Tests

The project includes unit tests using Google Test. To run the tests, follow these steps:

1. Build the tests:
   ```sh
   cmake --build . --target shape-printer-tests
   ```
2. Run the tests:
   ```sh
   ctest
   ```

## License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.

Enjoy extending shapes and output formats!