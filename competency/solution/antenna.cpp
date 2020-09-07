#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N;//송수신 안테나 수
int H[MAXN + 10];//송수신 안테나 높이
//FA stack
int stk[MAXN + 10];
int sp;
void push(int d) { stk[++sp] = d; }
int top() { return stk[sp]; }
void pop() { sp--; }
int empty() { return sp==0; }
int Solve(){
    int cnt=0;
    sp = 0;
    for (int i=0; i<N; i++){
        //1.스택에서 낮은 높이는 pop시킴 + cnt 증가
        while(!empty() && (top() < H[i])){
            cnt++; pop();
        }
        //2.스택이 비어있지 않으면 통신 가능 개수 1증가
        if (!empty()){
            cnt++;
            if (top() == H[i]) pop();
        }
        //3.i번 안테나 높이 스택에 저장
        push(H[i]);
    }
    return cnt;
}
void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
}
int SolveN2(){
    int cnt=0;
    for (int i=0; i<N; i++){//선택 안테나
        int h=0;//i와 j 사이 안테나 높이 중 최대 높이
        for (int j=i+1; j<N; j++){//비교대상
            if (h < H[j]){
                cnt++;
                h = H[j];
            }
            if (H[i] <= H[j]) break;//가지치기
        }
    }
    return cnt;
}
int main(){
	int ans = -1;
	InputData();//	입력 함수
	//ans = SolveN2();//	코드를 작성하세요
	ans = Solve();
    cout << ans << endl;//출력
	return 0;
}

