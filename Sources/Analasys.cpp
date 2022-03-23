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
		printf("�ҷ��� ���� ������ �����ϴ�!");
	} 
		
	printf("\n==========================================================================================\n");
	printf("\n\t\t\t�߱ǳ��� �м� �ý���v3.22 Developed by DevFissler\n");
	printf("\n====================================== \[%10s\] ======================================\n",filename);
	printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","��¥","�̿�� ����","�̿� �ð�","�߱� ����","��� ����","���� �ݾ�");
	printf("\n==========================================================================================\n");
	for (int index = 0; index < row; index++){
		printf("%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",date[index],ticketAuth[index],ticketTime[index],ticketQuan[index],discountType[index],totalPrice[index]);
	}
	printf("\n==========================================================================================\n");
	printf("\n================================ �̿�� �ð� �� �Ǹ� ��Ȳ ================================\n");
	
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
	printf("\n1 Day �̿��: �� %d��\t / ���� %d��\n",countFull,incomeFull);
	printf("\nAfter 4 �̿��: �� %d��\t / ���� %d��\n",countAF4,incomeAF4);
	
	printf("\n================================ �̿�� ���� �� �Ǹ� ��Ȳ ================================\n");
	
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
	printf("\n���� �̿��: �� %d��\t / ���� %d��\n",countAll,incomeAll);
	printf("\n��ũ �̿��: �� %d��\t / ���� %d��\n",countPark,incomePark);
	
	printf("\n============================= ��� ���� �з� �� �Ǹ� ��Ȳ ================================\n");
	
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
	printf("\n%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","����","�����","����������","�ް��庴","�ӻ��","�ٵ���");
	printf("\n%10d\t%10d\t%10d\t%10d\t%10d\t%10d\n",countNo,countDis,countHonor,countVaca,countPreg,countMulti);
	
	printf("\n====================================== ����  �� �Ǹ� ��Ȳ ================================\n");
	
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
	printf("\n\t\t\t\t�̿����ּż� �����մϴ�!\n");
	printf("\n==========================================================================================\n");

return 0;
}
