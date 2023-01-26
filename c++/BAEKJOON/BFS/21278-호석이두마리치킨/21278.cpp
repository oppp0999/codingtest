/* 크게 세 단계로 나누어 풀이를 진행하였다.

가능한 경우의 수 구하기 + 각 경우마다의 최소 왕복 거리 구하기(플로이드와샬) + 정렬 후 가장 짧은 경우 구하기 */

//플로이드 와샬 -> 완전탐색 알고리즘

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
#define INF 987654321 //무한 값, 가는 길이 없음

int N,M;
int city[101][101];
bool visit[101];
pair<int, int> result_city;
int result_dist = INT_MAX;

void check_chicken_house_distance(int chicken_house_one, int chicken_house_two){
    int total_distance = 0;
    for(int i=1; i<=N; i++){
        if(chicken_house_one == i || chicken_house_two == i)
            continue;
        total_distance += min(city[chicken_house_one][i],city[chicken_house_two][i]) * 2;

    }
    if(result_dist > total_distance){
        result_city=make_pair(chicken_house_one, chicken_house_two);
        result_dist = total_distance;
    }
}

void find_min_chicken_house_location(){
    for(int i =1; i<=N; i++){
        for(int j =1; j<=N; j++){
            check_chicken_house_distance(i,j);//모든 값을 대입하면서 최소의 경우의 수 찾기
        }
    }
}

void floyd_warshall(){
    //거쳐가는 노드
    for(int i = 1; i<=N; i++){
        //출발 노드
        for(int j =1; j<=N; j++){
            //도착 노드
            for(int k=1; k<=N; k++){
                if(j == k){
                    city[j][k]=0;
                }
                else{
                    city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
                }
            }
        }
    }
}

void set_city_dist(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            city[i][j] = INF;
        }
    }
}

int main(){
    cin >> N >> M;
    
    set_city_dist(); //1. 위치 값 초기화하기

    //2. 위치 연결, 위치 선청 받아서 쓰기
    for(int i = 0; i<M; i++){
        int src, dst;
        cin >> src >> dst;

        city[src][dst] = 1;//앞
        city[dst][src] = 1;//뒤
    }

    floyd_warshall(); // 최소 값 찾기 왕복 거리 찾기
    find_min_chicken_house_location(); //모든 값을 더해 가장 짧은 거리 찾기

    cout << result_city.first << ' ' << result_city.second << ' ' << result_dist;
}