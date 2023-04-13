#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> map(10000001);

//sort 방식 무조건 정해주기
bool cmp (int &a, int &b){
    return a>b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    //memset(map, 0, sizeof(map));
    
    //for(int a : tangerine){printf("%d ", a);}
    
    for(int i=0; i<tangerine.size(); i++){
            map[tangerine[i]]++;
    }
    sort(map.begin(), map.end(), cmp);

    int j = 0;
    while(k>0){
        k -= map[j];
        j++;
        answer++;
    }
    
    return answer;
}