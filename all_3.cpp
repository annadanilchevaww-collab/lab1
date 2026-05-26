#include <iostream>
#include <fstream>
#include <cctype>   
#include <cstdlib>  
using namespace std;

int main() {
    ifstream in("text.txt");
    ofstream out("end.txt");
    double product = 1.0;  
    bool found = false;     
    string num;            
    char ch;                

    while (in.get(ch)) {

        if (isdigit(ch)) {
            num += ch;
        }
        else if (ch == '-' && num.empty()) {
            num += ch;
        }

        else if (ch == '.' && num.find('.') == string::npos && !num.empty()) {
            num += ch;
        }
        else {
            if (!num.empty() && num != "-" && num != "." && num != "-.") {
                double val = atof(num.c_str()); 
                out << val << "\n";              
                product *= val;                    
                found = true;                   
            }
            num.clear();  
        }
    }
    if (!num.empty() && num != "-" && num != "." && num != "-.") {
        double val = atof(num.c_str());
        out << val << "\n";
        product *= val;
        found = true;
    }

    in.close();
    out.close();

    if (found) {
        cout <<"proizvedenie = " << product << endl;
    } else {
        cout << "no numbers" << endl;
    }

    return 0;