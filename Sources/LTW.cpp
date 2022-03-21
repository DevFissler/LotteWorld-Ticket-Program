#include <stdio.h>
int main ()
{
for (;;)
{
int ticketAuth,ticketTime,ticketQuan,idNumber,discountType,unitPrice,totalPrice;
float discountRate;

const int ALL_ALL_ADULT  = 59000; const int ALL_ALL_YOUTH  = 52000; const int ALL_ALL_KIDS  = 47000; const int ALL_ALL_BABY  = 15000; // 3살 ~ 12 살 어린이 , 만 13세 ~ 만 18세 청소년, 만 65세 이상 어린이요금 
const int ALL_AF4_ADULT  = 48000; const int ALL_AF4_YOUTH  = 42000; const int ALL_AF4_KIDS  = 36000; const int ALL_AF4_BABY  = 15000;
const int PARK_ALL_ADULT = 56000; const int PARK_ALL_YOUTH = 50000; const int PARK_ALL_KIDS = 46000; const int PARK_ALL_BABY = 15000;
const int PARK_AF4_ADULT = 45000; const int PARK_AF4_YOUTH = 40000; const int PARK_AF4_KIDS = 35000; const int PARK_AF4_BABY = 15000;

while (true){
printf("\n\n티켓 발권 시스템v3.16 Developed by DevFissler\n\n");
printf("\n===================이용권 종류===================\n");
printf("\n\t%-10s\t%-10s\n", "1.종합 이용권", "2. 파크 이용권\n");
printf("\n\t[1] 이용권의 종류를 선택하세요: ");
scanf("%d",&ticketAuth);

if (ticketAuth == 1 ||ticketAuth == 2 ){ // 1,2 이외의 선택지 고를 시 진행 x 
printf("\n====================이용 시간====================\n");
printf("\n\t%-10s\t%-10s\n", "1.1Day ", "2. After4\n");
printf("\n\t[2] 이용 시간을 선택하세요:  ");
scanf("%d",&ticketTime);


if (ticketTime == 1 ||ticketTime == 2){ // 1,2 이외의 선택지 고를 시 진행 x 
	printf("\n=================================================\n");
	printf("\n\t[3] 주민등록번호를 앞 6자리를  입력하세요: ");  //나이에 따른 요금 책정 부분 
	scanf("%d",&idNumber);
	
	int birthYear,birthDate,fullAge;
	const int nowYear = 2022, preDate = 316;  //기준 년, 기준 일 
		
	
	if (idNumber/10000 < 22){  // 출생 년도 계산 
	 birthYear = 2000+ idNumber/10000;
	 }
	else{
	 birthYear = 1900+ idNumber/10000;
	 }
	
	birthDate = idNumber%10000;  //출생일 계산 
	
	if (birthDate<=1231){

	if ( birthDate <= preDate) { //생일 지남 
	 fullAge=nowYear-birthYear;
	 }
	else if (birthDate > preDate) {
	 fullAge=nowYear-birthYear-1;
	}
	
	if (ticketAuth ==1){
	 if (ticketTime ==1){
	  	if(fullAge>=19 && fullAge<65){
			unitPrice=ALL_ALL_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=ALL_ALL_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=ALL_ALL_KIDS;
			}
		else {
			unitPrice=ALL_ALL_BABY;
			}
		}
	 else if (ticketTime ==2){
		if(fullAge>=19 && fullAge<65){
			unitPrice=ALL_AF4_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=ALL_AF4_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=ALL_AF4_KIDS;
			}
		else {
			unitPrice=ALL_AF4_BABY;
			}
		}
	}
	else if (ticketAuth ==2){
	 if (ticketTime ==1){
	  	if(fullAge>=19 && fullAge<65){
			unitPrice=PARK_ALL_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=PARK_ALL_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=PARK_ALL_KIDS;
			}
		else {
			unitPrice=PARK_ALL_BABY;
			}
		}
	 else if (ticketTime ==2){
		if(fullAge>=19 && fullAge<65){
			unitPrice=PARK_AF4_ADULT;
			}
		else if (fullAge>=13 && fullAge<19){
	 	 	unitPrice=PARK_AF4_YOUTH;
	 		}
		else if (fullAge>=3 && fullAge<13){
			unitPrice=PARK_AF4_KIDS;
			}
		else {
			unitPrice=PARK_AF4_BABY;
			}
		}
	}
	
printf("\n=================================================\n");
printf("\n\t[4] 발권할  티켓  수를 입력하세요(최대 10매):   ");
scanf("%d",&ticketQuan);

printf("\n=====================우대사항====================\n");
printf("\t1. 없음(경로 우대는 자동처리)\n");
printf("\t2. 장애인\n"); //동반 1인 50% 
printf("\t3. 국가유공자\n"); //동반 1인 50% 
printf("\t4. 휴가 장병\n"); // 종합만 동반 1인 49% 
printf("\t5. 임산부\n");  // 종합만 본인만 50% 
printf("\t6. 다둥이 행복카드\n"); // 가족 본인 30% 
printf("\n\t[5] 우대사항을 선택하세요 : ");
scanf("%d",&discountType);

	switch (discountType){
		case (1) : 
		discountRate = 0;
		break;
		case (2) :
		discountRate = 0.5;
		break;
		case (3) :
		discountRate = 0.5;
		break;
		case (4) :
		discountRate = 0.49;
		break;
		case (5) :
		discountRate = 0.5;
		break;
		case (6) :
		discountRate = 0.3;
		break;
		}

	if (ticketQuan ==1){
	totalPrice=unitPrice*(1-discountRate);
	}
	else {
	totalPrice=unitPrice*(ticketQuan-discountRate*2);//동반 할인 
	}
	
printf("\n=================================================\n");
printf("\n\t총 %d 장 발권, 가격은 %d 원 입니다\n\n",ticketQuan,totalPrice);
printf("\n\t감사합니다.\n\n"); 
printf("\n=================================================\n");
} //birthday 오류 시 return 복 
} //이용권 시간 설정  오류 시 return 
} //이용권 종류 설정 오류 시 return 
printf("\n=================================================\n");
printf("\n\t잘못된 입력입니다! 다시 입력해주세요.\n");
printf("\n=================================================\n");
} //while true 로 잘못된 데이터 입력 시 반복 
} //반복 입력 가능케 무한 루프 
return 0;
}
