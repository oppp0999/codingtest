#include <iostream>
#include <string>
using namespace std;
 
int main() {
	string str = "";
	cin >> str;
 
	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
		
		if (i % 10 == 9) cout << endl; // 10개 출력 후 한 줄 내리기
	}
 
}