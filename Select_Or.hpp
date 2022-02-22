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

class Select_Or: public Select{
    protected:
        Select *obj1;
        Select *obj2;	
    public:
	Select_Or(Select *arg1, Select *arg2){
            obj1 = arg1;
            obj2 = arg2;
	}
        virtual bool select(const Spreadsheet *sheet, int row) const{
           bool find1 = obj1->select(sheet,row);
           bool find2 = obj2->select(sheet,row);
           if(find1 == true || find2 == true){
               return true;
           }
        }
};

#endif
