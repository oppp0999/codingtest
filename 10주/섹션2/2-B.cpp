#include <iostream>
#include <cstring>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n, m,k, cnt,t;
int n1, m1;
int map[54][54];
int visited[54][54];

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i =0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny<0 || ny >=m || nx < 0 || nx >= n){continue;}
        if(map[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny,nx);
        }
    }
    return;
}
int main(){
    cin >> t;

    while(t--){
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cin >> n >> m >> k;
        for(int j=0; j<k; j++){
            cin >> n1 >> m1;
            map[m1][n1] = 1;
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(map[i][j]==1 && !visited[i][j]){
                dfs(i,j);
                cnt++;}
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}