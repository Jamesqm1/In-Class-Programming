#include <iostream>

#include <fstream>
#include <sstream>

using namespace std;


int main() {
    
    
    
    ifstream fin;
    cout << "Enter File to Copy from : ";
    string cf ="";
    cin >> cf;
    cout << endl;
    
    // ofstream fout;
    // cout << "Enter File to Copy to : ";
    // string sf ="";
    // cin >> sf;
    // cout << endl;
    
    
    fin.open(cf);
    // fout.open(sf);
    string x ="";
    string largest ="";
    string c = "";
    int lineof = -1;
    int cline =1;
    
    while (!fin.eof()) {
        getline(fin,x);
        istringstream sin(x);
        while(!sin.eof()){
            sin >> c;
            if(c.length()>largest.length()){
                lineof = cline;
                largest = c;
            }
        }
            cline= cline+1;
        
    }
    fin.close();
    cout << largest << " " << lineof << endl; 
    // fout.close();

    return 0;
}
