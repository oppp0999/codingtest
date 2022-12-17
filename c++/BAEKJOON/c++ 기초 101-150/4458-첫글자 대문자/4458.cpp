//ignore()함수는 입력한 이후 입력버퍼를 지워주는 역할을 합니다.

#include <iostream>
#include <string>
using namespace std;

int main(){
    int c=0;
    string a;

    cin >> c;
    cin.ignore();

    while(c--){
        getline(cin,a);
        if(a[0]>= 'a' && a[0]<= 'z'){
            a[0] = a[0] - 32;}
        cout << a << endl;
        //std::endl 버퍼를 비우는 코드
    }

}