#include <string>
#include <vector>
#include <deque> //중간값 삭제를 위해서

using namespace std;
int answer = 0;

int solution(int cacheSize, vector<string> cities) {
    deque<string> d;
    
    for(int i = 0; i<cities.size(); i++){
        
        //캐시에 넣어야 할 도시
        string city = cities[i];
 
        //대문자 -> 소문자 변환
        for (int k = 0; k < city.length(); k++) {
            city[k] = tolower(city[k]); //tolower 소문자, toupper 대문자
        }
        
        bool hit = false;
        int j=0;
        for(j = 0; j<d.size(); j++){
            if(d[j] == city){
                hit = true;
                break;
            }
        }
        
        d.push_back(city); //무조건 뒤에 넣기
        
        if(hit){
            d.erase(d.begin()+j);
            answer+=1;
        }
        else{
            if(d.size()>cacheSize){
                d.pop_front();
                }
            answer+=5;
        }
    }
    
    
    return answer;
}