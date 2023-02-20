//1. map을 사용하는방법
//2. unique 함수를 사용하는방법

//유니크함수는 sort와 함께 써야한다.

vector<int> v;
sort(v.begin(), v.end());
v.erase(unique(v.begin(),v.end()), v.end());
