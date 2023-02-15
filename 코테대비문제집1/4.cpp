#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10e9 + 1

using namespace std;

struct point {
	int pos;
	int color;
};

vector<point> v;

bool compare(const point& a, const point& b) {
	if (a.color != b.color)
		return a.color < b.color;
	return a.pos < b.pos;
}

void solve(int N) {
	long long sum = 0, front, back;

	for (int i = 0; i < N; i++) {

		//첫 번째 원소는 뒤에만 고려
		if (i == 0) {
			if (N >= 2 && v[i].color == v[i + 1].color)
				sum += (v[i + 1].pos - v[i].pos);
			continue;
		}

		//마지막 원소는 앞에만 고려
		if (i == N - 1) {
			if (v[i].color == v[i - 1].color)
				sum += (v[i].pos - v[i - 1].pos);
			break;
		}

		//나머지 원소: 앞, 뒤 둘 다 고려 + 색깔
		if (v[i].color != v[i - 1].color && v[i].color != v[i + 1].color)
			continue;

		if (v[i].color == v[i - 1].color)
			front = v[i].pos - v[i - 1].pos;
		else
			front = MAX; //냅다 젤 크게 잡아버리기

		if (v[i].color == v[i + 1].color)
			back = v[i + 1].pos - v[i].pos;
		else
			back = MAX;

		sum += min(front, back);
		
	}

	cout << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int N;
	cin >> N;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].pos >> v[i].color;

	sort(v.begin(), v.end(), compare);
	solve(N);

	return 0;
}