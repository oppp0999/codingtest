#include <iostream>
#include <string>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    string st = "";
    
    int i=0;
    while(i<a){
        st += to_string(a);
        if (st.size()>=b){
            st = st.substr(0,b);
            break;
        }
        i++;
    }
    cout << st;
}