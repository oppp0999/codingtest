#include <iostream>
using namespace std;

int main(){
    int time=0;
    int z;
    int k,n;

    cin >> k;
    cin >> n;

    while (n--)
    {
        int t;
        char ans;
        cin >> t >> ans;
        time += t;
        //3분 30초
        if(time>=210){
            cout << k;
            break;
        }
        if(ans =='T'){
            k++;
            if(k==9){k=1;}
        }
    }
     
}