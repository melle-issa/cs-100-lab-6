#ifndef SELECT_OR_HPP
#define SELECT_OR_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <vector>
#include <iosfwd>
#include <initializer_list>
#include <iostream>
#include <string>

class Select_Or: public Select_Column{
    protected:
	int column;
	std::string searchValue;
	Spreadsheet * searchSheet;
    public:
	Select_Or(Select_Contains *obj1, Select_Contains *obj2){

	}

};

#endif
