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

printf("�̿���� ������ �����ϼ���.\n");
printf("1.���� �̿��\n");
printf("2.��ũ �̿��\n");
scanf("%d",&ticketAuth);

printf("\n������ �����ϼ���.\n\n");
printf("1.�ְ���\n");
printf("2.�߰���\n");
scanf("%d",&ticketTime);

printf("\n��ĵ ���� �ֹε�Ϲ�ȣ�� �Է��ϼ���.\n");
scanf("%d",&idNumber);

printf("\n�߱���  �� ���� �Է��ϼ���\n");
scanf("%d ��",&ticketQuan);

printf("\n�������� �����ϼ���.\n");
printf("1. ����(��� ���� �ڵ�ó��)\n");
printf("2. �����\n");
printf("3. ����������\n");
printf("4. �ް� �庴\n");
printf("5. �ӻ��\n");
printf("6. �ٵ��� �ູī��\n");
scanf("%d",&discountType);
 
printf("\n�� %d �� �߱�, ������ %d �� �Դϴ�\n",ticketQuan,totalPrice);

}
