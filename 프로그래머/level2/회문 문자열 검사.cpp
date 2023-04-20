#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	int i = 1;
	while(n--){
		string input2;
		cin >> input2;
		string input;
		for(int k = 0; k<input2.size(); k++){
			input+= tolower(input2[k]);
		}
		
		if(input.size() % 2 == 0){
			string a = input.substr(0, input.size()/2);
			string b = input.substr(a.size(), input.size());
			reverse(b.begin(), b.end());
			
			if (a==b){
				cout << '#' <<i << " YES" << '\n';
			}
			else{
				cout << '#' << i << " NO" << '\n';
			}
			i++;
		}
		else{
			string a = input.substr(0, input.size()/2);
			string b = input.substr(a.size()+1, input.size());
			reverse(b.begin(), b.end());
			
			if (a==b){
				cout << '#' << i << " YES" << '\n';
			}
			else{
				cout << '#' << i << " NO" << '\n';
			}
			i++;
		}

	}
	return 0;
}

/* 
5
level
moon
abCBa
soon
gooG

#1 YES
#2 NO
#3 YES
#4 NO
#5 YES
 */