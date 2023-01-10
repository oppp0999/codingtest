#include<iostream>
#include<algorithm>
using namespace std;
int dp[10000001];

    /*
    DP는 bottom-up 방식이다.
    bottom-up이란 기본적인 값들은 미리 구해놓고 순차적으로 계산하는 것이다.
    */
   //즉 이 점화식은 1일땐 0이고 /3, /2, -1 은 횟수+1이다. 그렇기에 기본적인 값들을 구하고 시작.

int main()
{
	int x;
	cin >> x;
	
	for (int i = 2; i <= x; i++) {
		
		//1을 빼는 경우
		dp[i] = dp[i - 1] + 1;
		//2로 나눠지는 경우
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		//3으로 나눠지는 경우
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	//for (int i = 0; i < 10; i++){
	//	cout << dp[i];
    //}
	cout << dp[x] << '\n';
}