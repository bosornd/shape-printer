#ifndef PRINTSHAPE_H
#define PRINTSHAPE_H

#include <functional>
#include <vector>

namespace shape_printer {

class InsideShape {
public:
    virtual bool operator()(int x, int y, int rows) const = 0;
};

class Shape {
public:
    virtual bool inside(int x, int y, int rows) const = 0;
};

class Output {
public:
    virtual void operator()(const std::vector<std::vector<bool>>& image) const = 0;
};

class PrintShape {
public:
    PrintShape(std::function<bool(int, int, int)> insideShape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction);
    PrintShape(const Shape& shape, std::function<void(const std::vector<std::vector<bool>>&)> outputFunction);

    void setInsideShape(std::function<bool(int, int, int)> newInsideShape);
    void setInsideShape(const Shape& shape);

    void setOutputFunction(std::function<void(const std::vector<std::vector<bool>>&)> outputFunction);

    void operator()(int rows) const;

private:
    std::function<bool(int, int, int)> insideShape;
    std::function<void(const std::vector<std::vector<bool>>&)> output;
};

} // namespace shape_printer

#endif // PRINTSHAPE_H