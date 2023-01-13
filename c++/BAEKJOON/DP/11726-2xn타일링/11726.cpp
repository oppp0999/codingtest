#include <iostream>
using namespace std;

int DP[10007];

int main(){
    int a;
    cin >> a;
    DP[1]=1;
    DP[2]=2;
    
    for(int i=3; i<=a; i++){
        DP[i] = (DP[i-1]+DP[i-2]) % 10007;
    }
    cout << DP[a];
}

/* 모든 경우의 수를 한번 생각해보았다. 
n=1 > size 1 : 1개
n=2 > size 1: 2개 || size 2: 1개
n=3 > size 1: 3개 || size 1: 1개 + size 2: 2개 || size 1: 2개 + size 2: 1개 
n=4 > size 1: 4개 || size 1: 2개 + size 2: 2개(L) || size 1: 2개 + size 2: 2개(R) || size 1: 1개 + size 2: 2개 + size 1: 1개 
규칙이 보이지 않는가? 2xn 사이즈의 직사각형으로 채우려면 2x(n-1) 직사각형을 채우는 경우와 2x(n-2) 직사각형을 채우는 방법을 더하면 된다. */