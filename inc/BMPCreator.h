#ifndef BMPCREATOR_H
#define BMPCREATOR_H

#include "PrintShape.h"
#include <vector>
#include <string>
#include <fstream>

namespace shape_printer {
namespace output_extension {

class BMPCreator : public Output {
public:
    BMPCreator(const std::string& filename);

    void operator()(const std::vector<std::vector<bool>>& image) const override;

private:
    std::string filename;

    void writeBMP(const std::vector<std::vector<bool>>& image) const;
};

} // namespace output_extension
} // namespace shape_printer

#endif // BMPCREATOR_H