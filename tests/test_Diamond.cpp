#include <gtest/gtest.h>
#include "Diamond.h"

using namespace shape_printer::shape_extension;

TEST(DiamondTest, InsideDiamondFunction) {
    EXPECT_TRUE(insideDiamond(0, 0, 2));
    EXPECT_TRUE(insideDiamond(1, 0, 2));
    EXPECT_TRUE(insideDiamond(0, 1, 2));
    EXPECT_FALSE(insideDiamond(2, 0, 2));
    EXPECT_FALSE(insideDiamond(0, 2, 2));
}

TEST(DiamondTest, InsideDiamondFunctor) {
    InsideDiamond insideDiamondFunctor;
    EXPECT_TRUE(insideDiamondFunctor(0, 0, 2));
    EXPECT_TRUE(insideDiamondFunctor(1, 0, 2));
    EXPECT_TRUE(insideDiamondFunctor(0, 1, 2));
    EXPECT_FALSE(insideDiamondFunctor(2, 0, 2));
    EXPECT_FALSE(insideDiamondFunctor(0, 2, 2));
}

TEST(DiamondTest, DiamondClass) {
    Diamond diamond;
    EXPECT_TRUE(diamond.inside(0, 0, 2));
    EXPECT_TRUE(diamond.inside(1, 0, 2));
    EXPECT_TRUE(diamond.inside(0, 1, 2));
    EXPECT_FALSE(diamond.inside(2, 0, 2));
    EXPECT_FALSE(diamond.inside(0, 2, 2));
}