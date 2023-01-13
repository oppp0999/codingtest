#include <iostream>
#include <string>
using namespace std;

int max_h = 24;
int max_m = 60;
int max_s = 60;

typedef struct 
{
    int h,s,m;
}Time;

void setTime(string a, Time &f_time, Time &e_time) //시작 시간 객체, 끝 시간 객체
{
    f_time.h = stoi(a.substr(0,2));
    f_time.m = stoi(a.substr(3,2));
    f_time.s = stoi(a.substr(6,2));
    
    e_time.h = stoi(a.substr(9,2));
    e_time.m = stoi(a.substr(12,2));
    e_time.s = stoi(a.substr(15,2));
}

int conTime(Time time){
    return time.h * 10000 + time.m * 100 + time.s;
}

void upTime(Time &time){
    time.s++;

    if (time.s == max_s)
	{
		time.s = 0;

		time.m++;
	}

	if (time.m == max_m)
	{
		time.m = 0;

		time.h++;
	}

	if (time.h == max_h)
	{
		time.h = 0;
	}
}

bool equalTime(Time f_time, Time e_time){
    return f_time.h == e_time.h 
    && f_time.m == e_time.m
    && f_time.s == e_time.s;
}

int main(){
    ios_base::sync_with_stdio(0); //iostream C 런타임 라이브러리 작업이 소스 코드에 표시되는 순서대로 수행되도록 합니다. 없어도됨.
	cin.tie(0); //cin을 묶으면서 속도를 높이기위한 방법 필요없음.
    for(int i = 0; i<3; i++){
        string a;
        getline(cin, a);

        Time f_time,e_time;
        setTime(a, f_time, e_time);

        int cnt=0;
        while(1){
            int f=conTime(f_time);
            int e=conTime(e_time);

            if((f%3)==0){cnt++;}

            if(equalTime(f_time,e_time)){break;}
            
            upTime(f_time);
        }
        cout << cnt << '\n';
    }
}


/* 1. 타임에 관련된 객체생성
2. 문자열 나누기, 시작과 끝, 시간별 -> 정수로 변환
3. 변환된 정수 자리 정하기
4. 시간 증가
5. 비교 */