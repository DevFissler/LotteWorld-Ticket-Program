#include <stdio.h>
#include <ctime>
int main ()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	const char* filename = "report.csv";
	const int MAX = 500;
	
	int todayDate = (tm.tm_year+1900)*10000 + (tm.tm_mon+1)*100 + tm.tm_mday;
	int row = 0;
	int date[MAX],ticketAuth[MAX],ticketTime[MAX],ticketQuan[MAX],discountType[MAX],totalPrice[MAX];
	
	FILE *fp = fopen(filename,"r");
	
	while ( fscanf(fp,"%d,%d,%d,%d,%d,%d",&date[row],&ticketAuth[row],&ticketTime[row],&ticketQuan[row],&discountType[row],&totalPrice[row]) !=-1){
		row++;
	}
	fclose(fp);
	
	if (row == 0){
		printf("불러올 내역 파일이 없습니다!");
	} 
		
	printf("\n==========================================================================================\n");
	printf("\n\t\t\t발권내역 분석 시스템v3.22 Developed by DevFissler\n");
	printf("\n====================================== \[%10s\] ======================================\n",filename);
	printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","날짜","이용권 종류","이용 시간","발권 수량","우대 구분","결제 금액");
	printf("\n==========================================================================================\n");
	for (int index = 0; index < row; index++){
		printf("%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",date[index],ticketAuth[index],ticketTime[index],ticketQuan[index],discountType[index],totalPrice[index]);
	}
	printf("\n==========================================================================================\n");
	printf("\n================================ 이용권 시간 별 판매 현황 ================================\n");
	
	int countFull = 0 , countAF4 = 0, incomeFull = 0, incomeAF4 = 0;
	
	for (int index=0; index < row; index++){
		if ( ticketTime[index] == 1) {
			countFull += ticketQuan[index];
			incomeFull += totalPrice[index];
		} 
		else {
			countAF4 += ticketQuan[index];
			incomeAF4 += totalPrice[index];
		}
	}
	printf("\n1 Day 이용권: 총 %d매\t / 매출 %d원\n",countFull,incomeFull);
	printf("\nAfter 4 이용권: 총 %d매\t / 매출 %d원\n",countAF4,incomeAF4);
	
	printf("\n================================ 이용권 종류 별 판매 현황 ================================\n");
	
	int countAll = 0 , countPark = 0, incomeAll = 0, incomePark = 0;
	
	for (int index=0; index < row; index++){
		if ( ticketAuth[index] == 1) {
			countAll += ticketQuan[index];
			incomeAll += totalPrice[index];
		} 
		else {
			countPark += ticketQuan[index];
			incomePark += totalPrice[index];
		}
	}
	printf("\n종합 이용권: 총 %d매\t / 매출 %d원\n",countAll,incomeAll);
	printf("\n파크 이용권: 총 %d매\t / 매출 %d원\n",countPark,incomePark);
	
	printf("\n============================= 우대 사항 분류 별 판매 현황 ================================\n");
	
	int countNo = 0, countDis = 0 ,countHonor = 0, countVaca = 0, countPreg = 0, countMulti = 0;
	
	for (int index=0; index < row; index++){
		if ( discountType[index] == 1) {
			countNo += ticketQuan[index];		 
		} 
		else if ( discountType[index] == 2) {
			countDis += ticketQuan[index];		 
		} 
		else if ( discountType[index] == 3) {
			countHonor += ticketQuan[index];
		}
		else if ( discountType[index] == 4) {
			countVaca += ticketQuan[index];		 
		} 
		else if ( discountType[index] == 5) {
			countPreg += ticketQuan[index];		 
		}
		else {
			countMulti += ticketQuan[index];		 
		} 
	}
	printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","없음","장애인","국가유공자","휴가장병","임산부","다둥이");
	printf("\n%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",countNo,countDis,countHonor,countVaca,countPreg,countMulti);
	
	printf("\n====================================== 일자  별 판매 현황 ================================\n");
	
	int dateIndex = 0;
	int dateEarning = 0;
	int dateIncome[dateIndex]= {0};
	
	for (int dateIndex = 0; dateIndex <= 50; dateIndex++){
		for (int index=0; index <row ; index++){
			if (dateIndex = date[index]){
			dateEarning += totalPrice[index];
			}
		dateIncome[dateIndex] = dateEarning;
		}
	}
	
	for (int i= 0; i<row; i++ ){
		printf("%d\n",dateIncome[i]);
	}

	printf("\n==========================================================================================\n");
	printf("\n\t\t\t\t이용해주셔서 감사합니다!\n");
	printf("\n==========================================================================================\n");

return 0;
}
