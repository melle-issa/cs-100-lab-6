#ifndef SELECT_OR_HPP
#define SELECT_OR_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <vector>
#include <iosfwd>
#include <initializer_list>
#include <iostream>
#include <string>
#include "Select_Contains.hpp"

class Select_Or: public Select_Column{
    protected:
	//int column1;
	//int column2;
	std::string searchValue1;
	std::string searchValue2;
	Spreadsheet *searchSheet1;
	Spreadsheet *searchSheet2;
    public:
	Select_Or(Select_Contains *obj1, Select_Contains *obj2):Select_Column(obj1->getSpreadsheet(), obj1->getColumnName()){
	    searchSheet1 = obj1->getSpreadsheet();
	    searchSheet2 = obj2->getSpreadsheet();
	    searchValue1 = obj1->getSearchVal();
	    searchValue2 = obj2->getSearchVal();   
	}
	virtual bool select(const std::string& s)const{
	    std::size_t result1 = s.find(searchValue1);
	    std::size_t result2 = s.find(searchValue2);
	    if(result1 != std::string::npos || result2 != std::string::npos){
		return true;
	    }
	    return false;
	}

};

#endif
