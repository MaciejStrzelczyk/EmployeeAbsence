#include "googletest-main/googletest/include/gtest/gtest.h"
#include "../include/employee.h"


// Demonstrate some basic assertions.
TEST(Employee, employee) {

//    Employee* employee = new Employee();

EXPECT_STRNE("hello", "word");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
EXPECT_STREQ("hello", "hello");
}

