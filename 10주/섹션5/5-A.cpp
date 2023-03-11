#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, a, b, ret; //정수 개수, 대학 p,d 값, 총 벌 수 있는 돈
vector<pair<int,int> > v; //대학 정보
priority_queue<int, vector<int>, greater<int> > pq; //

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a >> b;
        v.push_back(pair<int,int>(b,a));
    }
    
    sort(v.begin(),v.end()); //일 수 기준으로 하기 위해서 q를 앞에 둔다.
    for(int i=0; i<n; i++){
        //cout << "second" << v[i].second << '\n';
        pq.push(v[i].second);
        if(pq.size() > v[i].first){
            //cout << "first" << pq.top() << '\n';
            pq.pop(); //선입했던 작은 값 빼기
        }
    }

    while(pq.size()){
        ret += pq.top();
        pq.pop();
    }

    cout << ret;
    
}