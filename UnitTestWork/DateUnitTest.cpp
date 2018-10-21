#include "UrLib/myfile.h"
#include <gtest/gtest.h>


TEST(DateMultiplyTest , bdate)
{
    EXPECT_EQ (15952 , DateMultiply(4,2,1994));
}

TEST(DateMultiplyTest2 , bdate)
{
    EXPECT_EQ (15952, DateMultiply(22,8,1992));
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc , argv);
   return RUN_ALL_TESTS(); 
}
