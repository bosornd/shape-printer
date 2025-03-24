#ifndef BMPCREATOR_H
#define BMPCREATOR_H

#include <vector>
#include <string>
#include "PrintShape.h"

namespace shape_printer {
namespace output_extension {

class BMPCreator : public Output {
    std::string filename;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;

public:
    BMPCreator(const std::string& filename, unsigned char red = 255, unsigned char green = 255, unsigned char blue = 255, unsigned char alpha = 255);

    void operator()(const std::vector<std::vector<bool>>& image) const override;

    void setColors(unsigned char red = 255, unsigned char green = 255, unsigned char blue = 255, unsigned char alpha = 255);

private:
    void saveBMP(const std::vector<std::vector<bool>>& image) const;
};

} // namespace output_extension
} // namespace shape_printer

#endif // BMPCREATOR_H