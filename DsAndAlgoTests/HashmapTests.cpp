#include <gtest/gtest.h>
#include "..\Hashmaps\Hashmap.cpp"
#include <string>

TEST(HashmapTests, TEST_RREMOVEDUPS)
{
    auto map = new Hashmap();
    std::string str = "Krupachintanncachintanjoshikrupajani";
    std::string expected = "Krupachintjosk";

    std::string actual = map->removeDups(str);
    EXPECT_EQ(expected, actual);
};
