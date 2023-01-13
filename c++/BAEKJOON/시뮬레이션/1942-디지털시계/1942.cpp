
#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;
const int MAX_SECOND = 60;
const int MAX_MINUTE = 60;
const int MAX_HOUR = 24;

typedef struct
{
	int hour, minute, second;
}Time;

void getTimeStruct(string input, Time &startTime, Time &endTime) //stoi -> 문자를 정수로
{
	startTime.hour = stoi(input.substr(0, 2));
	startTime.minute = stoi(input.substr(3, 2));
	startTime.second = stoi(input.substr(6, 2));

	endTime.hour = stoi(input.substr(9, 2));
	endTime.minute = stoi(input.substr(12, 2));
	endTime.second = stoi(input.substr(15, 2));
}

bool isTimeEqual(Time startTime, Time endTime)
{
	return startTime.hour == endTime.hour
		&& startTime.minute == endTime.minute
		&& startTime.second == endTime.second;
}

int convertTimeStructToInt(Time time)
{
	return time.hour * 10000 + time.minute * 100 + time.second;
}

void incrementTime(Time &time)
{
	time.second++;

	if (time.second == MAX_SECOND)
	{
		time.second = 0;

		time.minute++;
	}

	if (time.minute == MAX_MINUTE)
	{
		time.minute = 0;

		time.hour++;
	}

	if (time.hour == MAX_HOUR)
	{
		time.hour = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0); //iostream C 런타임 라이브러리 작업이 소스 코드에 표시되는 순서대로 수행되도록 합니다. 없어도됨.
	cin.tie(0); //cin을 묶으면서 속도를 높이기위한 방법 필요없음.

	for (int i = 0; i < MAX; i++) //3번반복
	{
		string input;
		getline(cin, input);

		Time startTime, endTime; //객체 생성
		getTimeStruct(input, startTime, endTime); //문자열을 시작시간과 끝시간 나누기

		int result = 0;

		while (1)
		{
			int start = convertTimeStructToInt(startTime);
			int end = convertTimeStructToInt(endTime);

			if (start % 3 == 0)
			{
				result++;
			}

			if (isTimeEqual(startTime, endTime)) //시간이 같아지면 멈춤
			{
				break;
			}

			incrementTime(startTime);//시간증가
		}

		cout << result << "\n";
	}
}