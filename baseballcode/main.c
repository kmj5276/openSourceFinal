#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
  int answer[3]; //정답을 저장할 배열
  int input[3]; //플레이어가 입력하는 수를 저장할 배열
  int i, j, strike, ball, temp; //중복되는 값이 있는지 확인하기 위해 임시로 값을 저장할 temp변수
  int count=1; //라운드가 진행됨에 따라 증가하는 변수
  int notSame=0; //입력한 숫자로 스트라이크와 볼이 둘 다 없을 시에 증가하는 변수  
  char rule; //규칙을 알려줄지 정하는 변수

  printf("============================================\n");
  printf("||                                        ||\n");
  printf("|| Welcome to the number baseball game!!! ||\n");
  printf("||                                        ||\n");
  printf("|| if you need rule > enter 'Y'           ||\n");
  printf("|| or enter anything                      ||\n");
  printf("============================================\n\n");
  printf("enter : ");
  scanf("%c", &rule);
  if(rule=='y' || rule=='Y')
  {
    printf("\n|||||  ||   || ||    |||||||   ||\n");
    printf("||  || ||   || ||    ||        ||\n");
    printf("|||||  ||   || ||    |||||||   ||\n");
    printf("|| ||  ||   || ||    ||\n");
    printf("||  \\\\  \\\\_//  ||||| |||||||   ||=\n\n");

    printf("============================================\n");
    printf("컴퓨터가 임의의 세자리 숫자를 설정합니다.\n");
    printf("자릿수와 숫자가 모두 맞으면 스트라이크이고 숫자만 맞으면 볼입니다.\n");
    printf("만약 3스트라이크면, 당신의 승리입니다.\n");
    printf("하지만, 세 번 이상 노스트라이크 노볼이면 당신의 패배입니다.\n");
    printf("그럼 시작합니다!!!\n");
    printf("============================================\n\n");
  }
  srand((unsigned)time(NULL)); //난수를 생성하고 서로 같은 값을 가지지 않도록 한다.
  for (i=0; i<3; i++) 
  { 
    temp = (rand()%9)+1; //1부터 9까지의 난수를 생성하고 temp에 저장한다.
    answer[i]=temp; //answer에 temp에 저장된 난수 값을 저장한다.
    for (j=0; j<i; j++) //answer에 값을 추가한 만큼 반복한다.
    {
     if (temp == answer[j] && i != j) //temp값과 answer에 넣은 값들을 비교해 같은 값이 있는지 찾는다.
      {
        i--; //i의 값을 감소시켜 해당 answer의 값을 다시 넣는다.
      }
    }
  } 
  while(1)
  {
    printf("[Number baseball round %d]\n\n", count); 
    while(1)
    {
      printf("서로 다른 숫자를 하나씩 입력해주세요 :\n");
      printf("=====\n");
      for(i=0; i<3; i++) //세 숫자를 입력 받는다.
      {
        scanf("%d", &input[i]);
        printf("=====\n");
      }
      if(input[0]==input[1]||input[0]==input[2]||input[1]==input[2]) //입력받은 수가 중복되는지 확인한다.
      {
        printf("\n중복된 숫자를 입력하면 안됩니다.\n\n다시 ");
        continue; 
      }
      else if(input[0]<1||input[0]>9||input[1]<1||input[1]>9||input[2]<1||input[2]>9) //입력받은 수가 범위를 벗어나지 않았는지 확인한다.
      { 
        printf("\n범위를 벗어난 숫자를 입력하였습니다.\n\n1부터 9사이의 "); 
        continue; 
      }
      break;
    }
    strike=0; //코드가 반복되므로 0으로 초기화해줘야한다.
    ball=0;
    for(i=0; i<3; i++)
    {
      for(j=0; j<3; j++) 
      {
        if(answer[i]==input[j]) //입력받은 수와 정답에서 스트라이크나 볼이 있는지 확인한다.
        {
          if(i==j) //같은 위치의 값이 동일하면 strike 값 증가
          {
            strike++;
          }
          else //다른 위치의 값이 동일하면 ball 값 증가
          {
            ball++;
          }
        }
      }
    }
    printf("============================================\n");
    printf("||   *Strike* : %d / *Ball* : %d            ||\n", strike, ball); 
    printf("============================================\n\n");
    if(strike==3) //3스트라이크가 되어 승리문구를 출력하고 종료한다.
    { 
      printf("*Victory!!!* 당신의 승리입니다! 축하드립니다!\n\n");
      break;
    }
    else if(count==9) //9라운드가 지나 패배문구를 출력하고 종료한다.
    { 
      printf("*Defeated!!!* 패배하였습니다 ㅠ-ㅠ Answer : [%d %d %d]\n\n",answer[0], answer[1], answer[2]);
      break;
    }
    if(strike==0 && ball ==0) //입력한 수에서 스트라이크와 볼이 하나도 발생하지 않았을 경우 notSame의 값이 증가한다. 
    {
      notSame++;
    }
    count++;
    if(notSame==3) //세번 이상 노스트라이크 노볼로 패배문구를 출력하고 종료한다.
    { 
      printf("*Defeated!!!* 패배하였습니다...ㅠ-ㅠ Answer : [%d %d %d]\n\n", answer[0], answer[1], answer[2]); 
      break; 
    }
  }

 return 0; 
}
