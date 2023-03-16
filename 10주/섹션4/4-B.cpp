#include<bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

using namespace std;

int n,m,cnt;
char a[54][54];
int visited[54][54];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void BFS(int y, int x){
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int> > q;
    q.push(pair<int,int>(y,x));

    while(q.size()){
        tie(y,x)  = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m ){continue;}
            if(visited[ny][nx]){continue;} // -> ==1 로하니까 메모리 초과남;
            if(a[ny][nx] == 'W'){continue;}
            visited[ny][nx] = visited[y][x] + 1;
            q.push(pair<int,int>(ny,nx));
            cnt = max(cnt, visited[ny][nx]);
        }
    }
} 
int main(){

    cin >> n >> m;
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<n;  i ++){
        for(int j = 0; j<m; j++){
            if(a[i][j] == 'L'){
                BFS(i,j);
    for(              int  i=0; i<n; i++){
            }
        }
    }
    cout << cnt -1 << '\n';
}