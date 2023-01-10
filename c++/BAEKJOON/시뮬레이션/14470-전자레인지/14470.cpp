#include <iostream>
using namespace std;

int main(){
    int A,B,C,D,E = 0;
    cin >> A >> B >> C >> D >> E;
    int cnt=0;
    int h=0;//해동안됨 : 0

    while(A!=B){
        if(A<0){
            A+=1;
            cnt+=C;
        }
        else if(A==0 && h==0){
            cnt+=D;
            h=1;
        }
        else {
            A+=1;
            cnt+=E;
        }
    }
    cout << cnt << '\n';
}