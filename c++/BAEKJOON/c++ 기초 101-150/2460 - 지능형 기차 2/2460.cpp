#include <iostream>
using namespace std;

int main(){
    int in, out, stat = 0;
    int max = 0;
    int sub;

    int i = 0;
    while(i<10){
        cin >> out >> in;
        if(out > 0){
            stat -= out;
            stat += in;
        }
        else{
            stat += in;

        }

        if(stat > max){
                max = stat;
                sub = i;
            }
        i++;
    }
    cout << max;
}