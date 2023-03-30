#include <iostream>
#include <string>
using namespace std;

int map[26];
int main(){
    string s;
    cin >> s;

    fill(map, map+26, 0);
    int a;
    for(int i = 0; i<s.size(); i++){
        a = s[i] - 'a';
        map[a]++;
    }

    for(int a : map){
        cout << a << " ";
    }
}