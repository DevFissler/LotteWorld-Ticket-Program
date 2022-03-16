#include <stdio.h>
int main ()
{
int ticketAuth,ticketTime,ticketQuan,idNumber,discountType;
int todayDate=316;

const int ALL_ALL_ADULT = 59000; const int ALL_ALL_YOUTH = 52000; const int ALL_ALL_KIDS = 47000; const int ALL_ALL_BABY = 15000;
const int ALL_AF4_ADULT = 48000; const int AF4_ALL_YOUTH = 42000; const int ALL_AF4_KIDS = 36000; const int ALL_AF4_BABY = 15000;
const int PARK_ALL_ADULT = 56000; const int PARK_ALL_YOUTH = 50000; const int PARK_ALL_KIDS = 46000; const int PARK_ALL_BABY = 15000;
const int PARK_AF4_ADULT = 45000; const int PARK_AF4_YOUTH = 40000; const int PARK_AF4_KIDS = 35000; const int PARK_AF4_BABY = 15000;

int totalPrice=ALL_ALL_KIDS;

printf("이용권의 종류를 선택하세요.\n");
printf("1.종합 이용권\n");
printf("2.파크 이용권\n");
scanf("%d",&ticketAuth);

printf("\n권종을 선택하세요.\n\n");
printf("1.주간권\n");
printf("2.야간권\n");
scanf("%d",&ticketTime);

printf("\n스캔 받은 주민등록번호를 입력하세요.\n");
scanf("%d",&idNumber);

printf("\n발권할  매 수를 입력하세요\n");
scanf("%d 매",&ticketQuan);

printf("\n우대사항을 선택하세요.\n");
printf("1. 없음(경로 우대는 자동처리)\n");
printf("2. 장애인\n");
printf("3. 국가유공자\n");
printf("4. 휴가 장병\n");
printf("5. 임산부\n");
printf("6. 다둥이 행복카드\n");
scanf("%d",&discountType);
 
printf("\n총 %d 장 발권, 가격은 %d 원 입니다\n",ticketQuan,totalPrice);

}
