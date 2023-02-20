#include <iostream>
#include <vector>
using namespace std;
vector<int> v; 


void print_v (vector<int> &v){
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}





//2. 함수를 쓰지 않고 수열을 직접 함수로 만들었을 때
void make_permutation(int n, int r, int depth){ //n = 몇개중에, r = 몇개 뽑기 , depth깊이
    //cout << n << ":" << r << ":" << depth << '\n';
    
    if(r == depth){ //전부 뽑았을 때
        //기저사례 
        print_v(v);
        return;
    }

    for(int i = depth; i<n; i++){
        swap(v[i], v[depth]);
        make_permutation(n,r, depth+1);
        swap(v[i], v[depth]);
    }
}



//1. next_permutation 메서드 사용
int main(){
    for(int i = 0; i<3; i++){
        v.push_back(i); 
    } // 0 , 1 , 2 이렇게 값이 들어감 i=0이기에

   /*  do
    {
        print_v(v);
    } while (next_permutation(v.begin(),v.end())); */

    make_permutation(3,1,0);
    
}

