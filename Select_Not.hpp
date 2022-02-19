#ifndef SELECT_NOT_HPP
#define SELECT_NOT_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <vector>
#include <iosfwd>
#include <initializer_list>
#include <iostream>
#include <string>

class Select_Not: public Select_Column{
    protected:
	int column;
	std::string searchValue;
	Spreadsheet* searchSheet;
    public:
	Select_Not(Select_Column *obj):Select_Column(sheet, string1){
	    column = sheet->get_column_by_name(string1);
	    searchValue = string2;
	    searchSheet = sheet;
	}
        virtual bool select(const std::string& s) const{
	    if(row.at(column).find(s) != std::npos){
		return true;
	    }
	    
	}
};

#endif
