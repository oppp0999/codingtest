/* 풀이
핵심 풀이는 다음과 같다.
1. dfs로 간선으로 연결된 노드들을 탐색해 연결된 노드들을 카운트한다.
2. 각 노드의 카운터 순으로 내림차순 정렬하고, 노드들의 카운터가 같다면 노드의 번호 순으로 오름차순 정렬한다.
문제를 해석하는 것이 어려웠는데 결국 숫자 두개가 주어질 때 두 번째 컴퓨터를 통해 첫 번째 컴퓨터를 해킹할 수 있다는 뜻이었습니다.
따라서 양방향이 아니라 방향 그래프이기 때문에 graph[node2].push_back(node1)을 하면 되고 재귀 호출 횟수가 최대인 노드를 순서대로 출력하면 되는 문제였습니다
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;
const int MAX = 10000 + 1;
int N, M;
vector<int> graph[MAX];
bool visited[MAX];
int cnt;

void DFS(int nodeNum)
{
        visited[nodeNum] = true;
        for (int i = 0; i < graph[nodeNum].size(); i++)
        {
                 int next = graph[nodeNum][i];
                 if (!visited[next])
                 {
                         cnt++;
                         DFS(next);
                 }
        }
}
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 속도 향상 위해
        cin >> N >> M;
        for (int i = 0; i < M; i++)
        {
                 int node1, node2;
                 cin >> node1 >> node2;
                 graph[node2].push_back(node1);
        }
        int nodeCnt = 0;
        vector<int> result;
        for (int i = 1; i <= N; i++)
        {
                 memset(visited, false, sizeof(visited));
                 cnt = 0;
                 DFS(i);
                 if (nodeCnt == cnt)
                         result.push_back(i);
                 if (nodeCnt < cnt)
                 {
                         nodeCnt = cnt;
                         result.clear();
                         result.push_back(i);
                 }
        }
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
                 cout << result[i] << " ";
        cout << endl;
       return 0;
}