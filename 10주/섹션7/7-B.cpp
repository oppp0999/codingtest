#include <iostream>
using namespace std;


int n, a[24][24], dp[24][24][3]; //가로, 대각, 세로

//옮길 수 있는지 체크
bool check(int y, int x, int d){ //행과 열로 체크 하기 에 y 고정후 x 위치.
    //가로 세로
    if(d ==0 || d == 2){
        if(!a[y][x]) return true;
    }
    else if(d==1){
        if(a[y][x]==0 && a[y-1][x]==0 && a[y][x-1] ==0) return true;
    }
    return false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++){ //0,0은 없고 1,1  부터 시작하기때문에 그냥 1, 1 로 시작
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1;//파이프가 차지하고있는 1과 2위치 방향은 0 (가로)
    for(int i =1; i<= n; i++){
        for(int j=1; j<=n; j++){
            //가로 체크
            if(check(i, j + 1, 0))dp[i][j+1][0] += dp[i][j][0];
            if(check(i + 1, j+1, 1))dp[i+1][j+1][1] += dp[i][j][0];
            //세로 체크
            if(check(i+1, j, 2))dp[i+1][j][2] += dp[i][j][2];
            if(check(i + 1, j+1, 1))dp[i+1][j+1][1] += dp[i][j][2];
            //대각선 체크
            if(check(i, j+1, 0))dp[i][j+1][0] += dp[i][j][1];
            if(check(i + 1, j, 2))dp[i+1][j][2] += dp[i][j][1];
            if(check(i + 1, j+1, 1))dp[i+1][j+1][1] += dp[i][j][1];
        }
    }

    int ret = dp[n][n][0]+dp[n][n][2]+dp[n][n][1];
    cout << ret << '\n';
}