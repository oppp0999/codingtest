#include <iostream>
using namespace std;
int a, i = 1;

int main() {
	for (cin >> a;a!=1; i++){
		a = a % 2 ? 3 * a + 1 : a / 2;
        //1이라면 홀수 , 0이라면 짝수
    }
	cout << i << endl;
}