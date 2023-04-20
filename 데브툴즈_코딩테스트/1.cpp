#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void sol(int n){
    int i = 1;
        while(i < 4){
            for(int j=1; j<10; j++){
                for(int k = n; k<n+4; k++){
                    cout << k << " * " << j << " = " << k*j << " ";
                }
                i++;
                cout << '\n';
            }
        }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    
    sol(2);
    cout << '\n';
    sol(6);
    


    return 0;
}