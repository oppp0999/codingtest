/*
[ 문제설명 ]
- 초기 상태가 윗면이 1 앞면이 5 오른쪽면이 3 등등등 으로 설정되어 있는 주사위가 하나 있다. 초기의 주사위의 모든 값은
  0이다.
- 맵이 하나 주어진다. 맵에는 숫자가 0을 포함한 자연수가 쓰여져 있다.
- 주사위를 굴릴 방향에 대한 정보가 입력으로 주어진다.
- 주사위를 입력한 방향대로 굴릴 때 마다, 윗면에 나오는 숫자를 출력시키면 된다.

[ 문제풀이 ]
1. 먼저 본인은 입력으로 주어지는 명령을 Vector에 저장해 놓았다. dx[] dy[] 방향도 문제에서 제시한대로 설정해 주었다.
2. 명령의 수만큼 반복문을 돌리면서, 주사위를 굴렸다. 이 때, 주사위를 굴리게 되면 일반적으로 보자면, 아니 일반적으로
   보는게 아니라 실제 상황에 대입해 보자면 윗면이 1이 오른쪽으로 구르게 되면 윗면이 오른쪽면으로 가고 왼쪽면이
   윗면이 된다. 하지만 이 문제에서는, 윗면의 값만 바꿔줄 뿐 실제로 윗면을 바꾸지는 않았다.
   예를 들어서 문제에서 말한대로 윗면이1 왼쪽면이 4라고 해보자. 윗면의 값이 예를들어 A이고, 왼쪽면의 값이 B라고 해보자.
   그렇다면 Dice[1] = A 이고 Dice[4] = B인데, 오른쪽으로 굴린다고 해서, 윗면을 Dice[4]로 관리하는 것이 아닌
   값만 Dice[1] = B로 바꾸어 주는 식으로 문제를 풀었다.
   나는 이 문제에서 주사위의 면들을 배열을 하나 만들어서 Dice[7]로 관리해 주었다.
3. 주사위를 굴리는 것은 주사위의 면만 잘 생각해보면 쉽게 풀 수 있다. 조금 헷갈릴뿐이지...
   먼저 나는 주사위를 굴리기 전에, 이전의 주사위의 값들을 계속해서 갱신해주었다.
   int형 변수 6개를 만들어서 int d1~d6 까지 만들었고, 각 변수들은 Dice[1] ~ Dice[6]까지의 값들을 저장하는 역할을 한다.
   즉, d1 = Dice[1], d2 = Dice[2] .... 가 되고, 예를 들어 오른쪽으로 주사위를 굴린다면
   Dice[1] = d4 , Dice[4] = d6 ... 이런 식으로 Dice[1]이라는 윗면을 그대로 두고, 그 값만 계속해서 갱신해 주었다.
*/


#include<iostream>
#include<vector>
 
#define endl "\n"
#define MAX 20
using namespace std;
 
int N, M, Sx, Sy, K;
int MAP[MAX][MAX];
 
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
 
int Dice[7] = { 0 };
 
vector<int> Cmd;
 
void Input()
{
    cin >> N >> M >> Sx >> Sy >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int a; cin >> a;
        a = a - 1;
        Cmd.push_back(a);
    }
}
 
void RollTheDice(int d)
{
    int d1, d2, d3, d4, d5, d6;
    d1 = Dice[1], d2 = Dice[2], d3 = Dice[3];
    d4 = Dice[4], d5 = Dice[5], d6 = Dice[6];
 
    if (d == 0)
    {
        Dice[1] = d4;
        Dice[4] = d6;
        Dice[6] = d3;
        Dice[3] = d1;
    }
    else if (d == 1)
    {
        Dice[4] = d1;
        Dice[6] = d4;
        Dice[3] = d6;
        Dice[1] = d3;
    }
    else if (d == 2)
    {
        Dice[1] = d5;
        Dice[2] = d1;
        Dice[6] = d2;
        Dice[5] = d6;
    }
    else if (d == 3)
    {
        Dice[5] = d1;
        Dice[1] = d2;
        Dice[2] = d6;
        Dice[6] = d5;
    }
}
 
void Solution()
{
    int x = Sx;
    int y = Sy;
 
    for (int i = 0; i < Cmd.size(); i++)
    {
        int nx = x + dx[Cmd.at(i)];
        int ny = y + dy[Cmd.at(i)];
        int d = Cmd.at(i);
 
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        
        RollTheDice(d);
        if (MAP[nx][ny] == 0) MAP[nx][ny] = Dice[6];
        else
        {
            Dice[6] = MAP[nx][ny];
            MAP[nx][ny] = 0;
        }
 
        cout << Dice[1] << endl;
 
        x = nx;
        y = ny;
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
