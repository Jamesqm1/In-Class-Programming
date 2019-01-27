#include <iostream>
using namespace std;

class foo {
    public:
        int x, y;
        char c;
    };


int main(){
    
    
    int arr[5];
int* p = arr;
p++;
cout << (p - arr) << endl;
}

