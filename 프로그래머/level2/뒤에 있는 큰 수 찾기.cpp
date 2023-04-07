#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1); //크기와 값 -1 설정
    stack<pair<int,int>> st;
    
    for(int i = 0; i<numbers.size(); i++){
        while(!st.empty()){
            pair<int, int> top = st.top();
            //printf("%d %d\n", top.first, top.second);  
            
            if(top.first >= numbers[i]){
                break;
            }
            answer[top.second] = numbers[i];
            st.pop();
        }
        st.push({numbers[i], i});
    }
    //pair<int, int> top = st.top();
    //printf("%d %d\n", top.first, top.second);
    return answer;
}