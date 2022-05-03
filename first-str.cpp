
#include <iostream>
#include <string>
#include <regex>

using namespace std;


string GetResult(string instruction){

    //string instruction{"add a0, x0, x1"};
    //string instruction{"   mov  a0,   x0, x1 #  remove ggjhgh"};
    //Remove leading , traiing , extra spaces
    instruction = regex_replace(instruction, regex("^ +| +$|( ) +"), "$1");
    //Remove everything after #
    cout<<"ok"<<endl;
    int countC=instruction.find ("#");

    if(countC>=0)
       instruction.erase (countC, instruction [instruction.length() - 1]);
    cout<<instruction<<endl;


    //separation of opcode and operands
    int n =0;

    n = instruction.find_first_of( " \t", n );

    string first_n=instruction.substr(0,n);
    cout<<first_n<<endl;
    instruction.erase( 0,  instruction.find_first_not_of( " \t", n ) );

    //cout << '\"' << instruction << "\"\n";


    return instruction;
}



int main()
{
  string input{"add a0, x0, x1"};
  string ins;
  ins=GetResult(input);
  cout<<ins;


return 0;
}


