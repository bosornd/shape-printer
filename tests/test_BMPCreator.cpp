#include <gtest/gtest.h>
#include <fstream>
#include "BMPCreator.h"
#include "BMP.h"

using namespace shape_printer::shape_extension;
using namespace shape_printer::output_extension;

class BMPCreatorTest : public ::testing::Test {
protected:
    std::string testFilename = "creator_test.bmp";
    
    void TearDown() override {
        // Clean up test file after each test
        std::remove(testFilename.c_str());
    }
};

TEST_F(BMPCreatorTest, CreateBMP) {
    // Simple test pattern - a 3x3 grid with diagonal pixels set
    std::vector<std::vector<bool>> imageData = {
        {true, false, false},
        {false, true, false},
        {false, false, true}
    };
    
    // Create the BMP file
    BMPCreator creator(testFilename);
    EXPECT_NO_THROW(creator(imageData));
    
    // Verify the file was created
    std::ifstream file(testFilename);
    EXPECT_TRUE(file.good());
}

TEST_F(BMPCreatorTest, VerifyContent) {
    // Create a simple pattern with BMPCreator
    std::vector<std::vector<bool>> imageData = {
        {true, false, true},
        {false, true, false},
        {true, false, true}
    };
    
    // Create the BMP with default colors
    BMPCreator creator(testFilename);
    creator(imageData);
    
    // Load the created BMP and verify the pattern is preserved
    BMP bmp(testFilename);
    
    // Test for true pixels
    EXPECT_TRUE(bmp.inside(-1, 1, 2));  // Top-left
    EXPECT_TRUE(bmp.inside(1, 1, 2));   // Top-right
    EXPECT_TRUE(bmp.inside(0, 0, 2));   // Center
    EXPECT_TRUE(bmp.inside(-1, -1, 2)); // Bottom-left
    EXPECT_TRUE(bmp.inside(1, -1, 2));  // Bottom-right
    
    // Test for false pixels
    EXPECT_FALSE(bmp.inside(0, 1, 2));  // Top-center
    EXPECT_FALSE(bmp.inside(-1, 0, 2)); // Middle-left
    EXPECT_FALSE(bmp.inside(1, 0, 2));  // Middle-right
    EXPECT_FALSE(bmp.inside(0, -1, 2)); // Bottom-center
}

TEST_F(BMPCreatorTest, CustomColors) {
    std::vector<std::vector<bool>> imageData = {
        {true, true},
        {true, true}
    };
    
    // Create BMP with red foreground
    BMPCreator creator(testFilename);
    creator.setColors(255, 0, 0, 255);  // bright red
    creator(imageData);
    
    // Verify file exists with correct size
    std::ifstream file(testFilename, std::ios::binary);
    EXPECT_TRUE(file.good());
    
    // Skip to the pixel data (54 bytes header)
    file.seekg(54);
    
    // Read first pixel (BGRA format)
    unsigned char pixel[4];
    file.read(reinterpret_cast<char*>(pixel), 4);
    
    // Check if it's red (BGRA format: B=0, G=0, R=255)
    EXPECT_EQ(pixel[0], 0);    // Blue
    EXPECT_EQ(pixel[1], 0);    // Green
    EXPECT_EQ(pixel[2], 255);  // Red
    EXPECT_EQ(pixel[3], 255);  // Alpha
}

TEST_F(BMPCreatorTest, TransparencyTest) {
    std::vector<std::vector<bool>> imageData = {
        {true, false},
        {false, true}
    };
    
    // Create BMP with semi-transparent green
    BMPCreator creator(testFilename);
    creator.setColors(0, 255, 0, 128);  // semi-transparent green
    creator(imageData);
    
    // Verify file exists
    std::ifstream file(testFilename, std::ios::binary);
    EXPECT_TRUE(file.good());
    
    // Skip to the pixel data
    file.seekg(54);
    
    // Read first pixel (should be semi-transparent green)
    unsigned char pixel[4];
    
    // First pixel is true, so it should be green with 50% transparency
    file.read(reinterpret_cast<char*>(pixel), 4);
    EXPECT_EQ(pixel[0], 0);    // Blue
    EXPECT_EQ(pixel[1], 255);  // Green
    EXPECT_EQ(pixel[2], 0);    // Red
    EXPECT_EQ(pixel[3], 128);  // Alpha (semi-transparent)
    
    // Second pixel is false, so it should be transparent black
    file.read(reinterpret_cast<char*>(pixel), 4);
    EXPECT_EQ(pixel[0], 0);  // Blue
    EXPECT_EQ(pixel[1], 0);  // Green
    EXPECT_EQ(pixel[2], 0);  // Red
    EXPECT_EQ(pixel[3], 0);  // Alpha (fully transparent)
    
    // Third pixel is false, so it should be transparent black
    file.read(reinterpret_cast<char*>(pixel), 4);
    EXPECT_EQ(pixel[0], 0);  // Blue
    EXPECT_EQ(pixel[1], 0);  // Green
    EXPECT_EQ(pixel[2], 0);  // Red
    EXPECT_EQ(pixel[3], 0);  // Alpha (fully transparent)
    
    // Fourth pixel is true, so it should be green with 50% transparency
    file.read(reinterpret_cast<char*>(pixel), 4);
    EXPECT_EQ(pixel[0], 0);    // Blue
    EXPECT_EQ(pixel[1], 255);  // Green
    EXPECT_EQ(pixel[2], 0);    // Red
    EXPECT_EQ(pixel[3], 128);  // Alpha (semi-transparent)
}

TEST_F(BMPCreatorTest, LargeImage) {
    // Create a larger image (20x20)
    const int size = 20;
    std::vector<std::vector<bool>> imageData(size, std::vector<bool>(size, false));
    
    // Set a diagonal pattern
    for (int i = 0; i < size; i++) {
        imageData[i][i] = true;
        imageData[i][size-i-1] = true;
    }
    
    // Create BMP
    BMPCreator creator(testFilename);
    EXPECT_NO_THROW(creator(imageData));
    
    // Load and verify size
    BMP bmp(testFilename);
    EXPECT_EQ(bmp.getSize(), size/2 + 1);  // 20/2 + 1 = 11
}
