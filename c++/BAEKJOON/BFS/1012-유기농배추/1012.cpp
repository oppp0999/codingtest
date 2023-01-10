#include <iostream>
#include <queue> //bfs 구현을 위한 큐

using namespace std;

queue <pair<int, int> > q; //pair은 하나로 묶은 인자들을 클래스 q를 만들어주는 역할
int farm[50][50]; //농장크기
int direct[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //dx, dy로 나누어서 사용해도된다. 방향배열(상하좌우)

int BFS(int width, int height, int number){
    for(int i =0; i< number; i++){ //배추의 위치 표시하기 위한 코드 << 배추 심기
        int x, y;
        cin >> x >> y; 
        farm[y][x] = 1;
    }
    int bug_count = 0; //벌레 개수 초기화
    for(int y =0; y<height; y++){
        for(int x=0; x<width; x++){
            if(farm[y][x]==1){
                q.push(make_pair(x,y)); //변수를 묶은 값을 q에 어떻게 함.
                farm[y][x] = 0; //들른 곳
                bug_count++;

                while(!q.empty()){
                    pair<int,int> now = q.front();
                    q.pop();
                    
                    for (int i = 0; i <4; i++){
                        //탐색할 배추 위치
                        pair<int, int> next = make_pair(now.first+direct[i][0], now.second + direct[i][1]); //first==x, second==y
                        // 탐색할 배추 위치
                        //int new_x = x + dx[i];
                        //int new_y = y + dy[i];

                        if(next.first >=0 && next.first < width && next.second >=0 && next.second < height && farm[next.second][next.first]==1){
                            farm[next.second][next.first]=0;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    return bug_count;
}


//1인곳을 만나서 visit상태가 아니면 bfs를 돌린다. bfs돌리게 되는 횟수 = 지렁이 개수 
int main(){
    int T=0;
    cin >> T;

    for(int i=0; i<T; i++){
        int M,N,K = 0;
        cin >> M >> N >> K;
        
        //농장을 배추가없다는 것으로 0으로 초기화
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
                farm[y][x]=0;
            }
        }

        //케이스마다 BFS처리
        cout << BFS(M,N,K) << '\n';
    }
}