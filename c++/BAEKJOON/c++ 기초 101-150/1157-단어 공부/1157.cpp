#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    char c;
    int sum[26]={0,}; //알파벳 개수만큼 배열을 생성 **배열 생성 중요 전부 0으로 초기화하는 작업!
    cin >> a;
    //cout << a.size();
    int i=0;
    int max=0;
    while(i<a.size()){
        if(a[i]>='a'){
            sum[a[i]-'a']++; //아스키코드
        }
        else{sum[a[i]-'A']++;//소문자는 -'a' 대문자는 -'A'
        }
        i++;
    }

    i=0;
    while(i<26){
        if(sum[i]==max){
            c='?';
        }
        else if(sum[i]>max){
            max=sum[i];
            c= i+'A';
        }
        i++;
    }
    cout << c;
}