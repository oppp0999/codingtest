#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i=0;i<progresses.size();i++)
    {
        int day=0;
        while(progresses[i]<100)
        {
            progresses[i]+=speeds[i];
            day++;
        }
        days.push_back(day);
    }
    
    int cnt=0;
    int maxDay=0;

    //앞에 날보다 뒤에 애들이 빨리 끝났을 때 체크해서 갯수 push
    for(int i=0;i<days.size();i++)
    {
        if(maxDay<days[i])
        {
            if(cnt!=0)
                answer.push_back(cnt);
            maxDay=days[i];
            cnt=1;
        }
        else
            cnt++;
    }
    if(cnt!=0)
        answer.push_back(cnt);
    
    return answer;
}