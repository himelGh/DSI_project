#include "Store.h"
#include <iostream>
#include <iomanip>

#include <vector>
#include <string>


//using namespace std;



//implementations
//Store::Store()
//{
//}



void Store:: setOpcode(){ opCode = str;}

void Store::setOperand(std::vector<std::string> opname) {  operand = opname; }

void Store:: printStoreInfo()
{
    std::cout << "Op code : " << opCode <<"       Operand"<<endl;
    //cout << "operand       : " ;
    //cout << opCode << endl;
    for (auto &s: operand) {
        cout<<setw(25)<< s <<endl;
    }
    cout<<endl;

}
