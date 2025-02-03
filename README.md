# Shape Printer

Shape Printer is a C++ project that allows you to generate and print various shapes to different output formats, such as console and BMP files. The project includes several shape definitions and output extensions to demonstrate its capabilities.

## Features

- Define custom shapes using lambda functions or classes.
- Print shapes to the console or to BMP files.
- **Easily extendable to add new shapes and output formats**.

## Shapes

The project includes the following shapes:

- **Diamond**: A diamond shape defined by the sum of the absolute values of the coordinates.
- **Cross**: A cross shape defined by the coordinates being zero.
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
   ```
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```

## Running the Application

After building the project, you can run the application by executing the generated executable in the build directory. The application will print shapes to the console, the file(output.txt) and the file(output.bmp).

Enjoy extending shapes and output formats!