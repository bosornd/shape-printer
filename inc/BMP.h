#ifndef BMP_H
#define BMP_H

#include <string>
#include "Image.h"

namespace shape_printer {
namespace shape_extension {

class BMP : public Image {
public:
    BMP(const std::string& filename);

private:
    std::vector<std::vector<bool>> loadBMP(const std::string& filename) const;
};

} // namespace shape_extension
} // namespace shape_printer

#endif // BMP_H