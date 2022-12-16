#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
	getline(cin, a);
    //cout << a;
    //cin >> a; -> getlinge으로 받는 이유는 공백때문에 string이 한 문단만 받아지기때문
    // 하지만 string으로 입력을 받게 될 경우 공백을 만나게 될경우 공백이전까지의 값이 저장이 됩니다.
    //getline()을 사용하여 입력을 받거나 str.get()으로 입력을 받을 수 있습니다.  

    int i=0;
    while (i<a.size()){
        if(a[i]>='a' && a[i]<='z'){
            if((a[i] - 'a') < 13){
                a[i]=a[i]+13;
            }
            else {
                a[i]=a[i]-13;
            }
        }
        else if(a[i]>='A' && a[i]<='Z'){
            if((a[i] - 'A') < 13){
                a[i]=a[i]+13;
            }
            else {
                a[i]=a[i]-13;
            }
        }
        i++;
    }

    cout << a;
}