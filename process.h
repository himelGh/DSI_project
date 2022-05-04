#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

#include <iostream>
#include <vector>


using namespace std;


string HashPart(string instruction);

tuple<string, string> SplitInstruction(string instruction);

vector<string> SplitOperand(string s);

bool Validate(string opcode,int opcount);




#endif // PROCESS_H_INCLUDED
