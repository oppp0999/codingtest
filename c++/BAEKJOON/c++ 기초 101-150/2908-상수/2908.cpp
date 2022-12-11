#include <iostream>
#include <string>

using namespace std;
// cin, cout을 사용하기 위해선 #include <iostream> 과 using namespace std; 선언 필요

int main() {
  string number1, number2, result;
  cin >> number1 >> number2;
  //scanf("%d %d", &number1, &number2); -> scanf대신 cin 입력을 사용(>>) cout는 출력(<<)

  for (int i =2; i >=0; i--){
    if (number1[i] == number2[i]){
      continue;
    }

    if(number1[i] > number2[i]){
      result = number1;
    }
    else{
      result = number2;
    }
    
    break;
  }
  cout << result[2] << result[1] << result[0];
}













