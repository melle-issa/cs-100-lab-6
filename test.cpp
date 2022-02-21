#include "spreadsheet.hpp"
#include "select.hpp"
#include "Select_Contains.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "gtest/gtest.h"
using namespace std;

TEST(SelectContains, containsAddedVal){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City","Job"});
    testSheet.add_row({"George","26","Riverside","Teacher"});
    testSheet.add_row({"Percy","26","Seattle","President"});
    testSheet.add_row({"Amelia","26","New York City","Lawyer"});
    testSheet.set_selection(new Select_Contains(&testSheet,"Age","26"));
    testSheet.print_selection(std::cout);
    EXPECT_EQ(testSheet.getData().at(0).at(0), "George");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
