#include <gtest/gtest.h>
#include <sstream>
#include "StreamOut.h"

using namespace shape_printer::output_extension;

TEST(StreamOutTest, DefaultCharacters) {
    std::ostringstream oss;
    StreamOut streamOut(oss);

    std::vector<std::vector<bool>> image = {
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };

    streamOut(image);

    std::string expected = "* *\n * \n* *\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(StreamOutTest, CustomCharacters) {
    std::ostringstream oss;
    StreamOut streamOut(oss, "O", ".", "\n");

    std::vector<std::vector<bool>> image = {
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };

    streamOut(image);

    std::string expected = "O.O\n.O.\nO.O\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(StreamOutTest, SetCharacters) {
    std::ostringstream oss;
    StreamOut streamOut(oss);
    streamOut.setCharacters("O", ".", "\n");

    std::vector<std::vector<bool>> image = {
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };

    streamOut(image);

    std::string expected = "O.O\n.O.\nO.O\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(StreamOutTest, SetOutput) {
    std::ostringstream oss1, oss2;
    StreamOut streamOut(oss1);

    std::vector<std::vector<bool>> image = {
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };

    streamOut(image);
    std::string expected1 = "* *\n * \n* *\n";
    EXPECT_EQ(oss1.str(), expected1);

    streamOut.setOutput(oss2);
    streamOut.setCharacters("O", ".", "\n");
    streamOut(image);
    std::string expected2 = "O.O\n.O.\nO.O\n";
    EXPECT_EQ(oss2.str(), expected2);
}