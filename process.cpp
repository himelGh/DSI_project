#include <iostream>
#include "process.h"
#include <regex>
#include <tuple>

using namespace std;


string HashPart(string instruction){


    //string instruction{"   mov  a0,   x0, x1 #  remove ggjhgh"};
    //Remove leading , traiing , extra spaces
    instruction = regex_replace(instruction, regex("^ +| +$|( ) +"), "$1");
    //Remove everything after #
    int countC=instruction.find ("#");

    if(countC>=0)
       instruction.erase (countC, instruction [instruction.length() - 1]);

    //instruction.erase (instruction.find ("#"), instruction [instruction.length() - 1]);
    //cout<<instruction<<endl;
    return instruction;
}


tuple<string, string> SplitInstruction(string instruction){

    //separation of opcode and operands
    int n =0;
    n = instruction.find_first_of( " \t", n );

    string first_s=instruction.substr(0,n);
    //cout<<first_s<<endl;
    instruction.erase( 0,  instruction.find_first_not_of( " \t", n ) );

    if(instruction.back()==',') first_s="Nothing"   ;

    return {first_s,instruction};

}


vector<string> SplitOperand(string s){

    //string s = "a0, x0, x1 ";

    regex regex("[,]+");

    vector<string> gather(
                    sregex_token_iterator(s.begin(), s.end(), regex, -1),
                    sregex_token_iterator()
                    );

    return gather;

}




bool Validate(string opcode,int opcount)
{
    //Multi Map initialization
    multimap<string, int> mapData ={
            {"add", 3},
            {"sub", 3},
            {"addi", 3},
            {"subi", 3},
            {"la",   2},
            {"li",   2},
            {"ecall",0},


    };

    // Iterate over the multimap
    for (pair<string, int> elem : mapData){
        //cout << elem.first << " :: " << elem.second << endl;
        if(elem.first==opcode){
            if(elem.second==opcount)
                return true;
            else
                return false;
        }
    }
    return false;
}




