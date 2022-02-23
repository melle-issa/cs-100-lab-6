#ifndef SELECT_NOT_HPP
#define SELECT_NOT_HPP

#include "select.hpp"
#include "spreadsheet.hpp"
#include <vector>
#include <iosfwd>
#include <initializer_list>
#include <iostream>
#include <string>
#include "Select_Contains.hpp"

class Select_Not: public Select{
    protected:
        Select *obj1;
    public:
	Select_Not(Select *arg1){
	    obj1 = arg1;
	}
        ~Select_Not(){
            delete obj1;
        }
        virtual bool select(const Spreadsheet *sheet, int row) const{
	    bool find = obj1->select(sheet,row);
            if(find == true){ // if it was found, we dont want it printed
                return false;
            }
            else{
                return true;
            }
       }
};

#endif
