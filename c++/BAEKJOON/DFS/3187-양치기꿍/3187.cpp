#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
string map[251][251];
int chk[251][251];
int k;
int v;
int r,c;
int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x, int y){
    for (int i=0; i<4; i++){
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];

        if(next_x < 1 || next_y < 1 || r < next_x || c < next_y)
            continue;
        if(map[next_x][next_y] != "#" && chk[next_x][next_y]==0){
            if(map[next_x][next_y] == 'v'){
                v++;
            }
            else if(map[next_x][next_y]  == 'k'){
                k++;
            }
            chk[next_x][next_y]=1;
            dfs(next_x,next_y);
        }
    }
}

int main(){
string input;
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		cin >> input;
		for (int j = 1; j <= c; j++)
		{
			map[i][j] = input[j-1];
		}
	}
 
	int kResult = 0;
	int vResult = 0;
 
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] == "v" || map[i][j] == "k")
			{
				k = 0;
				v = 0;
				dfs(i, j);
				if (v < k)
				{
					kResult += k;
				}
 				else if (v >= k)
				{					
					vResult += v;
				}
			}
		}
	}
 
 
	cout << kResult << " " << vResult << endl;
	return 0;
}