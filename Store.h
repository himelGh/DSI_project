
//#ifndef STORE_H
//#define STORE_H
#pragma once
#include<iostream>
using namespace std;

#include <string>
#include <vector>

class Store
{
    private:
		string opCode;
        vector<string> operand;

    public:
        //Store();
        //~Store(){}
        void setOpcode(string );
        void setOperand(vector<string> );
        void printStoreInfo();


};
//#endif
