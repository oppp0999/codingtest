#include <iostream>

using namespace std;

int dp[1001][10];
int N;
int main(){
    cin >> N;

    //초기값
    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }

    // a b c -> a<=b
    //             b<=c
    //ex) dp[4][2]는 dp[3][0] + dp[3][1] + dp[3][2]이다.
    //3까지 0이었다면 2를 선택할 수 있고 3까지 1이었다면 2를 선택할 수 있고
    //3까지 3이라면 2는 선택을 못하므로 제외
    for(int i=2; i<=N; i++){ //2로 쳤을 때
        for(int j = 0; j<=9; j++){
            for(int k = 0; k<=j; k++){
                dp[i][j] += dp[i-1][k]; //뒤오는 애들 k(0~7...등) , 다음수는 -1 갯수 
                dp[i][j] %= 10007;
            }
        }
    }

    //N에서 모든 개수는 0으로 끝나는 것부터 9로 끝나는 것 모두 합치면 됨.
    int ans = 0;
    for(int i=0; i<=9; i++){
        ans += dp[N][i];
        ans %= 10007;
    }
    cout << ans;
}