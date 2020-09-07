#include <stdio.h>
 
int N;
int s[100+10];
int a[100+10];
int sol;
 
int main(void)
{
      int i;
 
      // 입력받는 부분
      scanf("%d", &N);
      for (i=0; i<N; i++)
      {
            scanf("%d %d", &s[i], &a[i]);
      }
 
      // 여기서부터 작성
      for (int i=0; i<N; i++)
      {
          sol += a[i] % s[i];
      }

 
      // 출력하는 부분
      printf("%d", sol);
 
      return 0;
}
