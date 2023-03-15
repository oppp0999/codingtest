#include <iostream>
using namespace std;
//최소의 프로그램을 만든다 -> 이분탐색
typedef long long ll;
int n,m, lo, hi,ret, a[100004], psum;

bool check(ll mid){
    for(int i = 0; i<n; i++){
        if(a[i]>mid){
            return false;
        }
    }
    int temp = mid;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(mid - a[i] < 0){ //중간값이 더 작을 때
            mid = temp;
            cnt++;  //뺄 때마다 추가 음원
        }
        mid -= a[i];//점점 a에 가까워지고 뺄 때마다
    }
    if(mid != temp) cnt++;
    return cnt <= m;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
        psum += a[i]; //전체 더한 값
    }
    lo = 0; hi = psum;
    while(lo <= hi){
        int mid = (lo+hi) / 2;
        if(check(mid)){
            hi = mid -1;
            ret = mid;
        }else lo = mid +1;
    }
    cout << ret << '\n';
    return 0;
}