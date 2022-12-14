#include <iostream>
#include <string>

using namespace std;

int main(){
    int a;
    int c=0;
    int i=0;
    cin >> a;
    string b;
    cin >> b;

    //'0'을 빼서 아스키코드 값이1 실제 숫자 값
    while (i<a)
    {
        c+= b[i] - '0';
        i++;
    }
    cout << c;
}