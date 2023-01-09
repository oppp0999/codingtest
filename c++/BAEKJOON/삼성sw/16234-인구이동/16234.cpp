#include <iostream>
using namespace std;

//주어지는 처음 변수들
int N,L,R;
int Map[50][50]; //국가를 나타내는 이차원 배열 최대가 50이기에 
int Visited[50][50];
int Cnt;

//ROW, Column, 이전 국가의 인구 수
int find(int r, int c, int value){
    if(r < 0 || r > N-1 || c < 0 || c > N-1){return 0;}
    if(Visited[r][c]){return 0;} //이미 방문 한 곳은 0으로 리턴처리

    if(value != -1){
        int diff = abs(value - Map[r][c]);
        if(diff<L || diff>R){return 0;}
    }

    Visited[r][c] = 1;

    int sum = Map[r][c];
    ++Cnt;
    sum += find(r-1, c, Map[r][c]);
    sum += find(r+1, c, Map[r][c]);
    sum += find(r, c-1, Map[r][c]);
    sum += find(r, c+1, Map[r][c]);

    return sum; 
}

//DFS 구현, 범위를 벗어나면 그냥 리턴
void move(int r, int c, int value){
    if(r < 0 || r > N-1 || c < 0 || c > N-1){return;}
    if(Visited[r][c] != 1){return;}
    
    Visited[r][c] = 2;

    Map[r][c] = value;
    move(r-1, c, value);
    move(r+1, c, value);
    move(r, c-1, value);
    move(r, c+1, value);
}


int solve(){
    int ret = 0;
    bool flag;
    //첫 인구 이동을 위한 do로 시도
    do {
        flag = false;
        for(int i=0; i<N;++i){
            for(int j=0; j<N; ++j){
                Visited[i][j]=0; //인구 이동이 있을 때마다 값을 0으로 초기화
            }
        }

        //인접한 국가가 있을 때 이중 loop을 돌면서 각 좌표에서 dfs로 탐색
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(Visited[i][j]==0){ //0이라면 방문한 적이 없기에 탐색 시도하는데 총 인구수를 반환하도록 함
                    Cnt = 0;
                    int sum = find(i,j, -1); //탐색을 시도할 때 총 인구 수를 반환 이전 인구가 없기에 -1로 반환
                    if (Cnt >1){
                        flag = true;
                        move(i, j, sum/Cnt); //연합을 이루는 총 개수는 전체에서 카운터 나누기
                    }
                    else{ //cnt가 1이라고하면 이동할 수 없기에, 단순히 visited값을 2로만 바꿔주면 됨
                        Visited[i][j] = 2;
                    }
                }
            }
        }


        if (flag) ++ret;
    } while(flag);
    return ret;
}

int main(){
    cin >> N >> L >> R;
    //다음 N by N 배열을 입력받기 위한 loop
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin >> Map[i][j];
        }
    }
    cout << solve() << endl; //이동 날짜 횟수 출력

    return 0;
}