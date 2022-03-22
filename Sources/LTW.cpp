#include <stdio.h>
int main ()
{
for (;;){
int ticketAuth,ticketTime,idNumber,ticketQuan,discountType,unitPrice,totalPrice,contiChoice;
float discountRate;

const int ALL_ALL_ADULT  = 59000; const int ALL_ALL_YOUTH  = 52000; const int ALL_ALL_KIDS  = 47000; const int ALL_ALL_BABY  = 15000; // 3살 ~ 12 살 어린이 , 만 13세 ~ 만 18세 청소년, 만 65세 이상 어린이요금 
const int ALL_AF4_ADULT  = 48000; const int ALL_AF4_YOUTH  = 42000; const int ALL_AF4_KIDS  = 36000; const int ALL_AF4_BABY  = 15000;
const int PARK_ALL_ADULT = 56000; const int PARK_ALL_YOUTH = 50000; const int PARK_ALL_KIDS = 46000; const int PARK_ALL_BABY = 15000;
const int PARK_AF4_ADULT = 45000; const int PARK_AF4_YOUTH = 40000; const int PARK_AF4_KIDS = 35000; const int PARK_AF4_BABY = 15000;

printf("\n=============================================================\n");
printf("\n\n\t\티켓 발권 시스템v3.16 Developed by DevFissler\n\n");

do{
printf("\n==========================이용권 종류========================\n");
printf("\n\t%-10s\t%-10s\n", "1.종합 이용권", "2. 파크 이용권\n");
printf("\n\t[1] 이용권의 종류를 선택하세요: ");
scanf("%d",&ticketAuth);
	if (ticketAuth ==1 || ticketAuth ==2)
	continue;
	printf("\n=============================================================\n");
	printf("\n\t잘못된 입력입니다! 다시 입력해 주세요.\n");
	printf("\n=============================================================\n");
} while (! (ticketAuth ==1|| ticketAuth ==2));

do{
printf("\n===========================이용 시간=========================\n");
printf("\n\t%-10s\t%-10s\n", "1.1Day ", "2. After4\n");
printf("\n\t[2] 이용 시간을 선택하세요:  ");
scanf("%d",&ticketTime);
	if (ticketTime == 1 ||ticketTime == 2)
		continue;
	printf("\n=============================================================\n");
	printf("\n\t잘못된 입력입니다! 다시 입력해 주세요.\n");
	printf("\n=============================================================\n");
} while (! (ticketTime == 1 ||ticketTime == 2));

do{
printf("\n=============================================================\n");
printf("\n\t[3] 주민등록번호를 앞 6자리를  입력하세요: ");  
scanf("%d",&idNumber);
	if ( idNumber%10000<=1231 && idNumber%10000>= 101 && idNumber%100<=31 && idNumber%100 >=1 && idNumber <= 999999 && idNumber >=101 ) // 생년월일 가능범위 설정 
		continue;
	printf("\n=============================================================\n");
	printf("\n\t잘못된 입력입니다! 다시 입력해 주세요.\n");
	printf("\n=============================================================\n");
} while (!( idNumber%10000<=1231 && idNumber%10000>= 101 && idNumber%100<=31 && idNumber%100 >=1 && idNumber <= 999999 && idNumber >=101));

do{
printf("\n=============================================================\n");
printf("\n\t[4] 발권할  티켓  수를 입력하세요(최대 10매):   ");
scanf("%d",&ticketQuan);
	if (ticketQuan <= 10)
		continue;
	printf("\n=============================================================\n");
	printf("\n\t잘못된 입력입니다! 다시 입력해 주세요.\n");
	printf("\n=============================================================\n");
} while (!(ticketQuan <= 10));

do{
printf("\n===========================우대사항==========================\n");
printf("\n\t1. 없음(경로 우대는 자동처리)\n");
printf("\t2. 장애인\n"); //동반 1인 50% 
printf("\t3. 국가유공자\n"); //동반 1인 50% 
printf("\t4. 휴가 장병\n"); // 동반 1인 49% 
printf("\t5. 임산부\n");  // 본인만 50% 
printf("\t6. 다둥이 행복카드\n"); // 본인만 30% 
printf("\n\t[5] 우대사항을 선택하세요 : ");
scanf("%d",&discountType);
	if (discountType <= 6 )
		continue;
	printf("\n=============================================================\n");
	printf("\n\t잘못된 입력입니다! 다시 입력해 주세요.\n");
	printf("\n=============================================================\n");
} while ( ! (discountType <=6));

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

//연령 구분  (3-12/13-18/19-64/65-)	

int birthYear,birthDate,fullAge;
const int preYear = 2022, preDate = 321;  //기준 년, 기준 일 
		
	
if (idNumber/10000 < 22){  // 출생 년도 계산 
 	birthYear = 2000+ idNumber/10000;
	}
else{
 	birthYear = 1900+ idNumber/10000;
	}
	
birthDate = idNumber%10000;  //출생일 계산 

if ( birthDate <= preDate) { //생일 지남 
 	fullAge=preYear-birthYear;
	}
else {
 	fullAge=preYear-birthYear-1;
	}

// 연령구분 과 이용권 종류에 따라 단위가격(unitPrice) 설정 
	
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
else {
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
	
// 계산 부 ( 단위가격* 할인율* 발권매수) 
if ( discountType <5 ) {
	if (ticketQuan == 1){
		totalPrice=unitPrice-unitPrice*discountRate;
		}
	else {
		totalPrice=unitPrice*ticketQuan-unitPrice*discountRate*2;//동반 할인 
		}
	}
else {
	if (ticketAuth == 1) {
		totalPrice=unitPrice*ticketQuan-unitPrice*discountRate;
	}
	else
		totalPrice=unitPrice*ticketQuan;
}
	
printf("\n=============================================================\n");
printf("\n\t나이 : 만 %d세\t/ 구분 : ",fullAge); 
if (fullAge >= 65){
	printf("경로");
 }
else if(fullAge>=19 && fullAge<65){
	printf("일반");
 }
else if (fullAge>=13 && fullAge<19){
	printf("청소년");
 }
else if (fullAge>=3 && fullAge<13){
	printf("어린이"); 
 }
else {
	printf("유아"); 
 }
 
if (idNumber%10000 == preDate){
	totalPrice=totalPrice-unitPrice*0.5;
	printf("\n\n\t생일할인 대상자입니다.");
 }

printf("\n\n\t총 %d 장 발권, 입장료 총액은 %d 원 입니다.\n",ticketQuan,totalPrice);
printf("\n=============================================================\n");
printf("\n\t%-10s\t%-10s\n", "1. 계속 발권", "2. 발권 종료\n");
printf("\n\t계속 발권 하시겠습니까? : "); 
scanf("%d",&contiChoice);

if (contiChoice == 2){
	printf("\n=============================================================\n");
	printf("\n\t\t이용해주셔서 감사합니다.\n");
	printf("\n=============================================================\n");
	break;
	}
} //반복 입력 가능케 무한 루프 
return 0;
}
