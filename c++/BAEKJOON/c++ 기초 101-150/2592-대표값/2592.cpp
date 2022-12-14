#include <iostream>
using namespace std;

int main(){
    int a[10] = {0,};
    int b[10001] = {0,};
    int sum=0;
    int i=0;
    while(i<10){
        cin >> a[i];
        sum += a[i];
        b[a[i]]++; //배열 위치= 숫자 그 위치에 값을 증가시켜 최빈값을 만듦
        i++;
    }
    int max = 0;
    int c=0;
    for (int j=0; j<=10000; j++){
        if(b[j]>max){
            max = b[j];
            c=j;
        }
    }
    cout << sum/10<<'\n';
    cout << c;
    
}