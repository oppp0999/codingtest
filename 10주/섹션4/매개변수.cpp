#include <iostream>
using namespace std;  
const int n = 4;
string a[4] = {"사과", "딸기", "포도", "배"};
void go(int num){
    cout << num;
	string ret = "";	
	for(int i = 0; i < 4; i++){
		if(num & (1 << i)) ret += a[i] + " ";
	}
	cout << ret << '\n';
	return;
}
int main() {    
	for(int i = 1; i < n; i++){
		go(1 | (1 << i));
	} 
    return 0;
} 