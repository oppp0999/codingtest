#include <iostream>
#include <stack>
//스택을 사용한다는 것은 bfs를 사용 -> 재귀가 아님.
#include <vector>
#include <algorithm>
using namespace std;


//시간 복잡도는 위의 문제에서는 하나의 그룹을 찾는 시간은 while 문을 통한 stack 을 사용하기 때문에, 
//하나의 그룹을 찾을 때는 시간 복잡도가 대략 O(n) 이라고 보여진다. 
int total;
char** peopleLive;
vector<int> answer_number; 
stack<pair<int, int> > dfs_stack;
int num = 0;
 
int dfs() {
    int x = 0 , y = 0 ; 
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < total; j++) {
            // 가장 먼저 1인놈을 찾으면 2로 바꾸고 나서, 인접한 상하좌우 얘들을 stack 에 넣는다. 
            if (peopleLive[i][j] == '1') { 
                int one_district = 0;
                dfs_stack.push(make_pair(i, j));
 
                // bfs 1 round 시작
                while(dfs_stack.size()){
                    pair<int, int> sub = dfs_stack.top();
                    dfs_stack.pop();
                    // 기존 값이 '2' + num 가 아닌 경우에만 주변 상하좌우 체크 
                    if (peopleLive[sub.first][sub.second] != '2' + num) {
                        peopleLive[sub.first][sub.second] = '2' + num;
                        one_district++;
 
                        // 상하좌우에 '1' 을 가진 놈이 있으면 stack 에 넣어준다. 
                        if ((sub.first - 1) >= 0 && peopleLive[sub.first - 1][sub.second] == '1') {
                            dfs_stack.push(make_pair(sub.first - 1, sub.second));
                        }
                        if ((sub.second - 1) >= 0 && peopleLive[sub.first][sub.second - 1] == '1') {
                            dfs_stack.push(make_pair(sub.first, sub.second - 1));
                        }
                        if ((sub.first + 1) < total && peopleLive[sub.first + 1][sub.second] == '1') {
                            dfs_stack.push(make_pair(sub.first + 1, sub.second));
                        }
                        if ((sub.second + 1) < total && peopleLive[sub.first][sub.second + 1] == '1') {
                            dfs_stack.push(make_pair(sub.first, sub.second + 1));
                        }
                    }
                    
 
                }
 
                // 정답에 추가 
                answer_number.push_back(one_district);
                //num++;
            }
        }
    } 
    return 0;
}
 
int main() {
    cin >> total;
 
    // 동적 배열로 2차원 배열을 생성한 뒤에 char을 입력받는다. 
    peopleLive = (char**)malloc(sizeof(char*)*total); 
    for (int i = 0; i < total; i++) {
        peopleLive[i] = (char*)malloc(sizeof(char)*total);
        cin >> peopleLive[i];
    }
 
    dfs();
 
    // 정렬 후 출력
    sort(answer_number.begin(), answer_number.end());
    cout <<  answer_number.size() <<endl;
    for (int i = 0; i < answer_number.size(); i++) {
        cout << answer_number[i] << endl; 
    }
 
    return 0;
}
