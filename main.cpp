#include <iostream>
#include <fstream>
#include <iomanip>
#include "Store.h"
#include "process.cpp"
#include <tuple>


#include <vector>
#include <string>
#include <regex>

using namespace std;

string HashPart(string instruction);

tuple<string, string> SplitInstruction(string instruction);

vector<string> SplitOperand(string s);

bool Validate(string opcode,int opcount);

/*

class Store
{
    private:
		string opCode;
        vector<string> operand;

    public:
        Store();
        ~Store(){}
        void setOpcode(string str){ opCode = str;}
        void setOperand(vector<string> opname) {  operand = opname; }
        void printStoreInfo();


};
//implementations
Store::Store()
{
}



void Store:: printStoreInfo()
{
    cout << "Op code : " << opCode <<"       Operand"<<endl;
    //cout << "operand       : " ;
    //cout << opCode << endl;
    for (auto &s: operand) {
        cout<<setw(25)<< s <<endl;
    }
    cout<<endl;

}


*/


int main()
{

    fstream newfile;

    newfile.open("tpoint.txt",ios::in); //open a file to perform read operation using file object

    if (newfile.is_open()){   //checking whether the file is open
        string instruction;

        cout << "operator code   |   " << "operand  " << endl;
        cout<<"---------------------------------------"<<endl;

        while(getline(newfile, instruction)){ //read data from file object and put it into string.

            //cout << instruction << "\n"; //print the data of the string
            instruction = HashPart(instruction);

            auto [str1, str2] = SplitInstruction(instruction);



           vector<string> out = SplitOperand(str2);
           int element_count=0;

           if(str2.length()>0){
               for (auto &st: out) {
                   element_count++;
                   //cout << st <<'.'<< endl;
               }
           }
           //cout<<"element:  "<<element_count<<"     str1:"<<str1<<"    str2:"<<str2<<endl;

           bool v_info = Validate(str1,element_count);


           if (v_info == false) {
              continue;
           }

           vector<Store> list;

           Store *f1;

           f1 = new Store;

           f1->setOpcode(str1);
           f1->setOperand(out);
           list.push_back(*f1);

           // Now setup an iterator loop through the vector
           vector<Store>::iterator it;

           for ( it = list.begin(); it != list.end(); ++it ) {
         // For each Store, print out their info
               it->printStoreInfo();
           }

       }
       newfile.close(); //close the file object.
   }
    return 0;
}
