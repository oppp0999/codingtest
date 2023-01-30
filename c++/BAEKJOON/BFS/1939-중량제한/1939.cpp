/* 
1. 시간초과를 막기위해 BFS를 이용해서 풀기
2. 이분탐색 -> 2개의 범위로 나누어서 탐색하는 방식
3. left, right를 중간값으로나누어 (/2) mid값으로 탐색
4. mid값을 기준으로 탐색이 완료된다면, 더 큰 범위가 가능하기에 low, left값을 mid+1 값으로
5. 반대라면 high right의 값을 mid-1값으로 바꿔주면서 탐색을 진행
 */


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1000001
using namespace std;

int N,M,Max_Cost, Start, End;
bool visit[MAX]; //방문을 위한 배열
vector<pair<int,int> > v[MAX]; //x(first), y(sencond)

bool BFS(int cur_cost){
    queue<int> q;
    q.push(Start);
    visit[Start] = true;

    while(q.empty() ==0){
        int cur_factory = q.front();
        q.pop();

        if(cur_factory == End){return true;}

        for(int i= 0; i< v[cur_factory].size(); i++){
            int nextf= v[cur_factory][i].first;
            int nextf_cost = v[cur_factory][i].second;
            cout << nextf << nextf_cost;
            //중량 제한이 cost일 때 다리를 건널 수 있는지 여부를 판별
            if(visit[nextf] == false && cur_cost <= nextf_cost){
                visit[nextf]=true;
                q.push(nextf);
            }
        }
    }
    return false;
}


int main(){
    //1. 값 받기
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        int p1, p2, cost;
        cin >> p1 >> p2 >> cost;
        
        //양방향이기때문에 p1에 대해서 p2에 이동할 수 있는 값 넣고, 반대로도 해주기
        v[p1].push_back(make_pair(p2, cost));
        v[p2].push_back(make_pair(p1,cost));

        //maxcost 중량제한을 위해 가장 큰 이동 값을 적어넣기 이를 넘기면안됨.
        if(Max_Cost<cost){
            Max_Cost = cost;
        }
    }

    //마지막 줄 값들
    cin >> Start >> End;

    int Low=0;//시작점
    int High = Max_Cost;//끝점
    while(Low <=High){//같을 때 까지 반복, 찾고자하는 값이 미드와 같다면 반환, 미드보다 작다면 왼쪽부터 -1, 미드보다 크다면 +1하고 오른쪽부터
        memset(visit, false, sizeof(visit)); //메모리 전부 false로 초기화
        int Mid = (Low+High) / 2; //중간 값
        if(BFS(Mid)==true){
            Low = Mid +1;
        }
        else {
            High = Mid -1;
        }

    }
    cout << High;

}
