#include <iostream>
using namespace std;

int main(){
    int a[11] = {0,};
    int n,k;
    cin >> n >> k;
    
    int sum=0;
    int i=0;
    while(i<n){
        cin >> a[i];
        i++;
    }

    //i 와 while i>=0 주의
    i=n-1;
    while(i>=0){
        if(k>=a[i]){
            sum += k / a[i];
            k = k % a[i];
        }
        i--;
    }
    cout << sum;
}