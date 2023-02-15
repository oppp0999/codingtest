#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int x,y;

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int main(){
    int c;
    int max = 10000001;

    cin >> c;
    int a[max],b[max];

    set <pair<int,int> > ns;

    for(int i = 0; i<c; i++){
        cin >> x >> y;
        a[x] = max(a[x], y);
        b[y] = min(b[y],x); 
        ns.insert({ x,y });
    }

    int s;
    cin >> s;
    for(int i =0; i<s; i++){
        cin >> x >> y;

        if(ns.count({x,y})==1){
            cout << '1';
        }
        else if(b[y]<x && a[x]>y){
            cout << '2';
        }
        else {
            cout << "-1";
        }
    }

}