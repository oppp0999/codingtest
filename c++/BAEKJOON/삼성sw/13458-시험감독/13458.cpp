// 약 백만*백만 = 일조 이므로, long long 타입으로 선언해줬다.
// 32비트 int, 64비트 long long


#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, b, c;
	vector<int> a;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	scanf("%d %d", &b, &c);

	long long ans = 0;

    
	for(int i = 0; i < a.size(); ++i) {
		int k = 1;
		if (a[i] > b) {
			k += (a[i] - b) / c; //최솟값은 1. 응시자의 수에서 1(=총 감독관)을 뺀 수를 C 로 나눈 만큼 더해주고, 나머지가 있다면 1을 더 더해주면 된다.
			if ((a[i] - b) % c > 0)
				k += 1;
		}
		ans += k;
	}
	printf("%lld\n", ans);
	return 0;
}

//(응시생 수 - 총감독관 수) / 부감독관 수 한 값을 구해 필요한 부감독관 수를 구했습니다.
//이 때, 총 감독관 수 1명을 더해줬으며, 위의 값이 나누어떨어지지 않는 경우에 부감독관 수가 몫보다 1명 더 필요하므로 추가로 1명을 더해줬습니다.