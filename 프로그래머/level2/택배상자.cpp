#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(vector<int> order) {
    vector<int> order2(1000001);
    order2.push_back(1000001); //처음 값
    
    int index = 0;
    for(int i = 1; i<=order.size(); i++){
        if(order[index] == i){
            index++;
        }
        else if(order[index] == order2.back()){
            order2.pop_back();
            index++;
            i--; //보조 컨테이너 사용
        }
        else{
            order2.push_back(i);
        }
    }
    
    //원래 컨테이너에서 모든 숫자가 빠졌을 때
    while(order2.size()!=1){
        if(order2.back()==order[index]){
            index++;
            order2.pop_back();
        }
        else {
            break;
        }
    }
        
    return index;
}