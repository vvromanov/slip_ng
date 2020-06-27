#include "gtest/gtest.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    int retcode = RUN_ALL_TESTS();
    if (std::getenv("GTEST_RETURN_0")) {
        retcode = 0;
    }
    return retcode;
}
