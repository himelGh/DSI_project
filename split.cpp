#include <iostream>
#include <regex>
#include <string>

using namespace std ;


vector<string> split_string(){

    string s = "a0, x0, x1 ";
    //regex regex("[ ]+");
    regex regex("[, ]+");

    vector<string> gather(
                    sregex_token_iterator(s.begin(), s.end(), regex, -1),
                    sregex_token_iterator()
                    );

    //vector<string>* out=&gather;
    return gather;

}









int main()
{
    vector<string> out = split_string();
    int element_count=0;

    for (auto &s: out) {
        element_count++;

        cout << s <<'.'<< endl;
    }


    cout<<element_count;
    return 0;
}
