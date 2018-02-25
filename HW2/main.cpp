#include "run.h"
#include "gtest/gtest.h"
#include "tests.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    //run(); - use to start
}
