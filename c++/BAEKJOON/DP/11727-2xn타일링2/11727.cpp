/* dp 문제는 점화식 만드는 게 다다.
하지만 점화식 만드는 게 어렵다.
우선 n이 3일 땐, 2x3직사각형을 채워야 하는데, 이는
2x2직사각형에 2x1을 하나 더하는 것과,
2x1직사각형에 2x2을 하나 더하는 것, 1x2을 두 개 더하는 것,
총 3가지 경우가 있다.
따라서 dp[3]이 2x3직사각형을 만드는 방법의 수라고 하면, dp[2]+dp[1]+dp[1]과 같다.
dp[n] = dp[n-1]+dp[n-2]*2
 */


#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int dp[1000];
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < n; i++) {
        //3이라고 쳤을 때 3 = 1이 두개 + 2가 하나 필요해서 다음 식과 같다.
		dp[i] = (dp[i - 1] + dp[i - 2] * 2)%10007;
	}
	cout << dp[n-1];

	return 0;
}