#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    시간 복잡도: O(n)
    공간 복잡도: O(n)
    사용한 알고리즘: 이분탐색
    사용한 자료구조: vector
    
    논리 :
    바위 사이의 거리를 mid라고 하고, mid보다 간격이 좁으면 돌을 제거하는 형식으로 알고리즘을 짠다.
    start는 1, end는 distance가 되고 mid는 두 값의 평균으로 설정한다.
    그리고 몇개의 돌을 제거했는 지를 나타내는 변수인 cnt와 비교대상 돌 or 시작지점의 위치를 지정하는 변수인 prev를 만든다.
    rocks를 정렬한 후에 앞에서부터 간격을 잰다.
    
    입출력 예를 그대로 가져와서 알고리즘에 넣으면
    rocks가 [2,14,11,21,17], mid가 (1+25)/2 = 13 이라면 2-0 (idx 0 돌 제거), 11-0 (idx 1 돌 제거), 14-0, 17-14 (idx 3 돌 제거),
    21-14 (idx 4 돌 제거), 25-14 (마지막이기 때문에 남은 돌 1개도 제거) 이렇게 총 돌 5개가 제거된다.
    n은 2인데 5개를 제거했기 때문에 end = mid-1로 설정하고 다시 알고리즘을 반복한다.
    만약 n값보다 적은 돌을 제거했다면 start = mid+1로 설정하고 다시 알고리즘을 반복한다.
    만약 n값과 같은 돌을 제거했다면 거리의 최솟값 중 가장 큰 값을 구해야 하므로 start = mid+1로 설정한다.
    적거나 같은 돌을 제거했을 때 answer에 mid값을 넣는다.
    
    위 과정을 start > end가 될 때 까지 반복하고, answer을 반환한다.
*/

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int start = 1;
    int end = distance;
    int mid;
    int cnt, prev;
    
    sort(rocks.begin(), rocks.end()); // 정렬
    
    while(start <= end){ // start가 end보다 커질 때까지 while문 반복
        mid = (start+end)/2;
        cnt = 0;
        prev = 0;
        
        for (int i = 0; i < rocks.size(); ++i){ // 출발지점부터 돌간 사이 간격 확인
            if(mid > rocks[i] - prev)
                ++cnt;
            else
                prev = rocks[i];
        }
        
        if(mid > distance - prev) // 추가로 마지막 돌과 도착지점 비교
            ++cnt;
        
        if(cnt > n) // 돌을 더 많이 제거했다면
            end = mid-1;
        else{ // 돌을 같거나 덜 제거했다면
            start = mid+1;
            answer = mid;
        }
    }
    return answer;
}
