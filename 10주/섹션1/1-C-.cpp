#include <iostream>
using namespace std;

int a, b, c;
int m[104];
int ret;


int main(){
    cin >> a >> b >> c;

    int s, e;
    for(int i=0; i<3; i++){
        cin >> s >> e;
        for(int j = s; j<e; j++){
            m[j]++;
        }
    }

    for(int i =0; i<100; i++){
        if(m[i]){
            if(m[i]==1){ret+=a;}
            else if(m[i]==2){ret+=b*2;}
            else if(m[i]==3){ret+=c*3;} //3대이기에 한대당 1한씩이기에 곱하기 3
        }
    }
    cout << ret;

}