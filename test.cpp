#include "spreadsheet.hpp"
#include "select.hpp"
#include "Select_Contains.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "gtest/gtest.h"
#include <sstream>
using namespace std;

TEST(SelectContains, containsAddedVal){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Contains(&testSheet,"Name","George"));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \n");
 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
