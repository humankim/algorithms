#include <iostream>
using namespace std;

int N;              //송수신 안테나 수
int H[100000 + 10]; //송수신 안테나 높이

int stk[100000 + 10];
int sp;
void push(int d) { stk[++sp] = d; }
int top() { return stk[s]; }
void pop() { sp--; }
int empy { return sp = 0; }
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> H[i];
}
int Solve()
{
}

int SolveN2()
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int h = 0; // i,j사이 안테나 높이 중 최대 높이
        for (int j = i + 1; j < N; j++)
        {
            if (h < H[j])
            {
                cnt++;
                h = H[j];
            }
            if (H[i] <= H[j])
                break;
        }
    }
    return cnt;
}

int main()
{
    int ans = -1;
    InputData(); //	입력 함수

    //	코드를 작성하세요
    //ans = SolveN2();
    ans = Solve();
    cout << ans << endl; //출력

    return 0;
}