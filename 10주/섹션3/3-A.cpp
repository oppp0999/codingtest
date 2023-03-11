#include <iostream>
#include <vector>
using namespace std;
int n,m, a[54][54], result = 987654321;
vector<vector<int> > chickenList;
vector<pair<int, int> > _home, chicken;

void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }
    for(int i = start+1; i<chicken.size(); i++){
        v.push_back(i);
        combi(i,v);
        v.pop_back(); //비우기
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j]==1){_home.push_back(pair<int,int>(i,j));}
            if(a[i][j]==2){chicken.push_back(pair<int,int>(i,j));}
        }
    }

    vector<int> v;
    combi(-1,v);

    for(vector<int> cList : chickenList){
        int ret = 0;
        for(pair<int, int> home : _home){//집을 고정하고 다른 치킨집 돌리기
            int _min = 98654321;
            for(int ch : cList){//치킨집 골라서 돌리기
                int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
                _min = min(_min, _dist);
            }
            ret += _min;
        }
        result = min(result,ret);
    }
    cout << result;
}