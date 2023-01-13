
#include <iostream>
#include <queue>
using namespace std;
 
const int MAX = 1001;
int N, M;
int map[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };
queue<int> q;
 
void BFS(int v) {
    q.push(v);
    visited[v] = true;
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
 
        for (int i = 1; i <= N; i++) {
            if (map[v][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = true; //최종 결과는 방문 했다는 값으로 바꿈
            }
        }
    }
}
 
int main() {
    cin >> N >> M;
 
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        map[u][v] = 1;
        map[v][u] = 1;
    }
 
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            BFS(i);
            cnt++;
        }
    }
 
    cout << cnt << endl;
}
