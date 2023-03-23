#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int max_n = 104;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int n,m, a[max_n][max_n], visited[max_n][max_n];

void BFS(int y, int x){
    queue<pair<int, int> > q;
    visited[y][x] = 1;
    q.push(pair<int,int>(y,x));

    while(q.size()){
        int qy,qx;
        tie(qy, qx) = q.front();
        q.pop();

        for(int i =0; i<4; i++){
            int ny = qy + dy[i];
            int nx = qx + dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=m || a[ny][nx] == 0){
                continue;
            }
            if(visited[ny][nx]){continue;}
            visited[ny][nx] = visited[qy][qx] +1;
            q.push(pair<int,int>(ny,nx));
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    printf("%d", visited[n-1][m-1]);

}