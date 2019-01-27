//James Mach

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
    cout << "Sieve of Eratosthenes\n" << "---------------------\n" << endl;
    cout << "Enter a maximum number :: ";
    
    unsigned long long int max;
    cin >> max;
    max++;
    cout << endl;
    
    vector<bool> primes(max,true);
    primes[0]=false;
    primes[1]=false;
    
    for(unsigned long long int i = 2; i <= max; i++){
        
        for(unsigned long long int j = i*2; j < max; j+=i){
            
            primes[j]=false;
            
        }
        
    }
    
    int digits = std::to_string(max).size();
    long printed = 0;
    
    for(unsigned long long int i = 0; i < max; i++){
        
        if(primes[i]){
            
            printf(" %*llu", digits, i);
            printed++;
            
            if(printed%10==0){
            
                cout << endl;
            
            }
            
        }
        
    }
    
    cout << endl << endl;
    cout << " There are a total of " << std::to_string(printed) << " primes";
    cout << " less than or equal to " << std::to_string(max-1) << "." << endl;
    
    return 0;
}