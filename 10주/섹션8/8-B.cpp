#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, cnt;
struct cha{
    int s, i, p;
};

vector<cha > a;
bool visited[1004];
int dp[1004][1004];

int rpg(int STR, int INT){
    int &ret = dp[STR][INT];
    cout << ret;
    if(ret != -1){return ret;}
    ret = 0;
    int pnt = 0;
    vector<int> Q;
    for(int i = 0; i< n; i++){
        if(a[i].s <= STR || a[i].i <= INT){
            ret++;
            if(!visited[i]){
                visited[i] = true;
                pnt += a[i].p;
                Q.push_back(i);
            }
        }
    }
    for(int p = 0; p<= pnt; p++){
        int nextSTR = min(1000, STR + p);
        int nextINT = min(1000, INT + pnt - p);
        ret = max(ret, rpg(nextSTR, nextINT));
    }
    for( int q : Q) visited[q] = false;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i<n; i++){

        int STR, INT, PNT;
        cin >> STR >> INT >> PNT;
        a.push_back(cha({STR, INT, PNT}));
    }

    memset(dp, -1, sizeof(dp));
    cout << rpg(1,1) << '\n';//스텟이 1, 1부터 시작이기에

    
}