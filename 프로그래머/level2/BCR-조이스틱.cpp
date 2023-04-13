#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.size();
    int turn = n -1; //조이스틱을 한 방향으로 쭉 움직였을 때 case1
    
    for(int i = 0; i<n; i++){
        if(name[i] - 'A' < 14){
            answer += name[i] - 'A';
        }
        else{
            answer += 'Z' - name[i]+1;
        }
        
        int ind = i + 1; //문자의 인덱스 위치
        while(ind <n && name[ind] == 'A') ind++;
        
        turn = min(turn, i+n - ind + min(i,n-ind)); //원점을 기준으로 역방향으로 y까지 탐색하는데 이동거리 case2 와 비교
        //
    }
    answer += turn;
    
    return answer;
}