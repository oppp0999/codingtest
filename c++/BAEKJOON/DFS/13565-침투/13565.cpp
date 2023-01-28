/* 
전류가 0행에서 시작 5행으로 갈 수 있다면 yes
0으로 이루어진 칸에 대해 dfs 시작
visited는 따로 필요없오 0으로 이루어진 칸을 방문했다면 2로 바꾸워주면 됨.
 */

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

int n,m;
string graph[MAX];
bool canFinish = false;
int dirXY[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int r, int c){
    graph[r][c] = '2';
    for(int dir =0; dir<4; dir ++){
        int nr = r+ dirXY[dir][0];
        int nc = c+dirXY[dir][1];
        if(nr==n){
            canFinish= true;
            return;
        }
        if(nr<0 || nc>=m || nc <0) {continue;}
        if(graph[nr][nc] != '0'){continue;}
        dfs(nr, nc);
    }
}


int main(){
    cin >> n >> m;

    for (int i=0; i< n; i++){
        cin >> graph[i];
    }
    for(int c = 0; c<m; c++){
        if (graph[0][c]=='0'){
            dfs(0,c);
            if(canFinish == true){
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}