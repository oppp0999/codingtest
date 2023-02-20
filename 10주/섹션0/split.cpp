#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string input, string d){
    vector<string> ret;
    long long pos = 0;
    string token = "";//빈 문자 변수
    while((pos= input.find(d))!= string::npos){
        token = input.substr(0,pos);
        ret.push_back(token);
        input.erase(0, pos + d.length());
    }
    ret.push_back(input); //나머지 문자
    return ret;
}

int main(){
    string a = "a b c";
    string b = " ";
    
    vector<string> s = split(a,b);

    for(string b : s){
        cout << b;
    }

}

