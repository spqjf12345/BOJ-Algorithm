//
//  11729.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/12/10.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  int num;
  char a[100];
  int sum = 0;

  scanf("%d\n", &num);

 for(int i = 0 ; i < num ; i++) {
      scanf("%c", &a[i]);
  }

  for(int i = 0 ; i < num ; i++)
  {
    sum = sum + a[i]-'0';
  }
  
  printf("%d", sum);


  return 0;


}
