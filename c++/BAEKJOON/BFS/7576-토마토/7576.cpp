/* 토마토 창고 크기 m x n을 입력
m x n 크기의 창고에서 각각의 상태(1,0,-1)를 배열에 저장한다. 그리고 토마토가 익은상태(1)는 queue에 바로 넣는다.
BFS 알고리즘을 통해 탐색을 진행하는데, 익은 토마토(1)의 상하좌우의 4방향을 탐색하게 되고, 각각의 상태가 토마토 창고의 크기를 안벗어나면서 안익은 상태(0)라는 조건에 해당된다면 탐색한 칸 = 이미 익은토마토(1) + 1을 하게 된다. 즉, 이미 익은 토마토는 1이고 날짜가 하루 지나면 1+1, 그 다음날은 2 + 1이 되는 형태이다.
BFS 탐색이 끝나고 최종적인 상태에서,
만약 토마토 창고 내부에 아직도 익지않은 토마토(0)이 존재한다면 토마토가 들어있지 않은 칸(-1)으로 인해 토마토가 전부 익지 못하는 상황이므로 -1을 출력한다.
반대로 모든 토마토는 다 익었을때, 배열의 값에 따라 날짜가 결정이 되는데, 배열안에 가장 큰 값이 1이라면 앞서 말한 조건(안익은 상태라면)을 만족못해서 한번도 +1이 되지않아 기본 값(익어있는 상태)인 1에서 고정된다. 즉, 전체가 초기부터 익어있다고 볼 수 있다. 그래서 0을 출력한다.
마지막으로 배열안에 가장 큰 값이 1보다 크다면 해당 배열 값 - 1이 전체가 다 익는데 걸린 날이라고 볼 수 있다. 여기서 -1은 기본 값이 1부터 시작하므로 마지막에는 1을 빼줘야한다.  */

#include <iostream>
#include <queue>
using namespace std;
 
const int MAX = 1001;
int M, N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int path[MAX][MAX];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int,int> > q;
 
void printPath() {
    printf("\n[PATH]\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", path[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
void BFS() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                path[ny][nx] = path[y][x] + 1;
            }
        }
    }
 
}
 
int main() {
    cin >> M >> N;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
 
    /*익은 토마토를 찾아 BFS의 출발지로 queue에 삽입*/
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }
    BFS();
 
    //printPath();
 
    /*익지 않은 토마토 존재하면 -1 출력*/
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && path[i][j]==0) { //익지 않음 토마토가 있으나 방문한적 없음
                cout << -1;
                return 0;
            }
        }
    }
 
    /*방문 일자 저장 배열 중 최대값 출력*/
    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (path[i][j] > ans) {
                ans = path[i][j];
            }
        }
    }
    cout << ans;
 
}