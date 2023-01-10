#include <iostream>
using namespace std;

int main(){
    int cnt=0;

    int N;
    cin >> N;

    while(N!=1){
        if((N%3) == 0){
            N=N/3;
        }
        else if((N%3) == 0){
            N=N/2;
        }
        else{
            N=N-1;
        }
        cnt++;
    }
    cout << cnt;
}