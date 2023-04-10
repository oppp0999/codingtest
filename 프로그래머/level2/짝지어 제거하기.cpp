#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stack;
    stack.push(s[0]);
    for(int i = 1; i<s.size(); i++){
        if(!stack.empty()){
            if(stack.top() == s[i]){
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
        }
        else{
            stack.push(s[i]);
        }

        
    }
    if(stack.empty()){answer=1;}
    
    return answer;
}