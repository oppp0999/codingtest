#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string ss) {
    int answer = 0;
    int len = ss.size(); //기존 길이
    ss+=ss; // 회전 대신해서 전체 길이를 한 번더 더함
    for(int i=0;i<len;i++){ //기존길이만큼 반복
        int idx=i;
        stack<char> s;
        while(idx<i+len){ //추가로 더해진 문자열들을 까지
            char c = ss[idx++]; //추가로 나온 문자열들 
            if(c=='[' || c=='{' || c=='(') s.push(c);
            else if(c==']'){
                if(s.top()=='[') s.pop();
                else s.push(c);
            }
            else if(c=='}'){
                if(s.top()=='{') s.pop();
                else s.push(c);
            }
            else if(c==')'){
                if(s.top()=='(') s.pop();
                else s.push(c);
            }
        }
        if(s.empty()) answer++;
    }
    return answer;
}