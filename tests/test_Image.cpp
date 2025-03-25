#include <gtest/gtest.h>
#include "Image.h"

using namespace shape_printer::shape_extension;

TEST(ImageTest, Constructor) {
    // Create a simple 5x5 image of a plus sign
    std::vector<std::vector<bool>> imageData = {
        {false, false, true, false, false},
        {false, false, true, false, false},
        {true, true, true, true, true},
        {false, false, true, false, false},
        {false, false, true, false, false}
    };
    
    Image image(imageData);
    
    // Test that the image was constructed correctly by checking some points
    // Center of the plus should be inside
    EXPECT_TRUE(image.inside(0, 0, 3));
    // Corner should be outside
    EXPECT_FALSE(image.inside(-2, -2, 3));
}

TEST(ImageTest, InsideMethod) {
    std::vector<std::vector<bool>> imageData = {
        {false, true, false},
        {true, true, true},
        {false, true, false}
    };
    
    Image image(imageData);
    
    // Check points inside the image
    EXPECT_TRUE(image.inside(0, 0, 2));  // Center
    EXPECT_TRUE(image.inside(0, 1, 2));  // Top
    EXPECT_TRUE(image.inside(1, 0, 2));  // Right
    EXPECT_TRUE(image.inside(0, -1, 2)); // Bottom
    EXPECT_TRUE(image.inside(-1, 0, 2)); // Left
    
    // Check points outside the image
    EXPECT_FALSE(image.inside(1, 1, 2));   // Top-right
    EXPECT_FALSE(image.inside(-1, -1, 2)); // Bottom-left
    EXPECT_FALSE(image.inside(2, 0, 2));   // Far right
    EXPECT_FALSE(image.inside(-5, -5, 2)); // Far outside
}

TEST(ImageTest, GetSize) {
    // Test with square image
    std::vector<std::vector<bool>> squareImage = {
        {true, true, true},
        {true, true, true},
        {true, true, true}
    };
    Image square(squareImage);
    EXPECT_EQ(square.getSize(), 2); // 3/2 + 1 = 2.5 -> 2
    
    // Test with rectangular image (width > height)
    std::vector<std::vector<bool>> wideImage = {
        {true, true, true, true, true},
        {true, true, true, true, true}
    };
    Image wide(wideImage);
    EXPECT_EQ(wide.getSize(), 3); // 5/2 + 1 = 3.5 -> 3
    
    // Test with rectangular image (height > width)
    std::vector<std::vector<bool>> tallImage = {
        {true, true},
        {true, true},
        {true, true},
        {true, true},
        {true, true}
    };
    Image tall(tallImage);
    EXPECT_EQ(tall.getSize(), 3); // 5/2 + 1 = 3.5 -> 3
}
