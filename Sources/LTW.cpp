#include <stdio.h>
int main ()
{	
int row = 0;
int reportArray[50000][6] = {0};

for (;;){
int ticketAuth,ticketTime,idNumber,ticketQuan,discountType,unitPrice,totalPrice,contiChoice;
float discountRate=0.0;

const int ALL_ALL_ADULT  = 59000, ALL_ALL_YOUTH  = 52000, ALL_ALL_KIDS  = 47000, ALL_ALL_BABY  = 15000, // 3�� ~ 12 �� ��� , �� 13�� ~ �� 18�� û�ҳ�, �� 65�� �̻� ��̿�� 
		  ALL_AF4_ADULT  = 48000, ALL_AF4_YOUTH  = 42000, ALL_AF4_KIDS  = 36000, ALL_AF4_BABY  = 15000,
		  PARK_ALL_ADULT = 56000, PARK_ALL_YOUTH = 50000, PARK_ALL_KIDS = 46000, PARK_ALL_BABY = 15000,
		  PARK_AF4_ADULT = 45000, PARK_AF4_YOUTH = 40000, PARK_AF4_KIDS = 35000, PARK_AF4_BABY = 15000;

printf("\n============================================================================================\n");
printf("\n\n\t\t\tƼ�� �߱� �ý���v3.22 Developed by DevFissler\n\n");
printf("\t\t\t\t\t\t\t\t������ ��ȣ :20220323-");printf("%d",row+1); 

	do{
	printf("\n========================================= �̿�� ���� ======================================\n");
	printf("\n\t\t\t%-10s\t%-10s\n", "1.���� �̿��", "2. ��ũ �̿��\n");
	printf("\n\t\t\t[1] �̿���� ������ �����ϼ���: ");
	scanf("%d",&ticketAuth);
		if (ticketAuth ==1 || ticketAuth ==2)
		continue;
		printf("\n============================================================================================\n");
		printf("\n\t\t\t�߸��� �Է��Դϴ�! �ٽ� �Է��� �ּ���.\n");
		printf("\n============================================================================================\n");
	} while (! (ticketAuth ==1|| ticketAuth ==2));
	
	do{
	printf("\n========================================= �̿�   �ð� ======================================\n");
	printf("\n\t\t\t%-10s\t%-10s\n", "1.1Day ", "2. After4\n");
	printf("\n\t\t\t[2] �̿� �ð��� �����ϼ���:  ");
	scanf("%d",&ticketTime);
		if (ticketTime == 1 ||ticketTime == 2)
			continue;
		printf("\n============================================================================================\n");
		printf("\n\t\t\t�߸��� �Է��Դϴ�! �ٽ� �Է��� �ּ���.\n");
		printf("\n============================================================================================\n");
	} while (! (ticketTime == 1 ||ticketTime == 2));

	do{
	printf("\n========================================= ����   ���� ======================================\n");
	printf("\n\t\t\t[3] �ֹε�Ϲ�ȣ�� �� 6�ڸ���  �Է��ϼ���: ");  
	scanf("%d",&idNumber);
		if ( idNumber%10000<=1231 && idNumber%10000>= 101 && idNumber%100<=31 && idNumber%100 >=1 && idNumber <= 999999 && idNumber >=101) // ������� ���ɹ��� ���� 
			continue;
		printf("\n============================================================================================\n");
		printf("\n\t\t\t�߸��� �Է��Դϴ�! �ٽ� �Է��� �ּ���.\n");
		printf("\n============================================================================================\n");
	} while (! (idNumber%10000<=1231 && idNumber%10000>= 101 && idNumber%100<=31 && idNumber%100 >=1 && idNumber <= 999999 && idNumber >=101));
	
	do{
	printf("\n========================================= �߱�   ���� ======================================\n");
	printf("\n\t\t\t[4] �߱���  Ƽ��  ���� �Է��ϼ���(�ִ� 10��):   ");
	scanf("%d",&ticketQuan);
		if (ticketQuan <= 10)
			continue;
		printf("\n============================================================================================\n");
		printf("\n\t\t\t�߸��� �Է��Դϴ�! �ٽ� �Է��� �ּ���.\n");
		printf("\n============================================================================================\n");
	} while (! (ticketQuan <= 10));

	do{
	printf("\n========================================= ���   ���� ======================================\n");
	printf("\n\t\t\t1. ����(��� ���� �ڵ�ó��)\n");
	printf("\t\t\t2. �����\n"); //���� 1�� 50% 
	printf("\t\t\t3. ����������\n"); //���� 1�� 50% 
	printf("\t\t\t4. �ް� �庴\n"); // ���� 1�� 49% 
	printf("\t\t\t5. �ӻ��\n");  // ���θ� 50% 
	printf("\t\t\t6. �ٵ��� �ູī��\n"); // ���θ� 30% 
	printf("\n\t\t\t[5] �������� �����ϼ��� : ");
	scanf("%d",&discountType);
		if (discountType <= 6 )
			continue;
		printf("\n============================================================================================\n");
		printf("\n\t\t\t�߸��� �Է��Դϴ�! �ٽ� �Է��� �ּ���.\n");
		printf("\n============================================================================================\n");
	} while (! (discountType <=6));

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

//���� ����  (3-12/13-18/19-64/65-)	
int birthYear,birthDate,fullAge;
const int preYear = 2022, preDate = 321;  //���� ��, ���� �� 
		
	
	if (idNumber/10000 < 22){  // ��� �⵵ ��� 
	 	birthYear = 2000+ idNumber/10000;
	}
	else{
	 	birthYear = 1900+ idNumber/10000;
	}
	
	birthDate = idNumber%10000;  //����� ��� 

	if ( birthDate <= preDate) { //���� ���� 
	 	fullAge=preYear-birthYear;
	}
	else {
	 	fullAge=preYear-birthYear-1;
	}

// ���ɱ��� �� �̿�� ������ ���� ��������(unitPrice) ���� 	
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
	
// ��� �� ( ��������* ������* �߱Ǹż�) 
	if ( discountType <5 ) {
		if (ticketQuan == 1){
			totalPrice=unitPrice*(1-discountRate);
		}
		else {
			totalPrice=unitPrice*(ticketQuan-discountRate*2);//���� ���� 
		}
	}
	else {
		if (ticketAuth == 1) {
			totalPrice=unitPrice*(ticketQuan-discountRate);
		}
		else
			totalPrice=unitPrice*ticketQuan;
	}
		
printf("\n========================================= �߱�   ��� ======================================\n");
printf("\n\t\t\t���� : �� %d��\t/ ���� : ",fullAge); 
	
	if (fullAge >= 65){
		printf("���");
	}
	else if(fullAge>=19 && fullAge<65){
		printf("�Ϲ�");
	}
	else if (fullAge>=13 && fullAge<19){
		printf("û�ҳ�");
	}
	else if (fullAge>=3 && fullAge<13){
		printf("���"); 
	}
	else {
		printf("����"); 
	}
	 
reportArray[row][0] = ticketAuth;
reportArray[row][1] = ticketTime;
reportArray[row][2] = ticketQuan;
reportArray[row][3] = discountType;
reportArray[row][4] = fullAge;
reportArray[row][5] = totalPrice;

printf("\n\n\t\t\t�� %d �� �߱�, ����� �Ѿ��� %d �� �Դϴ�.\n",ticketQuan,totalPrice);
printf("\n============================================================================================\n");
printf("\n\t\t\t%-10s\t%-10s\n", "1. ��� �߱�", "2. �߱� ����\n");
printf("\n\t\t\t��� �߱� �Ͻðڽ��ϱ�? : "); 
scanf("%d",&contiChoice);

	if (contiChoice == 2){
		printf("\n========================================= �߱�  ���� =======================================\n");
		printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","�̿�� ����","�̿� �ð�","�߱� ����","��� ����","����","����� �Ѿ�");
		printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","(����/��ũ)","(1Day/After4)"," (��) ","(1-6)","(��) ","(��)");
		printf("\n============================================================================================\n");
		break;
	}
	else {
		row++;
	}

} //�ݺ� �Է� ������ ���� ���� 
	
	for (int i=0;i<=row;i++){	
		for (int j=0;j<6;j++){
			printf("%10d\t",reportArray[i][j]);
		}
		printf("\n");
	}

int sumIncome = 0;
int sumPeople = 0;
	
	for (int i=0;i<=row;i++){
		sumPeople += reportArray[i][2];
		sumIncome += reportArray[i][5];
	}
	
printf("\n========================================== 1�� �� ���� �ο�: %d �� / �� ���� : %d �� =====\n",sumPeople,sumIncome);
printf("\n\t\t\t�̿����ּż� �����մϴ�!\n");
printf("\n=============================================================================================\n");
return 0;
}
