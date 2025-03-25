#include <gtest/gtest.h>
#include <fstream>
#include "BMP.h"
#include "BMPCreator.h"

using namespace shape_printer::shape_extension;
using namespace shape_printer::output_extension;

// Helper function to create a test BMP file
void createTestBMP(const std::string& filename) {
    // Create a simple cross pattern
    std::vector<std::vector<bool>> imageData = {
        {false, false, true, false, false},
        {false, false, true, false, false},
        {true, true, true, true, true},
        {false, false, true, false, false},
        {false, false, true, false, false}
    };
    
    // Use BMPCreator to create the file
    BMPCreator creator(filename, 255, 0, 0, 255);
    creator(imageData);
}

// Test fixture that creates and removes a test BMP file
class BMPTest : public ::testing::Test {
protected:
    std::string testFilename = "test_image.bmp";
    
    void SetUp() override {
        // Create a test BMP file
        createTestBMP(testFilename);
    }
    
    void TearDown() override {
        // Remove the test file
        std::remove(testFilename.c_str());
    }
};

TEST_F(BMPTest, LoadBMP) {
    // Test that we can load the BMP without exceptions
    EXPECT_NO_THROW({
        BMP bmp(testFilename);
    });
}

TEST_F(BMPTest, InsideMethod) {
    BMP bmp(testFilename);
    
    // Check points that should be inside (part of the cross)
    EXPECT_TRUE(bmp.inside(0, 0, 3));   // Center
    EXPECT_TRUE(bmp.inside(0, 1, 3));   // Top vertical
    EXPECT_TRUE(bmp.inside(1, 0, 3));   // Right horizontal
    EXPECT_TRUE(bmp.inside(0, -1, 3));  // Bottom vertical
    EXPECT_TRUE(bmp.inside(-1, 0, 3));  // Left horizontal
    
    // Check points that should be outside (corners of the cross)
    EXPECT_FALSE(bmp.inside(1, 1, 3));   // Top-right
    EXPECT_FALSE(bmp.inside(-1, -1, 3)); // Bottom-left
    EXPECT_FALSE(bmp.inside(2, 2, 3));   // Far outside
}

TEST_F(BMPTest, GetSize) {
    BMP bmp(testFilename);
    
    // The image is 5x5, so size should be 5/2 + 1 = 3.5 -> 3
    EXPECT_EQ(bmp.getSize(), 3);
}

TEST(BMPExceptionTest, FileNotFound) {
    // Test that an exception is thrown when the file doesn't exist
    EXPECT_THROW({
        BMP bmp("nonexistent_file.bmp");
    }, std::runtime_error);
}

TEST(BMPExceptionTest, InvalidFile) {
    // Create an invalid BMP file (text file with .bmp extension)
    std::string invalidFilename = "invalid.bmp";
    std::ofstream invalidFile(invalidFilename);
    invalidFile << "This is not a valid BMP file";
    invalidFile.close();
    
    // Test that an exception is thrown or the program doesn't crash
    // when trying to load an invalid file
    EXPECT_ANY_THROW({
        BMP bmp(invalidFilename);
    });
    
    // Clean up
    std::remove(invalidFilename.c_str());
}

// Testing with different BMP variations
TEST(BMPVariationTest, TransparentPixels) {
    // Create a BMP with transparent pixels
    std::string filename = "transparent_test.bmp";
    std::vector<std::vector<bool>> imageData = {
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };
    
    // Use transparent foreground
    BMPCreator creator(filename, 255, 0, 0, 128);
    creator(imageData);
    
    // Test loading and inside checks
    BMP bmp(filename);
    EXPECT_TRUE(bmp.inside(0, 0, 2));   // Center (should be true despite transparency)
    EXPECT_FALSE(bmp.inside(0, 1, 2));  // Outside
    
    // Clean up
    std::remove(filename.c_str());
}
