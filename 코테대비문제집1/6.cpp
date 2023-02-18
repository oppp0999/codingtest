#include <iostream>
#include <queue>

using namespace std;

string str;
queue<int>a;
queue<int>b;
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') a.push(i);
		else if (str[i] == 'B') {
			b.push(i);
		}
		else {
			if (!b.empty()) {
				b.pop();
				ans++;
			}
		}
	}
	while (a.size() && b.size()) {
		if (a.front() < b.front()) {
			ans++;
			a.pop();
			b.pop();
		}
		else {
			b.pop();
		}
	}
	cout << ans << '\n';
}