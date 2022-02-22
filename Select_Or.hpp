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

class Select_Or: public Select_Contains{
    protected:
	//int column1;
	//int column2;
	std::string searchValue1;
	std::string searchValue2;
	Spreadsheet *searchSheet1;
	Spreadsheet *searchSheet2;
    public:
	Select_Or(Select_Contains *obj1, Select_Contains *obj2):Select_Contains(obj1->getSheet(), obj1->getColumnName(), obj1->getSearchVal()){
	    Select_Contains *testContains = new Select_Contains(obj2->getSheet(), obj2->getColumnName(), obj2->getSearchVal());
	    searchValue1 = obj1->getSearchVal();
	    searchValue2 = obj2->getSearchVal();
	   // std::cout << obj1->getColumnName() << " " << obj2->getColumnName() << std::endl;	
	//std::cout << testContains->getSearchVal() << std::endl;	   
	}
	virtual bool select(const std::string& s)const{
	    std::size_t result1 = s.find(searchValue1);
	    std::size_t result2 = s.find(searchValue2);
	    //std::cout << searchValue1 << " " << searchValue2 << std::endl;
	    if(result1 != std::string::npos || result2 != std::string::npos){
		return true;
	    }
	    return false;
	}

};

#endif
