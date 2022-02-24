#include "spreadsheet.hpp"
#include "select.hpp"
#include "Select_And.hpp"
#include "Select_Not.hpp"
#include "Select_Or.hpp"
#include "Select_Contains.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "gtest/gtest.h"
#include <sstream>
using namespace std;

//ask about repeated sheets

TEST(SelectContains, searchForString){
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

TEST(SelectContains, searchForEmptyString){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Contains(&testSheet,"Age",""));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \nPercy 26 Seattle \nAmelia 26 New York City \n");
}

TEST(SelectContains, searchForSubstring){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Contains(&testSheet,"City","t"));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "Percy 26 Seattle \nAmelia 26 New York City \n");
}

TEST(SelectContains, testSelectNot){ // where the output is nothing
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Not(new Select_Contains(&testSheet, "Age","26")));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "");
}

TEST(SelectContains, testSelectAnd){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_And(new Select_Contains(&testSheet, "Name","G"), new Select_Contains(&testSheet, "City","r")));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \n");
}

TEST(SelectContains, testSelectOr){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Or(new Select_Contains(&testSheet, "Name", "Amelia"), new Select_Contains(&testSheet, "City", "e")));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \nPercy 26 Seattle \nAmelia 26 New York City \n"); 
}

TEST(SelectContains, testSelectNotOr){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Not(new Select_Or(new Select_Contains(&testSheet, "Name", "a"), new Select_Contains(&testSheet, "Name", "y"))));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \n");
}

TEST(Select_Contains, testUpperCase){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Not(new Select_Contains(&testSheet, "City", "R")));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "Percy 26 Seattle \nAmelia 26 New York City \n");
}

TEST(Select_Contains, testLowerCase){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Contains(&testSheet, "City", "s"));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \n");
}

TEST(Select_Column, testNewColumn){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Age","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    EXPECT_THROW(new Select_Contains(&testSheet, "Last Name", "26"), std::invalid_argument);
}

TEST(Select_Column, testSameColumn){
    Spreadsheet testSheet;
    testSheet.set_column_names({"Name","Name","City"});
    testSheet.add_row({"George","26","Riverside"});
    testSheet.add_row({"Percy","26","Seattle"});
    testSheet.add_row({"Amelia","26","New York City"});
    testSheet.set_selection(new Select_Contains(&testSheet, "Name", "e"));
    std::stringstream output;
    testSheet.print_selection(output);
    EXPECT_EQ(output.str(), "George 26 Riverside \nPercy 26 Seattle \nAmelia 26 New York City \n");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
