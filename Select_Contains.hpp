#ifndef SELECT_CONTAINS_HPP
#define SELECT_CONTAINS_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <vector>
#include <iosfwd>
#include <initializer_list>
#include <iostream>
#include <string>

class Select_Contains: public Select_Column{
    protected:
	int column;
	std::string searchValue;
	Spreadsheet* searchSheet;
    public:
	Select_Contains(Spreadsheet* sheet, const std::string string1, const std::string string2):Select_Column(sheet, string1){
	    column = sheet->get_column_by_name(string1);
	    searchValue = string2;
	    searchSheet = sheet;
	}
        virtual bool select(const std::string& s) const{
             std::size_t result = s.find(searchValue);
	     if(result != std::string::npos){
                // std::cout << std::endl << s << std::endl;
	         return true;
             }
             else{
	         return false;
             }        	
        }

};

#endif
