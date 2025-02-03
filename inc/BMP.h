#ifndef BMP_H
#define BMP_H

#include "PrintShape.h"
#include <vector>
#include <string>
#include <fstream>

namespace shape_printer {
namespace shape_extension {

class BMP : public Shape {
public:
    BMP(const std::string& filename);

    bool inside(int x, int y, int rows) const override;
    int getWidth() const;
    int getHeight() const;

private:
    std::string filename;
    std::vector<std::vector<bool>> image;
    int width;
    int height;

    void loadBMP();
};

} // namespace shape_extension
} // namespace shape_printer

#endif // BMP_H