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
	std::string searchValue;
    public:
	Select_Contains(const Spreadsheet* sheet, const std::string string1, const std::string string2):Select_Column(sheet, string1){
	    searchValue = string2;
	}
        ~Select_Contains(){   }
        virtual bool select(const std::string& s) const{
             std::size_t result = s.find(searchValue);
	     if(result != std::string::npos || searchValue == ""){
	         return true;
             }
             else{
	         return false;
             }        	
        }
};

#endif
