#include <iostream>
#include <vector>
using namespace std;

int n = 5, k = 3; // 5개 중에 3개를 뽑을 때
//int a[5] = {1,2,3,4,5};


void print_v (vector<int> &v){
    for(int i = 0; i< v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}


//2. 조합
void combi(int start , vector<int> b){
    if(b.size()==k){
        //기저사례 필수
        print_v(b);
        return;
    }
    for(int i = start +1 ; i<n; i ++){
        b.push_back(i); //인덱스의 값을 넣음 이것은 a의 0 , 1, 2 번째를 뜻
        combi(i,b);
        b.pop_back();
    }
}

//1. next_permutation 메서드 사용
int main(){
    vector<int> b;
    combi(-1, b); 
    return 0;

    //for문으로 조합 만들기
    //전체 갯수와 상관없이 뽑는 개수가 3개라면 for문 3개 2개면 2개
    int n = 5;
    int k = 3;
    int a[5] = {1,2,3,4,5};
    for(int i =0; i<n; i++){
        for(int j = 0; j<i; j++){
            for(int k = 0; k<j; k++){
                cout << i << " " << " "<< k<< '\n';
            }
        }
    }

    
}

//되도록이면 조합은 재귀보다 포문을 사용하기

