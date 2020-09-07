#include <stdio.h>
#include <string.h>
 
char s[50+10];
int  sol;
 
int main(void)
{
      // 입력받는 부분
      scanf("%s", s);
 
      // 여기서부터 작성
      for(int i=0; i<strlen(s); i++) {
          if(i == 0 || s[i] != s[i-1]) {
              sol += 10;
          } else {
              sol += 5;
          }
      }
 
      // 출력하는 부분
      printf("%d", sol);
 
      return 0;
}
