/* 1
cache[i] = cache[i-1] + cache[i-2] + cache[i-3]
i 가 1,2,3인 경우는 따로 처리해줘야 합니다. */

//반복문 사용

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;

    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 12; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}

//재귀 사용

#include <iostream>
#include <vector>
#include <cstring> // memset

using namespace std;

int n;
int cache[12];

int recur(int num)
{
    // 기저 사례
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    if (num == 3)
        return 4;
    // 메모이제이션
    if (cache[num] != -1)
        return cache[num];
    return cache[num] = recur(num - 1) + recur(num - 2) + recur(num - 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        // 캐시를 -1로 초기화
        memset(cache, -1, sizeof(cache));
        cout << recur(n) << '\n';
    }

    return 0;
}