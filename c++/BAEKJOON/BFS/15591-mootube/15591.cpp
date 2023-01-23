/* Graph BFS
 a 동영상과 b 동영상의 relevant 값은 a에서 b로 가는 경로 중 간선의 값이 가장 작은 값이 됩니다. 우리는 k와 v가 주어질 때마다, v번 동영상에서 다른 모든 동영상까지 relevant 값이 k 이상인 동영상들을 count 해줘야합니다. 따라서, a 동영상에서 시작해서 BFS 탐색을 진행하면서 다른 모든 동영상과의 relevant 값을 구하면 되는데, a에서 어떤 동영상까지 탐색하는데 relevant 값이 주어진 k보다 작아진다면, 그 뒤의 탐색들도 다 k보다 relevant 값이 작아지므로 탐색을 마저 진행하지 않는다. */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, Q, p, q, r, k, v;
vector<pair<int, int> > map[5001];

int BFS(int k, int v) {
	int ans = 0;
	vector<bool> visited(5001, false);
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < map[cur].size(); i++) {
			int next = map[cur][i].first;
			int relev = map[cur][i].second;
			if (!visited[next] && k <= relev) {
				visited[next] = 1;
				q.push(next);
				ans++;
			}
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> q >> r;
		map[p].push_back({ q, r });
		map[q].push_back({ p, r });
	}
	for (int i = 0; i < Q; i++) {
		cin >> k >> v;
		cout << BFS(k, v) << '\n';
	}

	return 0;
}