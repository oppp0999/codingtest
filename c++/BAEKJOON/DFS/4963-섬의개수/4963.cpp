#include <iostream>
#include <cstring>
using namespace std;

int map[50][50];
int visit[50][50];

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int w,h;

void dfs(int y, int x){
    for(int i=0; i< 8; i++){
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextX<0||nextY<0||nextX>=w||nextY>=h){continue;} //범위를 벗어나면 무시
        if(!visit[nextY][nextX]&&map[nextY][nextX]){ //이동할 좌표가 방문하지 않은 땅이면 재귀호출
            visit[nextY][nextX]=1;
            dfs(nextY,nextX);
        }
    }
}

int main(){
    while(1){
        int cnt=0;
        cin>>w>>h; // 크기 받기;
        
        if(!w&&!h){break;} //0,0 을 입력받았을 때 종료

        for(int i=0; i<h; i++){ //y값
            for(int j=0; j<w; j++){ //x값
                cin>>map[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visit[i][j]&&map[i][j]){
                    visit[i][j]=1;
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        memset(visit,0,sizeof(visit)); //map은 덮어써도 문제가 없을 것이라 판단하여 visit만 초기화해준다피
    }
}

/* 기존 미로찾기 문제의 경우에는 현재 좌표를 기준으로 상,하,좌,우가 길이고
그 곳을 방문하지 않았을 때 그 경로를 BFS면 큐를 통해 push하거나, DFS면 해당 경로를 인수로 담은 뒤 재귀호출하는데,
이번 섬의 개수 문제의 경우에는 현재 좌표를 기준으로 8방향 중 한 방향이 섬일 때 해당하는 알고리즘을 돌리면 된다. */