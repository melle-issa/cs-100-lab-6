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
	Select_Not(Select_Column *obj):Select_Column(){
	    column = obj->getCol();
	   // searchSheet = sheet;
	}
        Select_Not():Select_Column(){}
        
        virtual bool select(const std::string& s) const{
	    std::size_t result = searchValue.find(s);
	    if(result != std::string::npos){
 	        return true;
	    }
	    return false;
};

#endif
