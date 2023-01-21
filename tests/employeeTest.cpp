#include "googletest-main/googletest/include/gtest/gtest.h"
#include "../include/employee.h"


// Demonstrate some basic assertions.
TEST(employeeTest, BasicAssertions) {

//    Employee* employee = new Employee();

EXPECT_STRNE("hello", "world");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
}

